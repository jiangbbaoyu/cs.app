# void store_prod(int128_t* dest, int64_t x, int64_t y)
# dest in %rdi, x in %rsi, y in %rdx

store_prod
	movq	%rdx, %rax		# save y in %rax
	cqto					# extend %rax to %rdx:%rax signally
	movq	%rsi, %rcx		# save x in %rcx
	sarq	$63, %rcx		# shift %rcx right arithmetically 63 position, %rcx filled with all ones if x is negative otherwise all zeros
	#下面把这两个扩展的数当成无符号数进行运算，取低128bit。
	# now y are represent as 128bits using %rdx:%rax (y = rdx*2^64 + rax)
	#     x are represent as 128bits using %rcx:%rsi (x = rcx*2^64 + rsi)
	# x*y = rdx*rcx*2^128 + rdx*rsi*2^64 + rcx*rax*2^64 + rax*rsi
	#由于我们只需要取低128位，所以对x*y进行取模操作mod 128，(rdx*rcx*2^128 >= 2^128) mod128 is zero
	# 得到：rdx*rsi*2^64mod2^128 + rcx*rax*2^64mod2^128 + rax*rsi
	# 对于rdx*rsi*2^64mod2^128,
	#   the higher 64bits of rdx*rsi  multiply 2^64 will be >= 2^128, so ignore
	#   the lower 64bits of rdx*rsi  multiply 2^64  will be < 2^128 and >= 2^64, so we need store the lower 64bits of rdx*rsi and interpret it as the result's higher 64 bits
	imulq	%rax, %rcx		#rcx*rax(store the lower 64bits of rdx*rsi in %rcx)
	imulq	%rsi, %rdx		#rdx*rsi(store the lower 64bits of rdx*rsi in %rdx)
	addq	%rdx, %rcx		# add two part of the higher 64bits of the result together ,and store in %rcx
	mulq	%rsi			# rax*rsi, store the result in %rdx:%rax
	addq	%rcx, %rdx		#add two part of the higher 64bits of the result together ,and store in %rdx
	movq	%rax, (%rdi)	#存储低64位
	movq	%rdx, 8(%rdi)	#存储高64位
	ret