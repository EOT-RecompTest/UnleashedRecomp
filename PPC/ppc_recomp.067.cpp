#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8238A960"))) PPC_WEAK_FUNC(sub_8238A960);
PPC_FUNC_IMPL(__imp__sub_8238A960) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,5208(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5208);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhz r9,4988(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4988);
	// addi r7,r3,5132
	ctx.r7.s64 = ctx.r3.s64 + 5132;
	// lhz r5,4990(r3)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4990);
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,5212(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5212);
	// addi r6,r3,4976
	ctx.r6.s64 = ctx.r3.s64 + 4976;
	// extsh r3,r9
	ctx.r3.s64 = ctx.r9.s16;
	// extsh r9,r5
	ctx.r9.s64 = ctx.r5.s16;
	// lwz r4,4632(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4632);
	// rlwinm r5,r8,1,0,30
	ctx.r5.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r10,r3,r8
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// mullw r8,r9,r5
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r5.s32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r8,r9
	ctx.r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8238a618
	ctx.lr = 0x8238A9D0;
	sub_8238A618(ctx, base);
	// addi r4,r31,4640
	ctx.r4.s64 = ctx.r31.s64 + 4640;
	// lwz r5,5208(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5208);
	// lis r10,-32198
	ctx.r10.s64 = -2110128128;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// lwz r8,5040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5040);
	// rlwinm r7,r5,3,0,28
	ctx.r7.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r10,-22128
	ctx.r9.s64 = ctx.r10.s64 + -22128;
	// addi r3,r31,4624
	ctx.r3.s64 = ctx.r31.s64 + 4624;
	// addi r6,r9,4
	ctx.r6.s64 = ctx.r9.s64 + 4;
	// lhz r11,5052(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 5052);
	// lwz r10,5212(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// extsh r5,r11
	ctx.r5.s64 = ctx.r11.s16;
	// lhz r30,5054(r31)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r31.u32 + 5054);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r11,r5,r7
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r7.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// extsh r5,r30
	ctx.r5.s64 = ctx.r30.s16;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r30,r7,1,0,30
	ctx.r30.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,4644(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4644, ctx.r8.u32);
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,5044(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5044);
	// mullw r10,r5,r30
	ctx.r10.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r30.s32);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r5,4652(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4652, ctx.r5.u32);
	// lwz r11,5048(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5048);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r7,r11,8
	ctx.r7.s64 = ctx.r11.s64 + 8;
	// stw r11,4660(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4660, ctx.r11.u32);
	// srawi r5,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 4;
	// stw r7,4668(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4668, ctx.r7.u32);
	// rotlwi r10,r11,0
	ctx.r10.u64 = rotl32(ctx.r11.u32, 0);
	// lhz r11,5054(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 5054);
	// extsh r8,r11
	ctx.r8.s64 = ctx.r11.s16;
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r7,r5,3,25,28
	ctx.r7.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0x78;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r5,r11,8
	ctx.r5.s64 = ctx.r11.s64 + 8;
	// stw r11,4676(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4676, ctx.r11.u32);
	// stw r5,4684(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4684, ctx.r5.u32);
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lwz r5,5224(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5224);
	// lwzx r11,r7,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238AA88;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238AAA0"))) PPC_WEAK_FUNC(sub_8238AAA0);
PPC_FUNC_IMPL(__imp__sub_8238AAA0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,5208(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5208);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhz r9,5004(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5004);
	// addi r7,r3,5168
	ctx.r7.s64 = ctx.r3.s64 + 5168;
	// lhz r5,5006(r3)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5006);
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,5212(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5212);
	// addi r6,r3,4992
	ctx.r6.s64 = ctx.r3.s64 + 4992;
	// extsh r3,r9
	ctx.r3.s64 = ctx.r9.s16;
	// extsh r9,r5
	ctx.r9.s64 = ctx.r5.s16;
	// lwz r4,4632(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4632);
	// rlwinm r5,r8,1,0,30
	ctx.r5.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r10,r3,r8
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// mullw r8,r9,r5
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r5.s32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r8,r9
	ctx.r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8238a618
	ctx.lr = 0x8238AB10;
	sub_8238A618(ctx, base);
	// addi r4,r31,4640
	ctx.r4.s64 = ctx.r31.s64 + 4640;
	// lwz r5,5208(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5208);
	// lis r10,-32198
	ctx.r10.s64 = -2110128128;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// lwz r8,5040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5040);
	// rlwinm r7,r5,3,0,28
	ctx.r7.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r10,-22128
	ctx.r9.s64 = ctx.r10.s64 + -22128;
	// addi r3,r31,4624
	ctx.r3.s64 = ctx.r31.s64 + 4624;
	// addi r6,r9,4
	ctx.r6.s64 = ctx.r9.s64 + 4;
	// lhz r11,5052(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 5052);
	// lwz r10,5212(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// extsh r5,r11
	ctx.r5.s64 = ctx.r11.s16;
	// lhz r30,5054(r31)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r31.u32 + 5054);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r11,r5,r7
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r7.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// extsh r5,r30
	ctx.r5.s64 = ctx.r30.s16;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r30,r7,1,0,30
	ctx.r30.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,4644(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4644, ctx.r8.u32);
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,5044(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5044);
	// mullw r10,r5,r30
	ctx.r10.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r30.s32);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r5,4652(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4652, ctx.r5.u32);
	// lwz r11,5048(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5048);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r7,r11,8
	ctx.r7.s64 = ctx.r11.s64 + 8;
	// stw r11,4660(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4660, ctx.r11.u32);
	// srawi r5,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 4;
	// stw r7,4668(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4668, ctx.r7.u32);
	// rotlwi r10,r11,0
	ctx.r10.u64 = rotl32(ctx.r11.u32, 0);
	// lhz r11,5054(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 5054);
	// extsh r8,r11
	ctx.r8.s64 = ctx.r11.s16;
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r7,r5,3,25,28
	ctx.r7.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0x78;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r5,r11,8
	ctx.r5.s64 = ctx.r11.s64 + 8;
	// stw r11,4676(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4676, ctx.r11.u32);
	// stw r5,4684(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4684, ctx.r5.u32);
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lwz r5,5224(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5224);
	// lwzx r11,r7,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238ABC8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238ABE0"))) PPC_WEAK_FUNC(sub_8238ABE0);
PPC_FUNC_IMPL(__imp__sub_8238ABE0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,5208(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5208);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lhz r9,4988(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4988);
	// addi r7,r3,5132
	ctx.r7.s64 = ctx.r3.s64 + 5132;
	// lhz r5,4990(r3)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r3.u32 + 4990);
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r10,5212(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5212);
	// addi r6,r3,4976
	ctx.r6.s64 = ctx.r3.s64 + 4976;
	// extsh r3,r9
	ctx.r3.s64 = ctx.r9.s16;
	// extsh r9,r5
	ctx.r9.s64 = ctx.r5.s16;
	// lwz r4,4632(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4632);
	// rlwinm r5,r8,1,0,30
	ctx.r5.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r10,r3,r8
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// mullw r8,r9,r5
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r5.s32);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r8,r9
	ctx.r11.u64 = ctx.r8.u64 + ctx.r9.u64;
	// stw r3,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8238a618
	ctx.lr = 0x8238AC50;
	sub_8238A618(ctx, base);
	// addi r7,r31,5168
	ctx.r7.s64 = ctx.r31.s64 + 5168;
	// addi r6,r31,4992
	ctx.r6.s64 = ctx.r31.s64 + 4992;
	// lwz r4,4636(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4636);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8238a618
	ctx.lr = 0x8238AC68;
	sub_8238A618(ctx, base);
	// addi r4,r31,4640
	ctx.r4.s64 = ctx.r31.s64 + 4640;
	// lwz r5,5208(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5208);
	// lis r10,-32198
	ctx.r10.s64 = -2110128128;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// lwz r8,5040(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5040);
	// rlwinm r7,r5,3,0,28
	ctx.r7.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r10,-22000
	ctx.r9.s64 = ctx.r10.s64 + -22000;
	// addi r3,r31,4624
	ctx.r3.s64 = ctx.r31.s64 + 4624;
	// addi r6,r9,4
	ctx.r6.s64 = ctx.r9.s64 + 4;
	// lhz r11,5052(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 5052);
	// lwz r10,5212(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// extsh r5,r11
	ctx.r5.s64 = ctx.r11.s16;
	// lhz r30,5054(r31)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r31.u32 + 5054);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r11,r5,r7
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r7.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// extsh r5,r30
	ctx.r5.s64 = ctx.r30.s16;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// rlwinm r30,r7,1,0,30
	ctx.r30.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,4644(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4644, ctx.r8.u32);
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,5044(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5044);
	// mullw r10,r5,r30
	ctx.r10.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r30.s32);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 + ctx.r7.u64;
	// stw r5,4652(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4652, ctx.r5.u32);
	// lwz r11,5048(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5048);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r7,r11,8
	ctx.r7.s64 = ctx.r11.s64 + 8;
	// stw r11,4660(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4660, ctx.r11.u32);
	// srawi r5,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 4;
	// stw r7,4668(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4668, ctx.r7.u32);
	// rotlwi r10,r11,0
	ctx.r10.u64 = rotl32(ctx.r11.u32, 0);
	// lhz r11,5054(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 5054);
	// extsh r8,r11
	ctx.r8.s64 = ctx.r11.s16;
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r7,r5,3,25,28
	ctx.r7.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0x78;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r5,r11,8
	ctx.r5.s64 = ctx.r11.s64 + 8;
	// stw r11,4676(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4676, ctx.r11.u32);
	// stw r5,4684(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4684, ctx.r5.u32);
	// lwzx r6,r7,r6
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r6.u32);
	// lwz r5,5224(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5224);
	// lwzx r11,r7,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r9.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238AD20;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238AD38"))) PPC_WEAK_FUNC(sub_8238AD38);
PPC_FUNC_IMPL(__imp__sub_8238AD38) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e45c
	ctx.lr = 0x8238AD40;
	__restfpr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r28,44(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r27,16(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 16);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r29,48(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r25,0
	ctx.r25.s64 = 0;
	// li r30,6
	ctx.r30.s64 = 6;
loc_8238AD60:
	// lbz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r26.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8238ad84
	if (!ctx.cr6.eq) goto loc_8238AD84;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r4,0(r29)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238AD80;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8238ad88
	goto loc_8238AD88;
loc_8238AD84:
	// or r25,r27,r25
	ctx.r25.u64 = ctx.r27.u64 | ctx.r25.u64;
loc_8238AD88:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// add r28,r28,r11
	ctx.r28.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// rlwinm r27,r27,31,1,31
	ctx.r27.u64 = rotl64(ctx.r27.u32 | (ctx.r27.u64 << 32), 31) & 0x7FFFFFFF;
	// bne 0x8238ad60
	if (!ctx.cr0.eq) goto loc_8238AD60;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x8238adc8
	if (ctx.cr6.eq) goto loc_8238ADC8;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r25,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r25.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8238ADC8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8238ADC8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8233e4ac
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238ADD0"))) PPC_WEAK_FUNC(sub_8238ADD0);
PPC_FUNC_IMPL(__imp__sub_8238ADD0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e45c
	ctx.lr = 0x8238ADD8;
	__restfpr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,44(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r27,20(r3)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r3.u32 + 20);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r28,48(r3)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r3.u32 + 48);
	// li r30,6
	ctx.r30.s64 = 6;
	// lwz r26,40(r3)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
loc_8238ADF8:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bge cr6,0x8238ae2c
	if (!ctx.cr6.lt) goto loc_8238AE2C;
	// lbz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r25.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8238ae2c
	if (!ctx.cr6.eq) goto loc_8238AE2C;
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238AE20;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,40(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// and r9,r10,r27
	ctx.r9.u64 = ctx.r10.u64 & ctx.r27.u64;
	// stw r9,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r9.u32);
loc_8238AE2C:
	// lwz r11,36(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 36);
	// rlwinm r10,r27,31,1,31
	ctx.r10.u64 = rotl64(ctx.r27.u32 | (ctx.r27.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// rlwinm r26,r26,1,0,30
	ctx.r26.u64 = rotl64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// or r27,r10,r9
	ctx.r27.u64 = ctx.r10.u64 | ctx.r9.u64;
	// bne 0x8238adf8
	if (!ctx.cr0.eq) goto loc_8238ADF8;
	// lwz r11,40(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8238ae78
	if (ctx.cr6.eq) goto loc_8238AE78;
	// lwz r11,48(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,12(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// stw r11,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8238AE78;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8238AE78:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8233e4ac
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238AE80"))) PPC_WEAK_FUNC(sub_8238AE80);
PPC_FUNC_IMPL(__imp__sub_8238AE80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f13,f0
	ctx.f13.u64 = uint64_t(int32_t(std::trunc(ctx.f0.f64)));
	// stfd f13,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f13.u64);
	// lhz r11,-10(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + -10);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x8238aeb4
	if (!ctx.cr6.lt) goto loc_8238AEB4;
	// subfic r11,r11,4
	ctx.xer.ca = ctx.r11.u32 <= 4;
	ctx.r11.s64 = 4 - ctx.r11.s64;
	// rlwinm r10,r11,29,3,31
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// neg r9,r10
	ctx.r9.s64 = -ctx.r10.s64;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// rlwimi r11,r9,16,0,15
	ctx.r11.u64 = (rotl32(ctx.r9.u32, 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// b 0x8238aec4
	goto loc_8238AEC4;
loc_8238AEB4:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// rlwinm r10,r11,29,3,31
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// rlwinm r9,r10,16,0,15
	ctx.r9.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// or r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 | ctx.r10.u64;
loc_8238AEC4:
	// clrldi r10,r11,32
	ctx.r10.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// rldicr r9,r11,32,31
	ctx.r9.u64 = rotl64(ctx.r11.u64, 32) & 0xFFFFFFFF00000000;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// std r8,0(r4)
	PPC_STORE_U64(ctx.r4.u32 + 0, ctx.r8.u64);
	// std r8,8(r4)
	PPC_STORE_U64(ctx.r4.u32 + 8, ctx.r8.u64);
	// std r8,16(r4)
	PPC_STORE_U64(ctx.r4.u32 + 16, ctx.r8.u64);
	// std r8,24(r4)
	PPC_STORE_U64(ctx.r4.u32 + 24, ctx.r8.u64);
	// std r8,32(r4)
	PPC_STORE_U64(ctx.r4.u32 + 32, ctx.r8.u64);
	// std r8,40(r4)
	PPC_STORE_U64(ctx.r4.u32 + 40, ctx.r8.u64);
	// std r8,48(r4)
	PPC_STORE_U64(ctx.r4.u32 + 48, ctx.r8.u64);
	// std r8,56(r4)
	PPC_STORE_U64(ctx.r4.u32 + 56, ctx.r8.u64);
	// std r8,64(r4)
	PPC_STORE_U64(ctx.r4.u32 + 64, ctx.r8.u64);
	// std r8,72(r4)
	PPC_STORE_U64(ctx.r4.u32 + 72, ctx.r8.u64);
	// std r8,80(r4)
	PPC_STORE_U64(ctx.r4.u32 + 80, ctx.r8.u64);
	// std r8,88(r4)
	PPC_STORE_U64(ctx.r4.u32 + 88, ctx.r8.u64);
	// std r8,96(r4)
	PPC_STORE_U64(ctx.r4.u32 + 96, ctx.r8.u64);
	// std r8,104(r4)
	PPC_STORE_U64(ctx.r4.u32 + 104, ctx.r8.u64);
	// std r8,112(r4)
	PPC_STORE_U64(ctx.r4.u32 + 112, ctx.r8.u64);
	// std r8,120(r4)
	PPC_STORE_U64(ctx.r4.u32 + 120, ctx.r8.u64);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238AF14"))) PPC_WEAK_FUNC(sub_8238AF14);
PPC_FUNC_IMPL(__imp__sub_8238AF14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238AF18"))) PPC_WEAK_FUNC(sub_8238AF18);
PPC_FUNC_IMPL(__imp__sub_8238AF18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e450
	ctx.lr = 0x8238AF20;
	__restfpr_22(ctx, base);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lwz r6,64(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 64);
	// lwz r5,68(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 68);
	// li r8,16
	ctx.r8.s64 = 16;
	// addi r4,r11,-48
	ctx.r4.s64 = ctx.r11.s64 + -48;
	// lwz r11,44(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 44);
	// li r9,32
	ctx.r9.s64 = 32;
	// lwz r23,40(r3)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 40);
	// li r10,48
	ctx.r10.s64 = 48;
	// lwz r3,52(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 52);
	// li r7,6
	ctx.r7.s64 = 6;
	// lvlx128 v63,r0,r6
	temp.u32 = ctx.r0.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v63,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// li r31,-32
	ctx.r31.s64 = -32;
	// lvlx128 v62,r0,r5
	temp.u32 = ctx.r0.u32 + ctx.r5.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// li r30,-16
	ctx.r30.s64 = -16;
	// lvlx v0,r8,r6
	temp.u32 = ctx.r8.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v0,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v13,r9,r6
	temp.u32 = ctx.r9.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v13,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// li r24,128
	ctx.r24.s64 = 128;
	// lvlx v12,r10,r6
	temp.u32 = ctx.r10.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v12,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// li r6,96
	ctx.r6.s64 = 96;
	// lvlx v11,r8,r5
	temp.u32 = ctx.r8.u32 + ctx.r5.u32;
	simd::store_shuffled(ctx.v11,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// lvlx v6,r4,r31
	temp.u32 = ctx.r4.u32 + ctx.r31.u32;
	simd::store_shuffled(ctx.v6,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// li r7,112
	ctx.r7.s64 = 112;
	// lvlx v5,r4,r30
	temp.u32 = ctx.r4.u32 + ctx.r30.u32;
	simd::store_shuffled(ctx.v5,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// li r25,144
	ctx.r25.s64 = 144;
	// lvlx v10,r9,r5
	temp.u32 = ctx.r9.u32 + ctx.r5.u32;
	simd::store_shuffled(ctx.v10,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// li r26,160
	ctx.r26.s64 = 160;
	// lvlx v9,r10,r5
	temp.u32 = ctx.r10.u32 + ctx.r5.u32;
	simd::store_shuffled(ctx.v9,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// li r5,80
	ctx.r5.s64 = 80;
	// lvlx v7,0,r4
	temp.u32 = ctx.r0.u32 + ctx.r4.u32;
	simd::store_shuffled(ctx.v7,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// li r4,64
	ctx.r4.s64 = 64;
	// li r27,176
	ctx.r27.s64 = 176;
	// li r28,192
	ctx.r28.s64 = 192;
	// li r29,208
	ctx.r29.s64 = 208;
	// li r30,224
	ctx.r30.s64 = 224;
	// li r31,240
	ctx.r31.s64 = 240;
loc_8238AFB4:
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// bge cr6,0x8238b5d0
	if (!ctx.cr6.lt) goto loc_8238B5D0;
	// lvlx128 v61,r0,r11
	temp.u32 = ctx.r0.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v61,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lwz r22,0(r3)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lvlx128 v60,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v59,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v59,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vspltw128 v58,v61,0
	simd::store_i32(ctx.v58.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v61.u32), 3));
	// lvlx128 v57,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vspltw128 v56,v60,0
	simd::store_i32(ctx.v56.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v60.u32), 3));
	// lvlx128 v55,r4,r11
	temp.u32 = ctx.r4.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v55,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vspltw128 v54,v59,0
	simd::store_i32(ctx.v54.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v59.u32), 3));
	// lvlx128 v53,r5,r11
	temp.u32 = ctx.r5.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v53,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vspltw128 v52,v57,0
	simd::store_i32(ctx.v52.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v57.u32), 3));
	// lvlx128 v51,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v51,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vspltw128 v50,v55,0
	simd::store_i32(ctx.v50.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v55.u32), 3));
	// vspltw128 v49,v53,0
	simd::store_i32(ctx.v49.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v53.u32), 3));
	// vmulfp128 v4,v58,v63
	ctx.fpscr.enableFlushMode();
	simd::store_f32_aligned(ctx.v4.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v58.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vspltw128 v48,v51,0
	simd::store_i32(ctx.v48.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v51.u32), 3));
	// vmulfp128 v2,v56,v63
	simd::store_f32_aligned(ctx.v2.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v56.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vmulfp128 v31,v54,v63
	simd::store_f32_aligned(ctx.v31.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v54.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vspltw128 v8,v61,1
	simd::store_i32(ctx.v8.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v61.u32), 2));
	// vmulfp128 v29,v52,v63
	simd::store_f32_aligned(ctx.v29.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v52.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vspltw128 v3,v60,1
	simd::store_i32(ctx.v3.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v60.u32), 2));
	// vmulfp128 v27,v50,v63
	simd::store_f32_aligned(ctx.v27.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v50.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vspltw128 v1,v59,1
	simd::store_i32(ctx.v1.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v59.u32), 2));
	// vmulfp128 v25,v49,v63
	simd::store_f32_aligned(ctx.v25.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v49.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vspltw128 v30,v57,1
	simd::store_i32(ctx.v30.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v57.u32), 2));
	// vmulfp128 v23,v48,v63
	simd::store_f32_aligned(ctx.v23.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v48.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vspltw128 v28,v55,1
	simd::store_i32(ctx.v28.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v55.u32), 2));
	// vspltw128 v26,v53,1
	simd::store_i32(ctx.v26.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v53.u32), 2));
	// lvlx128 v47,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v47,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vspltw128 v24,v51,1
	simd::store_i32(ctx.v24.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v51.u32), 2));
	// lvlx128 v46,r24,r11
	temp.u32 = ctx.r24.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v46,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vspltw128 v22,v61,2
	simd::store_i32(ctx.v22.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v61.u32), 1));
	// lvlx128 v45,r25,r11
	temp.u32 = ctx.r25.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v45,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vspltw128 v21,v60,2
	simd::store_i32(ctx.v21.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v60.u32), 1));
	// lvlx128 v44,r26,r11
	temp.u32 = ctx.r26.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v44,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vspltw128 v20,v59,2
	simd::store_i32(ctx.v20.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v59.u32), 1));
	// lvlx128 v35,r27,r11
	temp.u32 = ctx.r27.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v35,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmaddfp v8,v8,v0,v4
	simd::store_f32_aligned(ctx.v8.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v8.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v4.f32)));
	// vspltw128 v17,v53,2
	simd::store_i32(ctx.v17.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v53.u32), 1));
	// vmaddfp v4,v3,v0,v2
	simd::store_f32_aligned(ctx.v4.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v3.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v2.f32)));
	// vspltw128 v19,v57,2
	simd::store_i32(ctx.v19.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v57.u32), 1));
	// vmaddfp v3,v1,v0,v31
	simd::store_f32_aligned(ctx.v3.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v1.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v31.f32)));
	// vspltw128 v18,v55,2
	simd::store_i32(ctx.v18.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v55.u32), 1));
	// vmaddfp v2,v30,v0,v29
	simd::store_f32_aligned(ctx.v2.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v30.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v29.f32)));
	// vspltw128 v16,v51,2
	simd::store_i32(ctx.v16.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v51.u32), 1));
	// vmaddfp v1,v28,v0,v27
	simd::store_f32_aligned(ctx.v1.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v28.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v27.f32)));
	// vspltw128 v29,v61,3
	simd::store_i32(ctx.v29.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v61.u32), 0));
	// vmaddfp v31,v26,v0,v25
	simd::store_f32_aligned(ctx.v31.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v26.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v25.f32)));
	// vspltw128 v28,v60,3
	simd::store_i32(ctx.v28.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v60.u32), 0));
	// vmaddfp v30,v24,v0,v23
	simd::store_f32_aligned(ctx.v30.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v24.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v23.f32)));
	// vspltw128 v27,v59,3
	simd::store_i32(ctx.v27.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v59.u32), 0));
	// vspltw128 v26,v57,3
	simd::store_i32(ctx.v26.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v57.u32), 0));
	// vspltw128 v25,v55,3
	simd::store_i32(ctx.v25.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v55.u32), 0));
	// vspltw128 v24,v53,3
	simd::store_i32(ctx.v24.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v53.u32), 0));
	// vspltw128 v23,v51,3
	simd::store_i32(ctx.v23.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v51.u32), 0));
	// vspltw128 v43,v47,0
	simd::store_i32(ctx.v43.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v47.u32), 3));
	// vmaddfp v8,v22,v13,v8
	simd::store_f32_aligned(ctx.v8.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v22.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v8.f32)));
	// vmaddfp v4,v21,v13,v4
	simd::store_f32_aligned(ctx.v4.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v21.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v4.f32)));
	// vmaddfp v3,v20,v13,v3
	simd::store_f32_aligned(ctx.v3.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v20.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v3.f32)));
	// vmaddfp v2,v19,v13,v2
	simd::store_f32_aligned(ctx.v2.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v19.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v2.f32)));
	// vmaddfp v1,v18,v13,v1
	simd::store_f32_aligned(ctx.v1.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v18.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v1.f32)));
	// vmaddfp v31,v17,v13,v31
	simd::store_f32_aligned(ctx.v31.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v17.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v31.f32)));
	// vspltw128 v17,v47,2
	simd::store_i32(ctx.v17.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v47.u32), 1));
	// vmaddfp v30,v16,v13,v30
	simd::store_f32_aligned(ctx.v30.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v16.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v30.f32)));
	// vmaddfp v8,v29,v12,v8
	simd::store_f32_aligned(ctx.v8.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v29.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v8.f32)));
	// vmaddfp v4,v28,v12,v4
	simd::store_f32_aligned(ctx.v4.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v28.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v4.f32)));
	// vmaddfp v3,v27,v12,v3
	simd::store_f32_aligned(ctx.v3.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v27.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v3.f32)));
	// vmaddfp v2,v26,v12,v2
	simd::store_f32_aligned(ctx.v2.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v26.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v2.f32)));
	// vmaddfp v1,v25,v12,v1
	simd::store_f32_aligned(ctx.v1.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v25.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v1.f32)));
	// vmaddfp v31,v24,v12,v31
	simd::store_f32_aligned(ctx.v31.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v24.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v31.f32)));
	// vmaddfp v30,v23,v12,v30
	simd::store_f32_aligned(ctx.v30.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v23.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v30.f32)));
	// vor128 v42,v8,v8
	simd::store_i8(ctx.v42.u8, simd::load_i8(ctx.v8.u8));
	// vspltw128 v8,v47,1
	simd::store_i32(ctx.v8.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v47.u32), 2));
	// vor128 v41,v4,v4
	simd::store_i8(ctx.v41.u8, simd::load_i8(ctx.v4.u8));
	// vspltw128 v4,v47,3
	simd::store_i32(ctx.v4.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v47.u32), 0));
	// vor128 v40,v3,v3
	simd::store_i8(ctx.v40.u8, simd::load_i8(ctx.v3.u8));
	// vmulfp128 v3,v43,v63
	simd::store_f32_aligned(ctx.v3.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v43.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vor128 v39,v2,v2
	simd::store_i8(ctx.v39.u8, simd::load_i8(ctx.v2.u8));
	// vor128 v38,v1,v1
	simd::store_i8(ctx.v38.u8, simd::load_i8(ctx.v1.u8));
	// vor128 v37,v31,v31
	simd::store_i8(ctx.v37.u8, simd::load_i8(ctx.v31.u8));
	// vor128 v36,v30,v30
	simd::store_i8(ctx.v36.u8, simd::load_i8(ctx.v30.u8));
	// vspltw128 v34,v46,0
	simd::store_i32(ctx.v34.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v46.u32), 3));
	// lvlx128 v32,r28,r11
	temp.u32 = ctx.r28.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v32,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vspltw128 v33,v45,0
	simd::store_i32(ctx.v33.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v45.u32), 3));
	// lvlx128 v60,r29,r11
	temp.u32 = ctx.r29.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vspltw128 v61,v44,0
	simd::store_i32(ctx.v61.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v44.u32), 3));
	// vmaddfp v8,v8,v0,v3
	simd::store_f32_aligned(ctx.v8.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v8.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v3.f32)));
	// vspltw128 v59,v35,0
	simd::store_i32(ctx.v59.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v35.u32), 3));
	// lvlx128 v56,r30,r11
	temp.u32 = ctx.r30.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmulfp128 v1,v34,v62
	simd::store_f32_aligned(ctx.v1.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v34.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vspltw128 v58,v32,0
	simd::store_i32(ctx.v58.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v32.u32), 3));
	// vmulfp128 v30,v33,v62
	simd::store_f32_aligned(ctx.v30.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v33.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vspltw128 v57,v60,0
	simd::store_i32(ctx.v57.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v60.u32), 3));
	// vmulfp128 v23,v61,v62
	simd::store_f32_aligned(ctx.v23.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v61.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vspltw128 v2,v46,1
	simd::store_i32(ctx.v2.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v46.u32), 2));
	// vmulfp128 v21,v59,v62
	simd::store_f32_aligned(ctx.v21.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v59.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vspltw128 v31,v45,1
	simd::store_i32(ctx.v31.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v45.u32), 2));
	// vmulfp128 v19,v58,v62
	simd::store_f32_aligned(ctx.v19.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v58.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vspltw128 v29,v44,1
	simd::store_i32(ctx.v29.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v44.u32), 2));
	// vmulfp128 v18,v57,v62
	simd::store_f32_aligned(ctx.v18.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v57.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vspltw128 v22,v35,1
	simd::store_i32(ctx.v22.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v35.u32), 2));
	// vspltw128 v20,v32,1
	simd::store_i32(ctx.v20.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v32.u32), 2));
	// lvlx128 v55,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v55,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vspltw128 v3,v60,1
	simd::store_i32(ctx.v3.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v60.u32), 2));
	// vspltw128 v16,v46,2
	simd::store_i32(ctx.v16.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v46.u32), 1));
	// vspltw128 v15,v45,2
	simd::store_i32(ctx.v15.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v45.u32), 1));
	// vspltw128 v14,v44,2
	simd::store_i32(ctx.v14.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v44.u32), 1));
	// vspltw128 v26,v35,2
	simd::store_i32(ctx.v26.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v35.u32), 1));
	// vmaddfp v25,v2,v11,v1
	simd::store_f32_aligned(ctx.v25.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v2.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v1.f32)));
	// vspltw128 v27,v32,2
	simd::store_i32(ctx.v27.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v32.u32), 1));
	// vmaddfp v24,v31,v11,v30
	simd::store_f32_aligned(ctx.v24.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v31.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v30.f32)));
	// vspltw128 v28,v60,2
	simd::store_i32(ctx.v28.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v60.u32), 1));
	// vmaddfp v23,v29,v11,v23
	simd::store_f32_aligned(ctx.v23.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v29.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v23.f32)));
	// vspltw128 v29,v46,3
	simd::store_i32(ctx.v29.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v46.u32), 0));
	// vmaddfp v22,v22,v11,v21
	simd::store_f32_aligned(ctx.v22.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v22.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v21.f32)));
	// vspltw128 v30,v45,3
	simd::store_i32(ctx.v30.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v45.u32), 0));
	// vmaddfp v21,v20,v11,v19
	simd::store_f32_aligned(ctx.v21.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v20.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v19.f32)));
	// vspltw128 v31,v44,3
	simd::store_i32(ctx.v31.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v44.u32), 0));
	// vmaddfp v20,v3,v11,v18
	simd::store_f32_aligned(ctx.v20.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v3.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v18.f32)));
	// vspltw128 v1,v35,3
	simd::store_i32(ctx.v1.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v35.u32), 0));
	// vmaddfp v19,v17,v13,v8
	simd::store_f32_aligned(ctx.v19.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v17.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v8.f32)));
	// vspltw128 v8,v60,3
	simd::store_i32(ctx.v8.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v60.u32), 0));
	// vspltw128 v2,v32,3
	simd::store_i32(ctx.v2.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v32.u32), 0));
	// vspltw128 v54,v56,0
	simd::store_i32(ctx.v54.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v56.u32), 3));
	// vspltw128 v53,v55,0
	simd::store_i32(ctx.v53.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v55.u32), 3));
	// vspltw128 v3,v56,1
	simd::store_i32(ctx.v3.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v56.u32), 2));
	// vmaddfp v18,v16,v10,v25
	simd::store_f32_aligned(ctx.v18.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v16.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v25.f32)));
	// vmaddfp v17,v15,v10,v24
	simd::store_f32_aligned(ctx.v17.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v15.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v24.f32)));
	// vmaddfp v24,v14,v10,v23
	simd::store_f32_aligned(ctx.v24.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v14.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v23.f32)));
	// vmaddfp v25,v26,v10,v22
	simd::store_f32_aligned(ctx.v25.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v26.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v22.f32)));
	// vmaddfp v26,v27,v10,v21
	simd::store_f32_aligned(ctx.v26.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v27.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v21.f32)));
	// vmaddfp v27,v28,v10,v20
	simd::store_f32_aligned(ctx.v27.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v28.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v20.f32)));
	// vmaddfp v28,v4,v12,v19
	simd::store_f32_aligned(ctx.v28.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v4.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v19.f32)));
	// vmulfp128 v4,v54,v62
	simd::store_f32_aligned(ctx.v4.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v54.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vmaddfp v29,v29,v9,v18
	simd::store_f32_aligned(ctx.v29.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v29.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v18.f32)));
	// vmaddfp v30,v30,v9,v17
	simd::store_f32_aligned(ctx.v30.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v30.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v17.f32)));
	// vmaddfp v31,v31,v9,v24
	simd::store_f32_aligned(ctx.v31.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v31.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v24.f32)));
	// vmaddfp v1,v1,v9,v25
	simd::store_f32_aligned(ctx.v1.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v1.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v25.f32)));
	// vmaddfp v2,v2,v9,v26
	simd::store_f32_aligned(ctx.v2.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v2.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v26.f32)));
	// vspltw128 v26,v55,1
	simd::store_i32(ctx.v26.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v55.u32), 2));
	// vmaddfp v8,v8,v9,v27
	simd::store_f32_aligned(ctx.v8.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v8.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v27.f32)));
	// vmulfp128 v27,v53,v62
	simd::store_f32_aligned(ctx.v27.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v53.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vor128 v52,v28,v28
	simd::store_i8(ctx.v52.u8, simd::load_i8(ctx.v28.u8));
	// vspltw128 v28,v55,3
	simd::store_i32(ctx.v28.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v55.u32), 0));
	// vmaddfp v25,v3,v11,v4
	simd::store_f32_aligned(ctx.v25.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v3.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v4.f32)));
	// vaddfp128 v48,v42,v29
	simd::store_f32_aligned(ctx.v48.f32, simd::add_f32(simd::load_f32_aligned(ctx.v42.f32), simd::load_f32_aligned(ctx.v29.f32)));
	// vsubfp128 v46,v42,v29
	simd::store_f32_aligned(ctx.v46.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v42.f32), simd::load_f32_aligned(ctx.v29.f32)));
	// vor128 v51,v30,v30
	simd::store_i8(ctx.v51.u8, simd::load_i8(ctx.v30.u8));
	// vor128 v50,v31,v31
	simd::store_i8(ctx.v50.u8, simd::load_i8(ctx.v31.u8));
	// vspltw128 v30,v55,2
	simd::store_i32(ctx.v30.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v55.u32), 1));
	// vspltw128 v31,v56,2
	simd::store_i32(ctx.v31.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v56.u32), 1));
	// vor128 v49,v2,v2
	simd::store_i8(ctx.v49.u8, simd::load_i8(ctx.v2.u8));
	// vor128 v47,v8,v8
	simd::store_i8(ctx.v47.u8, simd::load_i8(ctx.v8.u8));
	// vaddfp128 v45,v41,v51
	simd::store_f32_aligned(ctx.v45.f32, simd::add_f32(simd::load_f32_aligned(ctx.v41.f32), simd::load_f32_aligned(ctx.v51.f32)));
	// vsubfp128 v44,v41,v51
	simd::store_f32_aligned(ctx.v44.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v41.f32), simd::load_f32_aligned(ctx.v51.f32)));
	// vspltw128 v8,v56,3
	simd::store_i32(ctx.v8.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v56.u32), 0));
	// vaddfp128 v43,v40,v50
	simd::store_f32_aligned(ctx.v43.f32, simd::add_f32(simd::load_f32_aligned(ctx.v40.f32), simd::load_f32_aligned(ctx.v50.f32)));
	// vsubfp128 v42,v40,v50
	simd::store_f32_aligned(ctx.v42.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v40.f32), simd::load_f32_aligned(ctx.v50.f32)));
	// vaddfp128 v41,v39,v1
	simd::store_f32_aligned(ctx.v41.f32, simd::add_f32(simd::load_f32_aligned(ctx.v39.f32), simd::load_f32_aligned(ctx.v1.f32)));
	// vmaddfp v14,v26,v11,v27
	simd::store_f32_aligned(ctx.v14.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v26.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v27.f32)));
	// vspltw128 v40,v48,0
	simd::store_i32(ctx.v40.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v48.u32), 3));
	// vspltw128 v35,v46,3
	simd::store_i32(ctx.v35.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v46.u32), 0));
	// vspltw128 v34,v48,1
	simd::store_i32(ctx.v34.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v48.u32), 2));
	// vsubfp128 v33,v39,v1
	simd::store_f32_aligned(ctx.v33.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v39.f32), simd::load_f32_aligned(ctx.v1.f32)));
	// vspltw128 v32,v46,2
	simd::store_i32(ctx.v32.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v46.u32), 1));
	// vmulfp128 v1,v40,v63
	simd::store_f32_aligned(ctx.v1.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v40.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vspltw128 v60,v48,2
	simd::store_i32(ctx.v60.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v48.u32), 1));
	// vmulfp128 v2,v35,v63
	simd::store_f32_aligned(ctx.v2.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v35.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vspltw128 v18,v45,0
	simd::store_i32(ctx.v18.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v45.u32), 3));
	// vmaddfp v15,v31,v10,v25
	simd::store_f32_aligned(ctx.v15.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v31.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v25.f32)));
	// vmulfp128 v3,v34,v63
	simd::store_f32_aligned(ctx.v3.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v34.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vspltw128 v19,v44,3
	simd::store_i32(ctx.v19.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v44.u32), 0));
	// vmulfp128 v4,v32,v63
	simd::store_f32_aligned(ctx.v4.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v32.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vspltw128 v20,v45,1
	simd::store_i32(ctx.v20.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v45.u32), 2));
	// vmulfp128 v29,v60,v63
	simd::store_f32_aligned(ctx.v29.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v60.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vspltw128 v21,v44,2
	simd::store_i32(ctx.v21.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v44.u32), 1));
	// vspltw128 v22,v45,2
	simd::store_i32(ctx.v22.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v45.u32), 1));
	// vaddfp128 v61,v38,v49
	simd::store_f32_aligned(ctx.v61.f32, simd::add_f32(simd::load_f32_aligned(ctx.v38.f32), simd::load_f32_aligned(ctx.v49.f32)));
	// vspltw128 v56,v46,1
	simd::store_i32(ctx.v56.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v46.u32), 2));
	// vsubfp128 v59,v38,v49
	simd::store_f32_aligned(ctx.v59.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v38.f32), simd::load_f32_aligned(ctx.v49.f32)));
	// vspltw128 v23,v43,0
	simd::store_i32(ctx.v23.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v43.u32), 3));
	// vaddfp128 v58,v37,v47
	simd::store_f32_aligned(ctx.v58.f32, simd::add_f32(simd::load_f32_aligned(ctx.v37.f32), simd::load_f32_aligned(ctx.v47.f32)));
	// vspltw128 v24,v42,3
	simd::store_i32(ctx.v24.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v42.u32), 0));
	// vsubfp128 v57,v37,v47
	simd::store_f32_aligned(ctx.v57.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v37.f32), simd::load_f32_aligned(ctx.v47.f32)));
	// vspltw128 v25,v43,1
	simd::store_i32(ctx.v25.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v43.u32), 2));
	// vspltw128 v26,v42,2
	simd::store_i32(ctx.v26.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v42.u32), 1));
	// vmaddfp v16,v18,v0,v1
	simd::store_f32_aligned(ctx.v16.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v18.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v1.f32)));
	// vspltw128 v27,v43,2
	simd::store_i32(ctx.v27.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v43.u32), 1));
	// vmaddfp v17,v19,v0,v2
	simd::store_f32_aligned(ctx.v17.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v19.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v2.f32)));
	// vspltw128 v31,v41,0
	simd::store_i32(ctx.v31.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v41.u32), 3));
	// vspltw128 v1,v33,3
	simd::store_i32(ctx.v1.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v33.u32), 0));
	// vmaddfp v18,v20,v0,v3
	simd::store_f32_aligned(ctx.v18.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v20.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v3.f32)));
	// vspltw128 v2,v41,1
	simd::store_i32(ctx.v2.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v41.u32), 2));
	// vmaddfp v19,v21,v0,v4
	simd::store_f32_aligned(ctx.v19.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v21.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v4.f32)));
	// vspltw128 v3,v33,2
	simd::store_i32(ctx.v3.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v33.u32), 1));
	// vmaddfp v20,v22,v0,v29
	simd::store_f32_aligned(ctx.v20.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v22.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v29.f32)));
	// vspltw128 v29,v44,1
	simd::store_i32(ctx.v29.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v44.u32), 2));
	// vmaddfp v21,v30,v10,v14
	simd::store_f32_aligned(ctx.v21.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v30.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v14.f32)));
	// vspltw128 v4,v41,2
	simd::store_i32(ctx.v4.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v41.u32), 1));
	// vmulfp128 v30,v56,v63
	simd::store_f32_aligned(ctx.v30.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v56.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vspltw128 v55,v48,3
	simd::store_i32(ctx.v55.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v48.u32), 0));
	// vmaddfp v22,v8,v9,v15
	simd::store_f32_aligned(ctx.v22.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v8.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v15.f32)));
	// vspltw128 v8,v42,1
	simd::store_i32(ctx.v8.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v42.u32), 2));
	// vspltw128 v54,v46,0
	simd::store_i32(ctx.v54.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v46.u32), 3));
	// vspltw128 v53,v61,0
	simd::store_i32(ctx.v53.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v61.u32), 3));
	// vspltw128 v51,v59,3
	simd::store_i32(ctx.v51.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v59.u32), 0));
	// vmaddfp v23,v23,v13,v16
	simd::store_f32_aligned(ctx.v23.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v23.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v16.f32)));
	// vspltw128 v50,v61,1
	simd::store_i32(ctx.v50.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v61.u32), 2));
	// vmaddfp v24,v24,v13,v17
	simd::store_f32_aligned(ctx.v24.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v24.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v17.f32)));
	// vspltw128 v49,v59,2
	simd::store_i32(ctx.v49.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v59.u32), 1));
	// vspltw128 v48,v61,2
	simd::store_i32(ctx.v48.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v61.u32), 1));
	// vmaddfp v25,v25,v13,v18
	simd::store_f32_aligned(ctx.v25.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v25.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v18.f32)));
	// vspltw128 v47,v59,1
	simd::store_i32(ctx.v47.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v59.u32), 2));
	// vmaddfp v26,v26,v13,v19
	simd::store_f32_aligned(ctx.v26.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v26.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v19.f32)));
	// vmaddfp v27,v27,v13,v20
	simd::store_f32_aligned(ctx.v27.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v27.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v20.f32)));
	// vmaddfp v28,v28,v9,v21
	simd::store_f32_aligned(ctx.v28.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v28.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v21.f32)));
	// vspltw128 v21,v45,3
	simd::store_i32(ctx.v21.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v45.u32), 0));
	// vmaddfp v30,v29,v0,v30
	simd::store_f32_aligned(ctx.v30.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v29.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v30.f32)));
	// vaddfp128 v46,v36,v22
	simd::store_f32_aligned(ctx.v46.f32, simd::add_f32(simd::load_f32_aligned(ctx.v36.f32), simd::load_f32_aligned(ctx.v22.f32)));
	// vsubfp128 v45,v36,v22
	simd::store_f32_aligned(ctx.v45.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v36.f32), simd::load_f32_aligned(ctx.v22.f32)));
	// vspltw128 v22,v44,0
	simd::store_i32(ctx.v22.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v44.u32), 3));
	// vmulfp128 v29,v55,v63
	simd::store_f32_aligned(ctx.v29.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v55.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vmaddfp v31,v31,v12,v23
	simd::store_f32_aligned(ctx.v31.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v31.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v23.f32)));
	// vspltw128 v23,v58,0
	simd::store_i32(ctx.v23.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v58.u32), 3));
	// vmaddfp v1,v1,v12,v24
	simd::store_f32_aligned(ctx.v1.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v1.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v24.f32)));
	// vmaddfp v2,v2,v12,v25
	simd::store_f32_aligned(ctx.v2.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v2.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v25.f32)));
	// vmaddfp v3,v3,v12,v26
	simd::store_f32_aligned(ctx.v3.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v3.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v26.f32)));
	// vmaddfp v4,v4,v12,v27
	simd::store_f32_aligned(ctx.v4.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v4.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v27.f32)));
	// vaddfp128 v40,v52,v28
	simd::store_f32_aligned(ctx.v40.f32, simd::add_f32(simd::load_f32_aligned(ctx.v52.f32), simd::load_f32_aligned(ctx.v28.f32)));
	// vmaddfp v16,v8,v13,v30
	simd::store_f32_aligned(ctx.v16.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v8.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v30.f32)));
	// vmulfp128 v30,v54,v63
	simd::store_f32_aligned(ctx.v30.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v54.f32), simd::load_f32_aligned(ctx.v63.f32)));
	// vsubfp128 v39,v52,v28
	simd::store_f32_aligned(ctx.v39.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v52.f32), simd::load_f32_aligned(ctx.v28.f32)));
	// vmulfp128 v27,v49,v62
	simd::store_f32_aligned(ctx.v27.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v49.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vmulfp128 v8,v47,v62
	simd::store_f32_aligned(ctx.v8.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v47.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vor128 v38,v31,v31
	simd::store_i8(ctx.v38.u8, simd::load_i8(ctx.v31.u8));
	// vmulfp128 v31,v53,v62
	simd::store_f32_aligned(ctx.v31.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v53.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vor128 v37,v1,v1
	simd::store_i8(ctx.v37.u8, simd::load_i8(ctx.v1.u8));
	// vmulfp128 v1,v51,v62
	simd::store_f32_aligned(ctx.v1.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v51.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vor128 v36,v2,v2
	simd::store_i8(ctx.v36.u8, simd::load_i8(ctx.v2.u8));
	// vmulfp128 v2,v50,v62
	simd::store_f32_aligned(ctx.v2.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v50.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vor128 v35,v3,v3
	simd::store_i8(ctx.v35.u8, simd::load_i8(ctx.v3.u8));
	// vmulfp128 v3,v48,v62
	simd::store_f32_aligned(ctx.v3.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v48.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vor128 v34,v4,v4
	simd::store_i8(ctx.v34.u8, simd::load_i8(ctx.v4.u8));
	// vspltw128 v24,v57,3
	simd::store_i32(ctx.v24.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v57.u32), 0));
	// vmaddfp v18,v22,v0,v30
	simd::store_f32_aligned(ctx.v18.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v22.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v30.f32)));
	// vspltw128 v26,v57,2
	simd::store_i32(ctx.v26.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v57.u32), 1));
	// vmaddfp v17,v21,v0,v29
	simd::store_f32_aligned(ctx.v17.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v21.f32), simd::load_f32_aligned(ctx.v0.f32)), simd::load_f32_aligned(ctx.v29.f32)));
	// vspltw128 v4,v57,1
	simd::store_i32(ctx.v4.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v57.u32), 2));
	// vmaddfp v19,v23,v11,v31
	simd::store_f32_aligned(ctx.v19.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v23.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v31.f32)));
	// vspltw128 v25,v58,1
	simd::store_i32(ctx.v25.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v58.u32), 2));
	// vmaddfp v20,v24,v11,v1
	simd::store_f32_aligned(ctx.v20.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v24.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v1.f32)));
	// vspltw128 v28,v58,2
	simd::store_i32(ctx.v28.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v58.u32), 1));
	// vmaddfp v22,v26,v11,v27
	simd::store_f32_aligned(ctx.v22.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v26.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v27.f32)));
	// vspltw128 v31,v46,0
	simd::store_i32(ctx.v31.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v46.u32), 3));
	// vmaddfp v24,v4,v11,v8
	simd::store_f32_aligned(ctx.v24.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v4.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v8.f32)));
	// vspltw128 v8,v45,1
	simd::store_i32(ctx.v8.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v45.u32), 2));
	// vmaddfp v21,v25,v11,v2
	simd::store_f32_aligned(ctx.v21.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v25.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v2.f32)));
	// vspltw128 v25,v45,2
	simd::store_i32(ctx.v25.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v45.u32), 1));
	// vmaddfp v23,v28,v11,v3
	simd::store_f32_aligned(ctx.v23.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v28.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v3.f32)));
	// vspltw128 v4,v33,1
	simd::store_i32(ctx.v4.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v33.u32), 2));
	// vspltw128 v1,v45,3
	simd::store_i32(ctx.v1.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v45.u32), 0));
	// vspltw128 v2,v46,1
	simd::store_i32(ctx.v2.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v46.u32), 2));
	// vspltw128 v32,v61,3
	simd::store_i32(ctx.v32.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v61.u32), 0));
	// vspltw128 v29,v43,3
	simd::store_i32(ctx.v29.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v43.u32), 0));
	// vspltw128 v3,v46,2
	simd::store_i32(ctx.v3.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v46.u32), 1));
	// vmaddfp v19,v31,v10,v19
	simd::store_f32_aligned(ctx.v19.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v31.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v19.f32)));
	// vspltw128 v30,v42,0
	simd::store_i32(ctx.v30.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v42.u32), 3));
	// vspltw128 v31,v39,2
	simd::store_i32(ctx.v31.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v39.u32), 1));
	// vmaddfp v20,v1,v10,v20
	simd::store_f32_aligned(ctx.v20.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v1.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v20.f32)));
	// vspltw128 v28,v40,0
	simd::store_i32(ctx.v28.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v40.u32), 3));
	// vmaddfp v22,v25,v10,v22
	simd::store_f32_aligned(ctx.v22.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v25.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v22.f32)));
	// vspltw128 v1,v40,2
	simd::store_i32(ctx.v1.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v40.u32), 1));
	// vmaddfp v24,v8,v10,v24
	simd::store_f32_aligned(ctx.v24.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v8.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v24.f32)));
	// vspltw128 v8,v46,3
	simd::store_i32(ctx.v8.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v46.u32), 0));
	// vmaddfp v25,v4,v12,v16
	simd::store_f32_aligned(ctx.v25.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v4.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v16.f32)));
	// vspltw128 v61,v59,0
	simd::store_i32(ctx.v61.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v59.u32), 3));
	// vmaddfp v21,v2,v10,v21
	simd::store_f32_aligned(ctx.v21.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v2.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v21.f32)));
	// vspltw128 v2,v39,1
	simd::store_i32(ctx.v2.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v39.u32), 2));
	// vmulfp128 v4,v32,v62
	simd::store_f32_aligned(ctx.v4.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v32.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vspltw128 v26,v41,3
	simd::store_i32(ctx.v26.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v41.u32), 0));
	// vmaddfp v23,v3,v10,v23
	simd::store_f32_aligned(ctx.v23.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v3.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v23.f32)));
	// vspltw128 v3,v58,3
	simd::store_i32(ctx.v3.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v58.u32), 0));
	// vmaddfp v17,v29,v13,v17
	simd::store_f32_aligned(ctx.v17.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v29.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v17.f32)));
	// vspltw128 v29,v39,3
	simd::store_i32(ctx.v29.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v39.u32), 0));
	// vmaddfp v18,v30,v13,v18
	simd::store_f32_aligned(ctx.v18.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v30.f32), simd::load_f32_aligned(ctx.v13.f32)), simd::load_f32_aligned(ctx.v18.f32)));
	// vspltw128 v30,v40,1
	simd::store_i32(ctx.v30.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v40.u32), 2));
	// vspltw128 v27,v33,0
	simd::store_i32(ctx.v27.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v33.u32), 3));
	// vmaddfp v28,v28,v9,v19
	simd::store_f32_aligned(ctx.v28.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v28.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v19.f32)));
	// vmaddfp v29,v29,v9,v20
	simd::store_f32_aligned(ctx.v29.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v29.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v20.f32)));
	// vmaddfp v31,v31,v9,v22
	simd::store_f32_aligned(ctx.v31.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v31.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v22.f32)));
	// vmaddfp v2,v2,v9,v24
	simd::store_f32_aligned(ctx.v2.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v2.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v24.f32)));
	// vmaddfp v30,v30,v9,v21
	simd::store_f32_aligned(ctx.v30.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v30.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v21.f32)));
	// vmaddfp v4,v3,v11,v4
	simd::store_f32_aligned(ctx.v4.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v3.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v4.f32)));
	// vmaddfp v1,v1,v9,v23
	simd::store_f32_aligned(ctx.v1.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v1.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v23.f32)));
	// vmulfp128 v3,v61,v62
	simd::store_f32_aligned(ctx.v3.f32, simd::mul_f32(simd::load_f32_aligned(ctx.v61.f32), simd::load_f32_aligned(ctx.v62.f32)));
	// vmaddfp v26,v26,v12,v17
	simd::store_f32_aligned(ctx.v26.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v26.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v17.f32)));
	// vmaddfp v27,v27,v12,v18
	simd::store_f32_aligned(ctx.v27.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v27.f32), simd::load_f32_aligned(ctx.v12.f32)), simd::load_f32_aligned(ctx.v18.f32)));
	// vaddfp128 v60,v38,v28
	simd::store_f32_aligned(ctx.v60.f32, simd::add_f32(simd::load_f32_aligned(ctx.v38.f32), simd::load_f32_aligned(ctx.v28.f32)));
	// vsubfp128 v52,v38,v28
	simd::store_f32_aligned(ctx.v52.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v38.f32), simd::load_f32_aligned(ctx.v28.f32)));
	// vaddfp128 v59,v37,v29
	simd::store_f32_aligned(ctx.v59.f32, simd::add_f32(simd::load_f32_aligned(ctx.v37.f32), simd::load_f32_aligned(ctx.v29.f32)));
	// vor128 v56,v31,v31
	simd::store_i8(ctx.v56.u8, simd::load_i8(ctx.v31.u8));
	// vsubfp128 v55,v37,v29
	simd::store_f32_aligned(ctx.v55.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v37.f32), simd::load_f32_aligned(ctx.v29.f32)));
	// vor128 v53,v2,v2
	simd::store_i8(ctx.v53.u8, simd::load_i8(ctx.v2.u8));
	// vspltw128 v2,v57,0
	simd::store_i32(ctx.v2.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v57.u32), 3));
	// vaddfp128 v58,v36,v30
	simd::store_f32_aligned(ctx.v58.f32, simd::add_f32(simd::load_f32_aligned(ctx.v36.f32), simd::load_f32_aligned(ctx.v30.f32)));
	// vmaddfp v31,v8,v10,v4
	simd::store_f32_aligned(ctx.v31.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v8.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v4.f32)));
	// vspltw128 v4,v45,0
	simd::store_i32(ctx.v4.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v45.u32), 3));
	// vaddfp128 v51,v35,v56
	simd::store_f32_aligned(ctx.v51.f32, simd::add_f32(simd::load_f32_aligned(ctx.v35.f32), simd::load_f32_aligned(ctx.v56.f32)));
	// vor128 v54,v1,v1
	simd::store_i8(ctx.v54.u8, simd::load_i8(ctx.v1.u8));
	// vaddfp128 v50,v25,v53
	simd::store_f32_aligned(ctx.v50.f32, simd::add_f32(simd::load_f32_aligned(ctx.v25.f32), simd::load_f32_aligned(ctx.v53.f32)));
	// vspltw128 v1,v40,3
	simd::store_i32(ctx.v1.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v40.u32), 0));
	// vspltw128 v8,v39,0
	simd::store_i32(ctx.v8.u32, simd::broadcast_lane_i32(simd::load_i32(ctx.v39.u32), 3));
	// vmaddfp v3,v2,v11,v3
	simd::store_f32_aligned(ctx.v3.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v2.f32), simd::load_f32_aligned(ctx.v11.f32)), simd::load_f32_aligned(ctx.v3.f32)));
	// vsubfp128 v48,v35,v56
	simd::store_f32_aligned(ctx.v48.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v35.f32), simd::load_f32_aligned(ctx.v56.f32)));
	// vaddfp128 v49,v34,v54
	simd::store_f32_aligned(ctx.v49.f32, simd::add_f32(simd::load_f32_aligned(ctx.v34.f32), simd::load_f32_aligned(ctx.v54.f32)));
	// vsubfp128 v47,v36,v30
	simd::store_f32_aligned(ctx.v47.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v36.f32), simd::load_f32_aligned(ctx.v30.f32)));
	// vsubfp128 v46,v25,v53
	simd::store_f32_aligned(ctx.v46.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v25.f32), simd::load_f32_aligned(ctx.v53.f32)));
	// vsubfp128 v45,v34,v54
	simd::store_f32_aligned(ctx.v45.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v34.f32), simd::load_f32_aligned(ctx.v54.f32)));
	// vrfin128 v44,v59
	simd::store_f32(ctx.v44.f32, simd::round_f32(simd::load_f32(ctx.v59.f32), simd::round_to_nearest_int));
	// vrfin128 v43,v60
	simd::store_f32(ctx.v43.f32, simd::round_f32(simd::load_f32(ctx.v60.f32), simd::round_to_nearest_int));
	// vrfin128 v41,v58
	simd::store_f32(ctx.v41.f32, simd::round_f32(simd::load_f32(ctx.v58.f32), simd::round_to_nearest_int));
	// vmaddfp v1,v1,v9,v31
	simd::store_f32_aligned(ctx.v1.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v1.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v31.f32)));
	// vrfin128 v42,v51
	simd::store_f32(ctx.v42.f32, simd::round_f32(simd::load_f32(ctx.v51.f32), simd::round_to_nearest_int));
	// vrfin128 v40,v50
	simd::store_f32(ctx.v40.f32, simd::round_f32(simd::load_f32(ctx.v50.f32), simd::round_to_nearest_int));
	// vmaddfp v4,v4,v10,v3
	simd::store_f32_aligned(ctx.v4.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v4.f32), simd::load_f32_aligned(ctx.v10.f32)), simd::load_f32_aligned(ctx.v3.f32)));
	// vrfin128 v38,v55
	simd::store_f32(ctx.v38.f32, simd::round_f32(simd::load_f32(ctx.v55.f32), simd::round_to_nearest_int));
	// vrfin128 v60,v45
	simd::store_f32(ctx.v60.f32, simd::round_f32(simd::load_f32(ctx.v45.f32), simd::round_to_nearest_int));
	// vrfin128 v36,v48
	simd::store_f32(ctx.v36.f32, simd::round_f32(simd::load_f32(ctx.v48.f32), simd::round_to_nearest_int));
	// vcfpsxws128 v59,v44,0
	simd::store_i32(ctx.v59.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v44.f32)));
	// vaddfp128 v34,v26,v1
	simd::store_f32_aligned(ctx.v34.f32, simd::add_f32(simd::load_f32_aligned(ctx.v26.f32), simd::load_f32_aligned(ctx.v1.f32)));
	// vsubfp128 v33,v26,v1
	simd::store_f32_aligned(ctx.v33.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v26.f32), simd::load_f32_aligned(ctx.v1.f32)));
	// vrfin128 v37,v52
	simd::store_f32(ctx.v37.f32, simd::round_f32(simd::load_f32(ctx.v52.f32), simd::round_to_nearest_int));
	// vrfin128 v39,v49
	simd::store_f32(ctx.v39.f32, simd::round_f32(simd::load_f32(ctx.v49.f32), simd::round_to_nearest_int));
	// vrfin128 v35,v47
	simd::store_f32(ctx.v35.f32, simd::round_f32(simd::load_f32(ctx.v47.f32), simd::round_to_nearest_int));
	// vrfin128 v32,v46
	simd::store_f32(ctx.v32.f32, simd::round_f32(simd::load_f32(ctx.v46.f32), simd::round_to_nearest_int));
	// vcfpsxws128 v58,v43,0
	simd::store_i32(ctx.v58.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v43.f32)));
	// vmaddfp v8,v8,v9,v4
	simd::store_f32_aligned(ctx.v8.f32, simd::add_f32(simd::mul_f32(simd::load_f32_aligned(ctx.v8.f32), simd::load_f32_aligned(ctx.v9.f32)), simd::load_f32_aligned(ctx.v4.f32)));
	// vcfpsxws128 v53,v38,0
	simd::store_i32(ctx.v53.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v38.f32)));
	// vcfpsxws128 v55,v40,0
	simd::store_i32(ctx.v55.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v40.f32)));
	// vcfpsxws128 v49,v36,0
	simd::store_i32(ctx.v49.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v36.f32)));
	// vcfpsxws128 v57,v42,0
	simd::store_i32(ctx.v57.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v42.f32)));
	// vrfin128 v52,v34
	simd::store_f32(ctx.v52.f32, simd::round_f32(simd::load_f32(ctx.v34.f32), simd::round_to_nearest_int));
	// vrfin128 v51,v33
	simd::store_f32(ctx.v51.f32, simd::round_f32(simd::load_f32(ctx.v33.f32), simd::round_to_nearest_int));
	// vcfpsxws128 v56,v41,0
	simd::store_i32(ctx.v56.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v41.f32)));
	// vcfpsxws128 v54,v39,0
	simd::store_i32(ctx.v54.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v39.f32)));
	// vcfpsxws128 v48,v35,0
	simd::store_i32(ctx.v48.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v35.f32)));
	// vcfpsxws128 v46,v60,0
	simd::store_i32(ctx.v46.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v60.f32)));
	// vcfpsxws128 v50,v37,0
	simd::store_i32(ctx.v50.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v37.f32)));
	// vperm128 v61,v58,v59,v7
	simd::store_i8(ctx.v61.u8, simd::permute_bytes(simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v59.u8), simd::load_i8(ctx.v7.u8)));
	// vaddfp128 v45,v27,v8
	simd::store_f32_aligned(ctx.v45.f32, simd::add_f32(simd::load_f32_aligned(ctx.v27.f32), simd::load_f32_aligned(ctx.v8.f32)));
	// vsubfp128 v44,v27,v8
	simd::store_f32_aligned(ctx.v44.f32, simd::sub_f32(simd::load_f32_aligned(ctx.v27.f32), simd::load_f32_aligned(ctx.v8.f32)));
	// vcfpsxws128 v47,v32,0
	simd::store_i32(ctx.v47.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v32.f32)));
	// vcfpsxws128 v43,v52,0
	simd::store_i32(ctx.v43.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v52.f32)));
	// vcfpsxws128 v42,v51,0
	simd::store_i32(ctx.v42.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v51.f32)));
	// vperm128 v60,v56,v57,v7
	simd::store_i8(ctx.v60.u8, simd::permute_bytes(simd::load_i8(ctx.v56.u8), simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v7.u8)));
	// vperm128 v59,v54,v55,v7
	simd::store_i8(ctx.v59.u8, simd::permute_bytes(simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v55.u8), simd::load_i8(ctx.v7.u8)));
	// vperm128 v57,v48,v49,v7
	simd::store_i8(ctx.v57.u8, simd::permute_bytes(simd::load_i8(ctx.v48.u8), simd::load_i8(ctx.v49.u8), simd::load_i8(ctx.v7.u8)));
	// vperm128 v58,v50,v53,v7
	simd::store_i8(ctx.v58.u8, simd::permute_bytes(simd::load_i8(ctx.v50.u8), simd::load_i8(ctx.v53.u8), simd::load_i8(ctx.v7.u8)));
	// vrfin128 v38,v45
	simd::store_f32(ctx.v38.f32, simd::round_f32(simd::load_f32(ctx.v45.f32), simd::round_to_nearest_int));
	// vperm128 v41,v61,v59,v6
	simd::store_i8(ctx.v41.u8, simd::permute_bytes(simd::load_i8(ctx.v61.u8), simd::load_i8(ctx.v59.u8), simd::load_i8(ctx.v6.u8)));
	// vrfin128 v36,v44
	simd::store_f32(ctx.v36.f32, simd::round_f32(simd::load_f32(ctx.v44.f32), simd::round_to_nearest_int));
	// vperm128 v40,v61,v59,v5
	simd::store_i8(ctx.v40.u8, simd::permute_bytes(simd::load_i8(ctx.v61.u8), simd::load_i8(ctx.v59.u8), simd::load_i8(ctx.v5.u8)));
	// vperm128 v56,v46,v47,v7
	simd::store_i8(ctx.v56.u8, simd::permute_bytes(simd::load_i8(ctx.v46.u8), simd::load_i8(ctx.v47.u8), simd::load_i8(ctx.v7.u8)));
	// vperm128 v39,v58,v56,v5
	simd::store_i8(ctx.v39.u8, simd::permute_bytes(simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v56.u8), simd::load_i8(ctx.v5.u8)));
	// vperm128 v37,v58,v56,v6
	simd::store_i8(ctx.v37.u8, simd::permute_bytes(simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v56.u8), simd::load_i8(ctx.v6.u8)));
	// vcfpsxws128 v35,v38,0
	simd::store_i32(ctx.v35.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v38.f32)));
	// vcfpsxws128 v34,v36,0
	simd::store_i32(ctx.v34.s32, simd::vctsxs(simd::load_f32_aligned(ctx.v36.f32)));
	// vperm128 v55,v43,v35,v7
	simd::store_i8(ctx.v55.u8, simd::permute_bytes(simd::load_i8(ctx.v43.u8), simd::load_i8(ctx.v35.u8), simd::load_i8(ctx.v7.u8)));
	// vperm128 v54,v42,v34,v7
	simd::store_i8(ctx.v54.u8, simd::permute_bytes(simd::load_i8(ctx.v42.u8), simd::load_i8(ctx.v34.u8), simd::load_i8(ctx.v7.u8)));
	// vperm128 v33,v60,v55,v6
	simd::store_i8(ctx.v33.u8, simd::permute_bytes(simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v55.u8), simd::load_i8(ctx.v6.u8)));
	// vperm128 v32,v57,v54,v5
	simd::store_i8(ctx.v32.u8, simd::permute_bytes(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v5.u8)));
	// vperm128 v61,v60,v55,v5
	simd::store_i8(ctx.v61.u8, simd::permute_bytes(simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v55.u8), simd::load_i8(ctx.v5.u8)));
	// vperm128 v60,v57,v54,v6
	simd::store_i8(ctx.v60.u8, simd::permute_bytes(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v6.u8)));
	// vmrghw128 v59,v41,v33
	simd::store_i32(ctx.v59.u32, simd::unpackhi_i32(simd::load_i32(ctx.v33.u32), simd::load_i32(ctx.v41.u32)));
	// vmrglw128 v58,v39,v32
	simd::store_i32(ctx.v58.u32, simd::unpacklo_i32(simd::load_i32(ctx.v32.u32), simd::load_i32(ctx.v39.u32)));
	// vmrglw128 v57,v41,v33
	simd::store_i32(ctx.v57.u32, simd::unpacklo_i32(simd::load_i32(ctx.v33.u32), simd::load_i32(ctx.v41.u32)));
	// vmrghw128 v56,v39,v32
	simd::store_i32(ctx.v56.u32, simd::unpackhi_i32(simd::load_i32(ctx.v32.u32), simd::load_i32(ctx.v39.u32)));
	// vmrghw128 v55,v40,v61
	simd::store_i32(ctx.v55.u32, simd::unpackhi_i32(simd::load_i32(ctx.v61.u32), simd::load_i32(ctx.v40.u32)));
	// vmrglw128 v53,v37,v60
	simd::store_i32(ctx.v53.u32, simd::unpacklo_i32(simd::load_i32(ctx.v60.u32), simd::load_i32(ctx.v37.u32)));
	// vmrglw128 v54,v40,v61
	simd::store_i32(ctx.v54.u32, simd::unpacklo_i32(simd::load_i32(ctx.v61.u32), simd::load_i32(ctx.v40.u32)));
	// vmrghw128 v52,v37,v60
	simd::store_i32(ctx.v52.u32, simd::unpackhi_i32(simd::load_i32(ctx.v60.u32), simd::load_i32(ctx.v37.u32)));
	// stvlx128 v59,r0,r22
{
	uint32_t addr = 
ctx.r22.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v59), 15 - i));
}
	// stvlx128 v58,r22,r8
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v58), 15 - i));
}
	// stvlx128 v57,r22,r9
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r9.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v57), 15 - i));
}
	// stvlx128 v56,r22,r10
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v56), 15 - i));
}
	// stvlx128 v55,r22,r4
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v55), 15 - i));
}
	// stvlx128 v53,r22,r5
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r5.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v53), 15 - i));
}
	// stvlx128 v54,r22,r6
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r6.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v54), 15 - i));
}
	// stvlx128 v52,r22,r7
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v52), 15 - i));
}
loc_8238B5D0:
	// rlwinm r23,r23,1,0,30
	ctx.r23.u64 = rotl64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// addi r11,r11,256
	ctx.r11.s64 = ctx.r11.s64 + 256;
	// bdnz 0x8238afb4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8238AFB4;
	// b 0x8233e4a0
	__restgprlr_22(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238B5E4"))) PPC_WEAK_FUNC(sub_8238B5E4);
PPC_FUNC_IMPL(__imp__sub_8238B5E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238B5E8"))) PPC_WEAK_FUNC(sub_8238B5E8);
PPC_FUNC_IMPL(__imp__sub_8238B5E8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e46c
	ctx.lr = 0x8238B5F0;
	__restfpr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r9,r3,768
	ctx.r9.s64 = ctx.r3.s64 + 768;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r9,8
	ctx.r11.s64 = ctx.r9.s64 + 8;
	// std r10,768(r3)
	PPC_STORE_U64(ctx.r3.u32 + 768, ctx.r10.u64);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r10,776(r3)
	PPC_STORE_U64(ctx.r3.u32 + 776, ctx.r10.u64);
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// addi r8,r3,2304
	ctx.r8.s64 = ctx.r3.s64 + 2304;
	// addi r7,r3,5228
	ctx.r7.s64 = ctx.r3.s64 + 5228;
	// addi r30,r3,4420
	ctx.r30.s64 = ctx.r3.s64 + 4420;
	// addi r29,r3,4472
	ctx.r29.s64 = ctx.r3.s64 + 4472;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// stdu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r11.u32 = ea;
	// std r10,8(r11)
	PPC_STORE_U64(ctx.r11.u32 + 8, ctx.r10.u64);
	// lwz r6,5128(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5128);
	// stw r6,4456(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4456, ctx.r6.u32);
	// stw r8,4452(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4452, ctx.r8.u32);
	// stw r10,4468(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4468, ctx.r10.u32);
	// lwz r5,5320(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5320);
	// stw r5,4464(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4464, ctx.r5.u32);
	// stw r7,4460(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4460, ctx.r7.u32);
	// stw r9,4448(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4448, ctx.r9.u32);
	// lwz r11,5304(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5304);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238B944;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r31,1024
	ctx.r9.s64 = ctx.r31.s64 + 1024;
	// stb r3,4472(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4472, ctx.r3.u8);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r9,4448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4448, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,5304(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5304);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8238B964;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r6,r31,1280
	ctx.r6.s64 = ctx.r31.s64 + 1280;
	// stb r3,4473(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4473, ctx.r3.u8);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r6,4448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4448, ctx.r6.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,5304(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5304);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// bctrl 
	ctx.lr = 0x8238B984;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r31,1536
	ctx.r3.s64 = ctx.r31.s64 + 1536;
	// stb r4,4474(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4474, ctx.r4.u8);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r3,4448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4448, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,5304(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5304);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238B9A8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r8,r31,5232
	ctx.r8.s64 = ctx.r31.s64 + 5232;
	// lwz r10,5324(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5324);
	// addi r7,r31,1792
	ctx.r7.s64 = ctx.r31.s64 + 1792;
	// stb r3,4475(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4475, ctx.r3.u8);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r8,4460(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4460, ctx.r8.u32);
	// stw r10,4464(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4464, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,4448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4448, ctx.r7.u32);
	// lwz r6,5304(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5304);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// bctrl 
	ctx.lr = 0x8238B9D8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r31,5236
	ctx.r4.s64 = ctx.r31.s64 + 5236;
	// addi r3,r31,2048
	ctx.r3.s64 = ctx.r31.s64 + 2048;
	// stb r5,4476(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4476, ctx.r5.u8);
	// stw r4,4460(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4460, ctx.r4.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stw r3,4448(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4448, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,5304(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5304);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238BA04;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// lwz r9,5120(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5120);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stb r10,4477(r31)
	PPC_STORE_U8(ctx.r31.u32 + 4477, ctx.r10.u8);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8238BA1C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8233e4bc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238BA28"))) PPC_WEAK_FUNC(sub_8238BA28);
PPC_FUNC_IMPL(__imp__sub_8238BA28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e464
	ctx.lr = 0x8238BA30;
	__restfpr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,5128(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5128);
	// addi r10,r3,2560
	ctx.r10.s64 = ctx.r3.s64 + 2560;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,4452(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4452, ctx.r10.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r9,4468(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4468, ctx.r9.u32);
	// addi r29,r3,4420
	ctx.r29.s64 = ctx.r3.s64 + 4420;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r11,4456(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4456, ctx.r11.u32);
	// addi r28,r3,768
	ctx.r28.s64 = ctx.r3.s64 + 768;
	// lwz r8,5224(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5224);
	// rlwinm r27,r8,2,0,29
	ctx.r27.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
loc_8238BA64:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bge cr6,0x8238ba8c
	if (!ctx.cr6.lt) goto loc_8238BA8C;
	// stw r28,28(r29)
	PPC_STORE_U32(ctx.r29.u32 + 28, ctx.r28.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,5308(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5308);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238BA84;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// add r10,r30,r31
	ctx.r10.u64 = ctx.r30.u64 + ctx.r31.u64;
	// stb r3,4472(r10)
	PPC_STORE_U8(ctx.r10.u32 + 4472, ctx.r3.u8);
loc_8238BA8C:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// rlwinm r27,r27,1,0,30
	ctx.r27.u64 = rotl64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r28,r28,256
	ctx.r28.s64 = ctx.r28.s64 + 256;
	// cmpwi cr6,r30,6
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 6, ctx.xer);
	// blt cr6,0x8238ba64
	if (ctx.cr6.lt) goto loc_8238BA64;
	// lwz r11,5224(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5224);
	// addi r3,r31,4472
	ctx.r3.s64 = ctx.r31.s64 + 4472;
	// lwz r10,5124(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5124);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r9,4512(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4512, ctx.r9.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8238BABC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8233e4b4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238BAC8"))) PPC_WEAK_FUNC(sub_8238BAC8);
PPC_FUNC_IMPL(__imp__sub_8238BAC8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e45c
	ctx.lr = 0x8238BAD0;
	__restfpr_25(ctx, base);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r7,0(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lhz r5,12(r5)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r5.u32 + 12);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// add r10,r7,r11
	ctx.r10.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r8,4(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// lwz r9,0(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwz r3,4(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lwz r27,8(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// add r7,r3,r7
	ctx.r7.u64 = ctx.r3.u64 + ctx.r7.u64;
	// ld r3,0(r10)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// ldux r4,r10,r11
	ea = ctx.r10.u32 + ctx.r11.u32;
	ctx.r4.u64 = PPC_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// ld r31,0(r8)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r8.u32 + 0);
	// lhz r26,14(r30)
	ctx.r26.u64 = PPC_LOAD_U16(ctx.r30.u32 + 14);
	// lwz r5,8(r30)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// std r3,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r3.u64);
	// ldux r3,r10,r11
	ea = ctx.r10.u32 + ctx.r11.u32;
	ctx.r3.u64 = PPC_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// stdux r4,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r4.u64);
	ctx.r9.u32 = ea;
	// ldux r4,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	ctx.r4.u64 = PPC_LOAD_U64(ea);
	ctx.r8.u32 = ea;
	// std r31,0(r7)
	PPC_STORE_U64(ctx.r7.u32 + 0, ctx.r31.u64);
	// lwz r6,4(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// ldux r31,r10,r11
	ea = ctx.r10.u32 + ctx.r11.u32;
	ctx.r31.u64 = PPC_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// stdux r3,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r3.u64);
	ctx.r9.u32 = ea;
	// add r5,r5,r6
	ctx.r5.u64 = ctx.r5.u64 + ctx.r6.u64;
	// ldux r3,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	ctx.r3.u64 = PPC_LOAD_U64(ea);
	ctx.r8.u32 = ea;
	// add r6,r27,r6
	ctx.r6.u64 = ctx.r27.u64 + ctx.r6.u64;
	// stdux r4,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r4.u64);
	ctx.r7.u32 = ea;
	// ldux r30,r10,r11
	ea = ctx.r10.u32 + ctx.r11.u32;
	ctx.r30.u64 = PPC_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// stdux r31,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r31.u64);
	ctx.r9.u32 = ea;
	// ldux r31,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	ctx.r31.u64 = PPC_LOAD_U64(ea);
	ctx.r8.u32 = ea;
	// lvlx128 v63,r0,r6
	temp.u32 = ctx.r0.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v63,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stdux r3,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r3.u64);
	ctx.r7.u32 = ea;
	// ldux r29,r10,r11
	ea = ctx.r10.u32 + ctx.r11.u32;
	ctx.r29.u64 = PPC_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// stdux r30,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r30.u64);
	ctx.r9.u32 = ea;
	// ldux r30,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	ctx.r30.u64 = PPC_LOAD_U64(ea);
	ctx.r8.u32 = ea;
	// stdux r31,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r31.u64);
	ctx.r7.u32 = ea;
	// ldux r28,r10,r11
	ea = ctx.r10.u32 + ctx.r11.u32;
	ctx.r28.u64 = PPC_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// stdux r29,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r29.u64);
	ctx.r9.u32 = ea;
	// ldux r29,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	ctx.r29.u64 = PPC_LOAD_U64(ea);
	ctx.r8.u32 = ea;
	// stdux r30,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r30.u64);
	ctx.r7.u32 = ea;
	// ldux r4,r10,r11
	ea = ctx.r10.u32 + ctx.r11.u32;
	ctx.r4.u64 = PPC_LOAD_U64(ea);
	ctx.r10.u32 = ea;
	// stdux r28,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r28.u64);
	ctx.r9.u32 = ea;
	// ldux r28,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	ctx.r28.u64 = PPC_LOAD_U64(ea);
	ctx.r8.u32 = ea;
	// stdux r29,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r29.u64);
	ctx.r7.u32 = ea;
	// stdux r4,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r4.u64);
	ctx.r9.u32 = ea;
	// ldux r3,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	ctx.r3.u64 = PPC_LOAD_U64(ea);
	ctx.r8.u32 = ea;
	// stdux r28,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r28.u64);
	ctx.r7.u32 = ea;
	// stdux r3,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r3.u64);
	ctx.r7.u32 = ea;
	// extsh r11,r26
	ctx.r11.s64 = ctx.r26.s16;
	// stvlx128 v63,r0,r5
{
	uint32_t addr = 
ctx.r5.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v63), 15 - i));
}
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v62,r11,r6
	temp.u32 = ctx.r11.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stvlx128 v62,r5,r11
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v62), 15 - i));
}
	// rlwinm r25,r11,1,0,30
	ctx.r25.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r9
	ctx.r30.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r29,r11,3,0,28
	ctx.r29.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx128 v61,r25,r6
	temp.u32 = ctx.r25.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v61,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r28,r11,r8
	ctx.r28.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 + ctx.r4.u64;
	// subf r27,r11,r10
	ctx.r27.s64 = ctx.r10.s64 - ctx.r11.s64;
	// rlwinm r4,r31,1,0,30
	ctx.r4.u64 = rotl64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r3
	ctx.r8.u64 = ctx.r11.u64 + ctx.r3.u64;
	// add r10,r11,r7
	ctx.r10.u64 = ctx.r11.u64 + ctx.r7.u64;
	// subf r31,r11,r29
	ctx.r31.s64 = ctx.r29.s64 - ctx.r11.s64;
	// rlwinm r3,r30,1,0,30
	ctx.r3.u64 = rotl64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r26,r11,4,0,27
	ctx.r26.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r29,r11,3,0,28
	ctx.r29.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mulli r30,r11,11
	ctx.r30.s64 = ctx.r11.s64 * 11;
	// stvlx128 v61,r5,r25
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r25.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v61), 15 - i));
}
	// rlwinm r28,r28,2,0,29
	ctx.r28.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx128 v60,r10,r6
	temp.u32 = ctx.r10.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// mulli r25,r11,13
	ctx.r25.s64 = ctx.r11.s64 * 13;
	// stvlx128 v60,r5,r10
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v60), 15 - i));
}
	// lvlx128 v59,r7,r6
	temp.u32 = ctx.r7.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v59,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r10,r27,1,0,30
	ctx.r10.u64 = rotl64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// stvlx128 v59,r5,r7
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v59), 15 - i));
}
	// subf r7,r11,r26
	ctx.r7.s64 = ctx.r26.s64 - ctx.r11.s64;
	// lvlx128 v58,r9,r6
	temp.u32 = ctx.r9.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v58,r5,r9
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r9.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v58), 15 - i));
}
	// lvlx128 v57,r4,r6
	temp.u32 = ctx.r4.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v57,r5,r4
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v57), 15 - i));
}
	// lvlx128 v56,r31,r6
	temp.u32 = ctx.r31.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v56,r5,r31
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r31.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v56), 15 - i));
}
	// lvlx128 v55,r29,r6
	temp.u32 = ctx.r29.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v55,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v55,r5,r29
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r29.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v55), 15 - i));
}
	// lvlx128 v54,r8,r6
	temp.u32 = ctx.r8.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v54,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v54,r5,r8
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v54), 15 - i));
}
	// lvlx128 v53,r3,r6
	temp.u32 = ctx.r3.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v53,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v53,r5,r3
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r3.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v53), 15 - i));
}
	// lvlx128 v52,r30,r6
	temp.u32 = ctx.r30.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v52,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v52,r5,r30
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r30.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v52), 15 - i));
}
	// lvlx128 v51,r28,r6
	temp.u32 = ctx.r28.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v51,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v51,r5,r28
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r28.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v51), 15 - i));
}
	// lvlx128 v50,r25,r6
	temp.u32 = ctx.r25.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v50,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v50,r5,r25
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r25.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v50), 15 - i));
}
	// lvlx128 v49,r10,r6
	temp.u32 = ctx.r10.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v49,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v49,r5,r10
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v49), 15 - i));
}
	// lvlx128 v48,r7,r6
	temp.u32 = ctx.r7.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v48,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v48,r5,r7
{
	uint32_t addr = 
ctx.r5.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v48), 15 - i));
}
	// b 0x8233e4ac
	__restgprlr_25(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238BC94"))) PPC_WEAK_FUNC(sub_8238BC94);
PPC_FUNC_IMPL(__imp__sub_8238BC94) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238BC98"))) PPC_WEAK_FUNC(sub_8238BC98);
PPC_FUNC_IMPL(__imp__sub_8238BC98) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e43c
	ctx.lr = 0x8238BCA0;
	__restfpr_17(ctx, base);
	// lhz r11,12(r5)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r5.u32 + 12);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lwz r28,0(r5)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r31,4(r4)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r8,4(r5)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// rlwinm r29,r11,1,0,30
	ctx.r29.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r27,r11,r9
	ctx.r27.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r30,r11,2,0,29
	ctx.r30.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r26,r11,3,0,28
	ctx.r26.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r10,r28
	ctx.r9.u64 = ctx.r10.u64 + ctx.r28.u64;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r31,r31,r10
	ctx.r31.u64 = ctx.r31.u64 + ctx.r10.u64;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// rlwinm r28,r11,2,0,29
	ctx.r28.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// rlwinm r27,r27,1,0,30
	ctx.r27.u64 = rotl64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r26,r11,r26
	ctx.r26.s64 = ctx.r26.s64 - ctx.r11.s64;
	// bge cr6,0x8238bd40
	if (!ctx.cr6.lt) goto loc_8238BD40;
	// dcbzl r0,r9
	memset(base + ((ctx.r9.u32) & ~127), 0, 128);
	// dcbzl r11,r9
	memset(base + ((ctx.r11.u32 + ctx.r9.u32) & ~127), 0, 128);
	// dcbzl r10,r9
	memset(base + ((ctx.r10.u32 + ctx.r9.u32) & ~127), 0, 128);
	// dcbzl r29,r9
	memset(base + ((ctx.r29.u32 + ctx.r9.u32) & ~127), 0, 128);
	// dcbzl r28,r9
	memset(base + ((ctx.r28.u32 + ctx.r9.u32) & ~127), 0, 128);
	// dcbzl r30,r9
	memset(base + ((ctx.r30.u32 + ctx.r9.u32) & ~127), 0, 128);
	// dcbzl r27,r9
	memset(base + ((ctx.r27.u32 + ctx.r9.u32) & ~127), 0, 128);
	// dcbzl r26,r9
	memset(base + ((ctx.r26.u32 + ctx.r9.u32) & ~127), 0, 128);
	// dcbzl r0,r8
	memset(base + ((ctx.r8.u32) & ~127), 0, 128);
	// dcbzl r11,r8
	memset(base + ((ctx.r11.u32 + ctx.r8.u32) & ~127), 0, 128);
	// dcbzl r10,r8
	memset(base + ((ctx.r10.u32 + ctx.r8.u32) & ~127), 0, 128);
	// dcbzl r29,r8
	memset(base + ((ctx.r29.u32 + ctx.r8.u32) & ~127), 0, 128);
	// dcbzl r28,r8
	memset(base + ((ctx.r28.u32 + ctx.r8.u32) & ~127), 0, 128);
	// dcbzl r30,r8
	memset(base + ((ctx.r30.u32 + ctx.r8.u32) & ~127), 0, 128);
	// dcbzl r27,r8
	memset(base + ((ctx.r27.u32 + ctx.r8.u32) & ~127), 0, 128);
	// dcbzl r26,r8
	memset(base + ((ctx.r26.u32 + ctx.r8.u32) & ~127), 0, 128);
loc_8238BD40:
	// ld r30,0(r7)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r7.u32 + 0);
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = rotl64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// ldux r10,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	ctx.r10.u64 = PPC_LOAD_U64(ea);
	ctx.r7.u32 = ea;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ld r29,0(r31)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// ldux r26,r31,r11
	ea = ctx.r31.u32 + ctx.r11.u32;
	ctx.r26.u64 = PPC_LOAD_U64(ea);
	ctx.r31.u32 = ea;
	// lhz r28,14(r5)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r5.u32 + 14);
	// std r30,0(r9)
	PPC_STORE_U64(ctx.r9.u32 + 0, ctx.r30.u64);
	// ldux r6,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	ctx.r6.u64 = PPC_LOAD_U64(ea);
	ctx.r7.u32 = ea;
	// stdux r10,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r10.u64);
	ctx.r9.u32 = ea;
	// extsh r10,r28
	ctx.r10.s64 = ctx.r28.s16;
	// std r29,0(r8)
	PPC_STORE_U64(ctx.r8.u32 + 0, ctx.r29.u64);
	// stdux r26,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r26.u64);
	ctx.r8.u32 = ea;
	// rlwinm r28,r10,3,0,28
	ctx.r28.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r21,r10,1,0,30
	ctx.r21.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// ldux r30,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	ctx.r30.u64 = PPC_LOAD_U64(ea);
	ctx.r7.u32 = ea;
	// subf r19,r10,r28
	ctx.r19.s64 = ctx.r28.s64 - ctx.r10.s64;
	// stdux r6,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r6.u64);
	ctx.r9.u32 = ea;
	// rlwinm r22,r10,2,0,29
	ctx.r22.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// ldux r6,r31,r11
	ea = ctx.r31.u32 + ctx.r11.u32;
	ctx.r6.u64 = PPC_LOAD_U64(ea);
	ctx.r31.u32 = ea;
	// rlwinm r23,r10,1,0,30
	ctx.r23.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r24,r10,1,0,30
	ctx.r24.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r25,r10,2,0,29
	ctx.r25.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// ldux r29,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	ctx.r29.u64 = PPC_LOAD_U64(ea);
	ctx.r7.u32 = ea;
	// rlwinm r26,r10,3,0,28
	ctx.r26.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stdux r30,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r30.u64);
	ctx.r9.u32 = ea;
	// add r21,r10,r21
	ctx.r21.u64 = ctx.r10.u64 + ctx.r21.u64;
	// ldux r30,r31,r11
	ea = ctx.r31.u32 + ctx.r11.u32;
	ctx.r30.u64 = PPC_LOAD_U64(ea);
	ctx.r31.u32 = ea;
	// rlwinm r20,r10,3,0,28
	ctx.r20.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stdux r6,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r6.u64);
	ctx.r8.u32 = ea;
	// add r22,r10,r22
	ctx.r22.u64 = ctx.r10.u64 + ctx.r22.u64;
	// lwz r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// add r23,r10,r23
	ctx.r23.u64 = ctx.r10.u64 + ctx.r23.u64;
	// ldux r28,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	ctx.r28.u64 = PPC_LOAD_U64(ea);
	ctx.r7.u32 = ea;
	// rlwinm r18,r10,4,0,27
	ctx.r18.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// stdux r29,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r29.u64);
	ctx.r9.u32 = ea;
	// rlwinm r4,r10,1,0,30
	ctx.r4.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// ldux r29,r31,r11
	ea = ctx.r31.u32 + ctx.r11.u32;
	ctx.r29.u64 = PPC_LOAD_U64(ea);
	ctx.r31.u32 = ea;
	// stdux r30,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r30.u64);
	ctx.r8.u32 = ea;
	// add r30,r10,r26
	ctx.r30.u64 = ctx.r10.u64 + ctx.r26.u64;
	// mulli r26,r10,13
	ctx.r26.s64 = ctx.r10.s64 * 13;
	// ldux r27,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	ctx.r27.u64 = PPC_LOAD_U64(ea);
	ctx.r7.u32 = ea;
	// stdux r28,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r28.u64);
	ctx.r9.u32 = ea;
	// ldux r28,r31,r11
	ea = ctx.r31.u32 + ctx.r11.u32;
	ctx.r28.u64 = PPC_LOAD_U64(ea);
	ctx.r31.u32 = ea;
	// stdux r29,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r29.u64);
	ctx.r8.u32 = ea;
	// ldux r17,r7,r11
	ea = ctx.r7.u32 + ctx.r11.u32;
	ctx.r17.u64 = PPC_LOAD_U64(ea);
	ctx.r7.u32 = ea;
	// stdux r27,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r27.u64);
	ctx.r9.u32 = ea;
	// ldux r27,r31,r11
	ea = ctx.r31.u32 + ctx.r11.u32;
	ctx.r27.u64 = PPC_LOAD_U64(ea);
	ctx.r31.u32 = ea;
	// rlwinm r29,r22,1,0,30
	ctx.r29.u64 = rotl64(ctx.r22.u32 | (ctx.r22.u64 << 32), 1) & 0xFFFFFFFE;
	// stdux r28,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r28.u64);
	ctx.r8.u32 = ea;
	// mulli r28,r10,11
	ctx.r28.s64 = ctx.r10.s64 * 11;
	// lwz r7,4(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r3,8(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 8);
	// stdux r17,r9,r11
	ea = ctx.r9.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r17.u64);
	ctx.r9.u32 = ea;
	// ldux r9,r31,r11
	ea = ctx.r31.u32 + ctx.r11.u32;
	ctx.r9.u64 = PPC_LOAD_U64(ea);
	ctx.r31.u32 = ea;
	// stdux r27,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r27.u64);
	ctx.r8.u32 = ea;
	// add r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 + ctx.r7.u64;
	// add r5,r10,r24
	ctx.r5.u64 = ctx.r10.u64 + ctx.r24.u64;
	// stdux r9,r8,r11
	ea = ctx.r8.u32 + ctx.r11.u32;
	PPC_STORE_U64(ea, ctx.r9.u64);
	ctx.r8.u32 = ea;
	// add r7,r3,r7
	ctx.r7.u64 = ctx.r3.u64 + ctx.r7.u64;
	// add r9,r10,r25
	ctx.r9.u64 = ctx.r10.u64 + ctx.r25.u64;
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r21,1,0,30
	ctx.r11.u64 = rotl64(ctx.r21.u32 | (ctx.r21.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r10,r20
	ctx.r8.s64 = ctx.r20.s64 - ctx.r10.s64;
	// rlwinm r31,r10,3,0,28
	ctx.r31.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r27,r23,2,0,29
	ctx.r27.u64 = rotl64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r25,r19,1,0,30
	ctx.r25.u64 = rotl64(ctx.r19.u32 | (ctx.r19.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r24,r10,r18
	ctx.r24.s64 = ctx.r18.s64 - ctx.r10.s64;
	// bge cr6,0x8238be94
	if (!ctx.cr6.lt) goto loc_8238BE94;
	// dcbzl r0,r7
	memset(base + ((ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r10,r7
	memset(base + ((ctx.r10.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r4,r7
	memset(base + ((ctx.r4.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r5,r7
	memset(base + ((ctx.r5.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r3,r7
	memset(base + ((ctx.r3.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r9,r7
	memset(base + ((ctx.r9.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r11,r7
	memset(base + ((ctx.r11.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r8,r7
	memset(base + ((ctx.r8.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r31,r7
	memset(base + ((ctx.r31.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r30,r7
	memset(base + ((ctx.r30.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r29,r7
	memset(base + ((ctx.r29.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r28,r7
	memset(base + ((ctx.r28.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r27,r7
	memset(base + ((ctx.r27.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r26,r7
	memset(base + ((ctx.r26.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r25,r7
	memset(base + ((ctx.r25.u32 + ctx.r7.u32) & ~127), 0, 128);
	// dcbzl r24,r7
	memset(base + ((ctx.r24.u32 + ctx.r7.u32) & ~127), 0, 128);
loc_8238BE94:
	// lvlx128 v63,r0,r6
	temp.u32 = ctx.r0.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v63,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v63,r0,r7
{
	uint32_t addr = 
ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v63), 15 - i));
}
	// lvlx128 v62,r10,r6
	temp.u32 = ctx.r10.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v62,r7,r10
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v62), 15 - i));
}
	// lvlx128 v61,r4,r6
	temp.u32 = ctx.r4.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v61,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v61,r7,r4
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v61), 15 - i));
}
	// lvlx128 v60,r5,r6
	temp.u32 = ctx.r5.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v60,r7,r5
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r5.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v60), 15 - i));
}
	// lvlx128 v59,r3,r6
	temp.u32 = ctx.r3.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v59,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v59,r7,r3
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r3.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v59), 15 - i));
}
	// lvlx128 v58,r9,r6
	temp.u32 = ctx.r9.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v58,r7,r9
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r9.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v58), 15 - i));
}
	// lvlx128 v57,r11,r6
	temp.u32 = ctx.r11.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v57,r7,r11
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v57), 15 - i));
}
	// lvlx128 v56,r8,r6
	temp.u32 = ctx.r8.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v56,r7,r8
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v56), 15 - i));
}
	// lvlx128 v55,r31,r6
	temp.u32 = ctx.r31.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v55,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v55,r7,r31
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r31.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v55), 15 - i));
}
	// lvlx128 v54,r30,r6
	temp.u32 = ctx.r30.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v54,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v54,r7,r30
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r30.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v54), 15 - i));
}
	// lvlx128 v53,r29,r6
	temp.u32 = ctx.r29.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v53,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v53,r7,r29
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r29.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v53), 15 - i));
}
	// lvlx128 v52,r28,r6
	temp.u32 = ctx.r28.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v52,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v52,r7,r28
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r28.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v52), 15 - i));
}
	// lvlx128 v51,r27,r6
	temp.u32 = ctx.r27.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v51,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v51,r7,r27
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r27.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v51), 15 - i));
}
	// lvlx128 v50,r26,r6
	temp.u32 = ctx.r26.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v50,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v50,r7,r26
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r26.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v50), 15 - i));
}
	// lvlx128 v49,r25,r6
	temp.u32 = ctx.r25.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v49,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v49,r7,r25
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r25.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v49), 15 - i));
}
	// lvlx128 v48,r24,r6
	temp.u32 = ctx.r24.u32 + ctx.r6.u32;
	simd::store_shuffled(ctx.v48,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvlx128 v48,r7,r24
{
	uint32_t addr = 
ctx.r7.u32 + ctx.r24.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v48), 15 - i));
}
	// b 0x8233e48c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238BF18"))) PPC_WEAK_FUNC(sub_8238BF18);
PPC_FUNC_IMPL(__imp__sub_8238BF18) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e454
	ctx.lr = 0x8238BF20;
	__restfpr_23(ctx, base);
	// li r10,6
	ctx.r10.s64 = 6;
	// addi r9,r4,4
	ctx.r9.s64 = ctx.r4.s64 + 4;
	// li r11,16
	ctx.r11.s64 = 16;
	// li r8,48
	ctx.r8.s64 = 48;
	// li r30,32
	ctx.r30.s64 = 32;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r31,80
	ctx.r31.s64 = 80;
	// li r4,64
	ctx.r4.s64 = 64;
	// li r5,112
	ctx.r5.s64 = 112;
	// li r6,96
	ctx.r6.s64 = 96;
	// li r29,8
	ctx.r29.s64 = 8;
loc_8238BF4C:
	// lvlx128 v63,r11,r3
	temp.u32 = ctx.r11.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v63,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lvlx128 v62,r0,r3
	temp.u32 = ctx.r0.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lwz r11,4(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lvlx128 v61,r8,r3
	temp.u32 = ctx.r8.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v61,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// lvlx128 v60,r30,r3
	temp.u32 = ctx.r30.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vpkshus128 v63,v62,v63
	simd::store_i8(ctx.v63.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v63.s16), simd::load_i16(ctx.v62.s16)));
	// lvlx128 v59,r31,r3
	temp.u32 = ctx.r31.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v59,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lvlx128 v58,r4,r3
	temp.u32 = ctx.r4.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vpkshus128 v62,v60,v61
	simd::store_i8(ctx.v62.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v61.s16), simd::load_i16(ctx.v60.s16)));
	// lvlx128 v57,r5,r3
	temp.u32 = ctx.r5.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v56,r6,r3
	temp.u32 = ctx.r6.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vpkshus128 v61,v58,v59
	simd::store_i8(ctx.v61.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v59.s16), simd::load_i16(ctx.v58.s16)));
	// vsldoi128 v59,v63,v63,8
	simd::store_i8(ctx.v59.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v63.u8), 8));
	// vpkshus128 v60,v56,v57
	simd::store_i8(ctx.v60.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v57.s16), simd::load_i16(ctx.v56.s16)));
	// vsldoi128 v58,v62,v62,8
	simd::store_i8(ctx.v58.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v62.u8), simd::load_i8(ctx.v62.u8), 8));
	// vsldoi128 v57,v61,v61,8
	simd::store_i8(ctx.v57.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v61.u8), simd::load_i8(ctx.v61.u8), 8));
	// vsldoi128 v56,v60,v60,8
	simd::store_i8(ctx.v56.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v60.u8), 8));
	// bne cr6,0x8238c00c
	if (!ctx.cr6.eq) goto loc_8238C00C;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stvrx128 v59,r10,r29
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r29.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v59), i));
}
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r27,r8,8
	ctx.r27.s64 = ctx.r8.s64 + 8;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r11,4
	ctx.r28.s64 = ctx.r11.s64 + 4;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r26,r11,8
	ctx.r26.s64 = ctx.r11.s64 + 8;
	// addi r25,r11,2
	ctx.r25.s64 = ctx.r11.s64 + 2;
	// rlwinm r24,r11,3,0,28
	ctx.r24.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r23,r8,8
	ctx.r23.s64 = ctx.r8.s64 + 8;
	// rlwinm r28,r28,1,0,30
	ctx.r28.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// stvrx128 v63,r10,r26
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r26.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v63), i));
}
	// rlwinm r7,r25,2,0,29
	ctx.r7.u64 = rotl64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r11,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r11.s64;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stvrx128 v58,r10,r28
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r28.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v58), i));
}
	// stvrx128 v62,r10,r27
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r27.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v62), i));
}
	// stvrx128 v57,r10,r7
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v57), i));
}
	// stvrx128 v61,r10,r23
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r23.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v61), i));
}
	// stvrx128 v56,r10,r8
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v56), i));
}
	// stvrx128 v60,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v60), i));
}
	// b 0x8238c054
	goto loc_8238C054;
loc_8238C00C:
	// rlwinm r28,r11,1,0,30
	ctx.r28.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stvlx128 v63,r0,r10
{
	uint32_t addr = 
ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v63), 15 - i));
}
	// add r27,r11,r8
	ctx.r27.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stvlx128 v59,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v59), 15 - i));
}
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stvlx128 v62,r10,r28
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r28.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v62), 15 - i));
}
	// rlwinm r26,r11,2,0,29
	ctx.r26.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r28,r11,3,0,28
	ctx.r28.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stvlx128 v58,r10,r27
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r27.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v58), 15 - i));
}
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r11,r28
	ctx.r11.s64 = ctx.r28.s64 - ctx.r11.s64;
	// stvlx128 v61,r10,r26
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r26.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v61), 15 - i));
}
	// stvlx128 v57,r10,r7
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v57), 15 - i));
}
	// stvlx128 v60,r10,r8
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v60), 15 - i));
}
	// stvlx128 v56,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v56), 15 - i));
}
loc_8238C054:
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// li r11,16
	ctx.r11.s64 = 16;
	// li r8,48
	ctx.r8.s64 = 48;
	// bdnz 0x8238bf4c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8238BF4C;
	// b 0x8233e4a4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238C06C"))) PPC_WEAK_FUNC(sub_8238C06C);
PPC_FUNC_IMPL(__imp__sub_8238C06C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238C070"))) PPC_WEAK_FUNC(sub_8238C070);
PPC_FUNC_IMPL(__imp__sub_8238C070) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e448
	ctx.lr = 0x8238C078;
	__restfpr_20(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// addi r26,r4,4
	ctx.r26.s64 = ctx.r4.s64 + 4;
	// li r27,16
	ctx.r27.s64 = 16;
	// li r28,48
	ctx.r28.s64 = 48;
	// li r29,32
	ctx.r29.s64 = 32;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r30,80
	ctx.r30.s64 = 80;
	// li r31,64
	ctx.r31.s64 = 64;
	// li r4,112
	ctx.r4.s64 = 112;
	// li r5,96
	ctx.r5.s64 = 96;
	// li r7,8
	ctx.r7.s64 = 8;
loc_8238C0A4:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lwz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 4);
	// bge cr6,0x8238c100
	if (!ctx.cr6.lt) goto loc_8238C100;
	// dcbzl r0,r10
	memset(base + ((ctx.r10.u32) & ~127), 0, 128);
	// dcbzl r11,r10
	memset(base + ((ctx.r11.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbzl r9,r10
	memset(base + ((ctx.r9.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 + ctx.r9.u64;
	// dcbzl r8,r10
	memset(base + ((ctx.r8.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbzl r9,r10
	memset(base + ((ctx.r9.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 + ctx.r9.u64;
	// dcbzl r8,r10
	memset(base + ((ctx.r8.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbzl r8,r10
	memset(base + ((ctx.r8.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r8,r11,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r11.s64;
	// dcbzl r8,r10
	memset(base + ((ctx.r8.u32 + ctx.r10.u32) & ~127), 0, 128);
loc_8238C100:
	// lvlx128 v62,r27,r3
	temp.u32 = ctx.r27.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// clrlwi r9,r10,28
	ctx.r9.u64 = ctx.r10.u32 & 0xF;
	// lvlx128 v63,r0,r3
	temp.u32 = ctx.r0.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v63,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = rotl64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v61,r28,r3
	temp.u32 = ctx.r28.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v61,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lvlx128 v60,r29,r3
	temp.u32 = ctx.r29.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vpkshus128 v63,v63,v62
	simd::store_i8(ctx.v63.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v62.s16), simd::load_i16(ctx.v63.s16)));
	// lvlx128 v59,r30,r3
	temp.u32 = ctx.r30.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v59,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v58,r31,r3
	temp.u32 = ctx.r31.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vpkshus128 v62,v60,v61
	simd::store_i8(ctx.v62.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v61.s16), simd::load_i16(ctx.v60.s16)));
	// lvlx128 v57,r4,r3
	temp.u32 = ctx.r4.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v56,r5,r3
	temp.u32 = ctx.r5.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vpkshus128 v61,v58,v59
	simd::store_i8(ctx.v61.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v59.s16), simd::load_i16(ctx.v58.s16)));
	// vsldoi128 v59,v63,v63,8
	simd::store_i8(ctx.v59.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v63.u8), 8));
	// vpkshus128 v60,v56,v57
	simd::store_i8(ctx.v60.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v57.s16), simd::load_i16(ctx.v56.s16)));
	// vsldoi128 v58,v62,v62,8
	simd::store_i8(ctx.v58.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v62.u8), simd::load_i8(ctx.v62.u8), 8));
	// vsldoi128 v57,v61,v61,8
	simd::store_i8(ctx.v57.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v61.u8), simd::load_i8(ctx.v61.u8), 8));
	// vsldoi128 v56,v60,v60,8
	simd::store_i8(ctx.v56.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v60.u8), 8));
	// bne cr6,0x8238c1bc
	if (!ctx.cr6.eq) goto loc_8238C1BC;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stvrx128 v59,r10,r7
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v59), i));
}
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r24,r9,8
	ctx.r24.s64 = ctx.r9.s64 + 8;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r25,r11,4
	ctx.r25.s64 = ctx.r11.s64 + 4;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// addi r23,r11,8
	ctx.r23.s64 = ctx.r11.s64 + 8;
	// addi r22,r11,2
	ctx.r22.s64 = ctx.r11.s64 + 2;
	// rlwinm r21,r11,3,0,28
	ctx.r21.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r20,r9,8
	ctx.r20.s64 = ctx.r9.s64 + 8;
	// rlwinm r25,r25,1,0,30
	ctx.r25.u64 = rotl64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r8,1,0,30
	ctx.r9.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// stvrx128 v63,r10,r23
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r23.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v63), i));
}
	// rlwinm r8,r22,2,0,29
	ctx.r8.u64 = rotl64(ctx.r22.u32 | (ctx.r22.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r11,r21
	ctx.r11.s64 = ctx.r21.s64 - ctx.r11.s64;
	// addi r9,r9,8
	ctx.r9.s64 = ctx.r9.s64 + 8;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stvrx128 v58,r10,r25
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r25.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v58), i));
}
	// stvrx128 v62,r10,r24
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r24.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v62), i));
}
	// stvrx128 v57,r10,r8
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v57), i));
}
	// stvrx128 v61,r10,r20
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r20.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v61), i));
}
	// stvrx128 v56,r10,r9
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r9.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v56), i));
}
	// stvrx128 v60,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v60), i));
}
	// b 0x8238c204
	goto loc_8238C204;
loc_8238C1BC:
	// rlwinm r25,r11,1,0,30
	ctx.r25.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stvlx128 v63,r0,r10
{
	uint32_t addr = 
ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v63), 15 - i));
}
	// add r24,r11,r9
	ctx.r24.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stvlx128 v59,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v59), 15 - i));
}
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stvlx128 v62,r10,r25
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r25.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v62), 15 - i));
}
	// rlwinm r23,r11,2,0,29
	ctx.r23.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r25,r11,3,0,28
	ctx.r25.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stvlx128 v58,r10,r24
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r24.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v58), 15 - i));
}
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r11,r25
	ctx.r11.s64 = ctx.r25.s64 - ctx.r11.s64;
	// stvlx128 v61,r10,r23
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r23.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v61), 15 - i));
}
	// stvlx128 v57,r10,r8
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v57), 15 - i));
}
	// stvlx128 v60,r10,r9
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r9.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v60), 15 - i));
}
	// stvlx128 v56,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v56), 15 - i));
}
loc_8238C204:
	// addi r3,r3,128
	ctx.r3.s64 = ctx.r3.s64 + 128;
	// addi r26,r26,8
	ctx.r26.s64 = ctx.r26.s64 + 8;
	// bdnz 0x8238c0a4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8238C0A4;
	// b 0x8233e498
	__restgprlr_20(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238C214"))) PPC_WEAK_FUNC(sub_8238C214);
PPC_FUNC_IMPL(__imp__sub_8238C214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238C218"))) PPC_WEAK_FUNC(sub_8238C218);
PPC_FUNC_IMPL(__imp__sub_8238C218) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e444
	ctx.lr = 0x8238C220;
	__restfpr_19(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r7,16
	ctx.r7.s64 = 16;
	// vspltisw v10,0
	simd::store_i32(ctx.v10.u32, simd::set1_i32(int32_t(0x0)));
	// li r6,32
	ctx.r6.s64 = 32;
	// li r4,48
	ctx.r4.s64 = 48;
	// addi r30,r10,4
	ctx.r30.s64 = ctx.r10.s64 + 4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r25,80
	ctx.r25.s64 = 80;
	// li r26,64
	ctx.r26.s64 = 64;
	// li r27,112
	ctx.r27.s64 = 112;
	// li r28,96
	ctx.r28.s64 = 96;
	// li r29,8
	ctx.r29.s64 = 8;
loc_8238C25C:
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lvlx v0,0,r8
	temp.u32 = ctx.r0.u32 + ctx.r8.u32;
	simd::store_shuffled(ctx.v0,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lwz r11,4(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lvlx v13,r7,r8
	temp.u32 = ctx.r7.u32 + ctx.r8.u32;
	simd::store_shuffled(ctx.v13,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v12,r6,r8
	temp.u32 = ctx.r6.u32 + ctx.r8.u32;
	simd::store_shuffled(ctx.v12,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lvlx v11,r4,r8
	temp.u32 = ctx.r4.u32 + ctx.r8.u32;
	simd::store_shuffled(ctx.v11,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// bge cr6,0x8238c2ec
	if (!ctx.cr6.lt) goto loc_8238C2EC;
	// vmrglb v9,v10,v0
	simd::store_i8(ctx.v9.u8, simd::unpacklo_i8(simd::load_i8(ctx.v0.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v8,r7,r9
	temp.u32 = ctx.r7.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v8,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v7,v10,v0
	simd::store_i8(ctx.v7.u8, simd::unpackhi_i8(simd::load_i8(ctx.v0.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v6,0,r9
	temp.u32 = ctx.r0.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v6,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrglb v5,v10,v13
	simd::store_i8(ctx.v5.u8, simd::unpacklo_i8(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v4,r4,r9
	temp.u32 = ctx.r4.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v4,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v3,v10,v13
	simd::store_i8(ctx.v3.u8, simd::unpackhi_i8(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v2,r6,r9
	temp.u32 = ctx.r6.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v2,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrglb v1,v10,v12
	simd::store_i8(ctx.v1.u8, simd::unpacklo_i8(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v31,r25,r9
	temp.u32 = ctx.r25.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v31,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v30,v10,v12
	simd::store_i8(ctx.v30.u8, simd::unpackhi_i8(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v29,r26,r9
	temp.u32 = ctx.r26.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v29,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrglb v28,v10,v11
	simd::store_i8(ctx.v28.u8, simd::unpacklo_i8(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v27,r27,r9
	temp.u32 = ctx.r27.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v27,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v26,v10,v11
	simd::store_i8(ctx.v26.u8, simd::unpackhi_i8(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v25,r28,r9
	temp.u32 = ctx.r28.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v25,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vaddshs v24,v9,v8
	simd::store_i16(ctx.v24.s16, simd::add_saturate_i16(simd::load_i16(ctx.v9.s16), simd::load_i16(ctx.v8.s16)));
	// vaddshs v23,v7,v6
	simd::store_i16(ctx.v23.s16, simd::add_saturate_i16(simd::load_i16(ctx.v7.s16), simd::load_i16(ctx.v6.s16)));
	// vaddshs v22,v5,v4
	simd::store_i16(ctx.v22.s16, simd::add_saturate_i16(simd::load_i16(ctx.v5.s16), simd::load_i16(ctx.v4.s16)));
	// vaddshs v21,v3,v2
	simd::store_i16(ctx.v21.s16, simd::add_saturate_i16(simd::load_i16(ctx.v3.s16), simd::load_i16(ctx.v2.s16)));
	// vaddshs v20,v1,v31
	simd::store_i16(ctx.v20.s16, simd::add_saturate_i16(simd::load_i16(ctx.v1.s16), simd::load_i16(ctx.v31.s16)));
	// vaddshs v19,v30,v29
	simd::store_i16(ctx.v19.s16, simd::add_saturate_i16(simd::load_i16(ctx.v30.s16), simd::load_i16(ctx.v29.s16)));
	// vpkshus v0,v23,v24
	simd::store_i8(ctx.v0.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v24.s16), simd::load_i16(ctx.v23.s16)));
	// vaddshs v18,v28,v27
	simd::store_i16(ctx.v18.s16, simd::add_saturate_i16(simd::load_i16(ctx.v28.s16), simd::load_i16(ctx.v27.s16)));
	// vaddshs v17,v26,v25
	simd::store_i16(ctx.v17.s16, simd::add_saturate_i16(simd::load_i16(ctx.v26.s16), simd::load_i16(ctx.v25.s16)));
	// vpkshus v13,v21,v22
	simd::store_i8(ctx.v13.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v22.s16), simd::load_i16(ctx.v21.s16)));
	// vpkshus v12,v19,v20
	simd::store_i8(ctx.v12.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v20.s16), simd::load_i16(ctx.v19.s16)));
	// vpkshus v11,v17,v18
	simd::store_i8(ctx.v11.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v18.s16), simd::load_i16(ctx.v17.s16)));
loc_8238C2EC:
	// clrlwi r3,r10,28
	ctx.r3.u64 = ctx.r10.u32 & 0xF;
	// vsldoi128 v63,v0,v0,8
	simd::store_i8(ctx.v63.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v0.u8), simd::load_i8(ctx.v0.u8), 8));
	// vsldoi128 v62,v13,v13,8
	simd::store_i8(ctx.v62.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v13.u8), 8));
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// vsldoi128 v61,v12,v12,8
	simd::store_i8(ctx.v61.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v12.u8), 8));
	// vsldoi128 v60,v11,v11,8
	simd::store_i8(ctx.v60.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v11.u8), 8));
	// rlwinm r3,r11,1,0,30
	ctx.r3.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bne cr6,0x8238c374
	if (!ctx.cr6.eq) goto loc_8238C374;
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stvrx128 v63,r10,r29
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r29.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v63), i));
}
	// rlwinm r31,r11,1,0,30
	ctx.r31.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r23,r3,8
	ctx.r23.s64 = ctx.r3.s64 + 8;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r24,r11,4
	ctx.r24.s64 = ctx.r11.s64 + 4;
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r22,r11,8
	ctx.r22.s64 = ctx.r11.s64 + 8;
	// addi r21,r11,2
	ctx.r21.s64 = ctx.r11.s64 + 2;
	// rlwinm r20,r11,3,0,28
	ctx.r20.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r19,r3,8
	ctx.r19.s64 = ctx.r3.s64 + 8;
	// rlwinm r24,r24,1,0,30
	ctx.r24.u64 = rotl64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r3,r31,1,0,30
	ctx.r3.u64 = rotl64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// stvrx v0,r10,r22
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r22.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v0), i));
}
	// rlwinm r31,r21,2,0,29
	ctx.r31.u64 = rotl64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r11,r20
	ctx.r11.s64 = ctx.r20.s64 - ctx.r11.s64;
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stvrx128 v62,r10,r24
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r24.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v62), i));
}
	// stvrx v13,r10,r23
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r23.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v13), i));
}
	// stvrx128 v61,r10,r31
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r31.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v61), i));
}
	// stvrx v12,r10,r19
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r19.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v12), i));
}
	// stvrx128 v60,r10,r3
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r3.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v60), i));
}
	// stvrx v11,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v11), i));
}
	// b 0x8238c3bc
	goto loc_8238C3BC;
loc_8238C374:
	// rlwinm r24,r11,1,0,30
	ctx.r24.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stvlx v0,0,r10
{
	uint32_t addr = 
ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v0), 15 - i));
}
	// add r23,r11,r3
	ctx.r23.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stvlx128 v63,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v63), 15 - i));
}
	// rlwinm r3,r11,1,0,30
	ctx.r3.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r31,r11,2,0,29
	ctx.r31.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stvlx v13,r10,r24
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r24.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v13), 15 - i));
}
	// rlwinm r22,r11,2,0,29
	ctx.r22.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r24,r11,3,0,28
	ctx.r24.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stvlx128 v62,r10,r23
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r23.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v62), 15 - i));
}
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r11,r24
	ctx.r11.s64 = ctx.r24.s64 - ctx.r11.s64;
	// stvlx v12,r10,r22
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r22.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v12), 15 - i));
}
	// stvlx128 v61,r10,r31
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r31.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v61), 15 - i));
}
	// stvlx v11,r10,r3
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r3.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v11), 15 - i));
}
	// stvlx128 v60,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v60), 15 - i));
}
loc_8238C3BC:
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// addi r8,r8,64
	ctx.r8.s64 = ctx.r8.s64 + 64;
	// rlwinm r5,r5,1,0,30
	ctx.r5.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// bdnz 0x8238c25c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8238C25C;
	// b 0x8233e494
	__restgprlr_19(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238C3D4"))) PPC_WEAK_FUNC(sub_8238C3D4);
PPC_FUNC_IMPL(__imp__sub_8238C3D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238C3D8"))) PPC_WEAK_FUNC(sub_8238C3D8);
PPC_FUNC_IMPL(__imp__sub_8238C3D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e440
	ctx.lr = 0x8238C3E0;
	__restfpr_18(ctx, base);
	// li r11,6
	ctx.r11.s64 = 6;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// addi r29,r4,4
	ctx.r29.s64 = ctx.r4.s64 + 4;
	// lwz r4,8(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// vspltisw v10,0
	simd::store_i32(ctx.v10.u32, simd::set1_i32(int32_t(0x0)));
	// li r30,16
	ctx.r30.s64 = 16;
	// li r31,32
	ctx.r31.s64 = 32;
	// li r3,48
	ctx.r3.s64 = 48;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// li r24,80
	ctx.r24.s64 = 80;
	// li r25,64
	ctx.r25.s64 = 64;
	// li r26,112
	ctx.r26.s64 = 112;
	// li r27,96
	ctx.r27.s64 = 96;
	// li r28,8
	ctx.r28.s64 = 8;
loc_8238C418:
	// lwz r10,0(r29)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r29.u32 + 0);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lwz r11,4(r29)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + 4);
	// bge cr6,0x8238c474
	if (!ctx.cr6.lt) goto loc_8238C474;
	// dcbzl r0,r10
	memset(base + ((ctx.r10.u32) & ~127), 0, 128);
	// dcbzl r11,r10
	memset(base + ((ctx.r11.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbzl r8,r10
	memset(base + ((ctx.r8.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r8
	ctx.r7.u64 = ctx.r11.u64 + ctx.r8.u64;
	// dcbzl r7,r10
	memset(base + ((ctx.r7.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbzl r8,r10
	memset(base + ((ctx.r8.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r8
	ctx.r7.u64 = ctx.r11.u64 + ctx.r8.u64;
	// dcbzl r7,r10
	memset(base + ((ctx.r7.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbzl r7,r10
	memset(base + ((ctx.r7.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// dcbzl r7,r10
	memset(base + ((ctx.r7.u32 + ctx.r10.u32) & ~127), 0, 128);
loc_8238C474:
	// lvlx v0,0,r4
	temp.u32 = ctx.r0.u32 + ctx.r4.u32;
	simd::store_shuffled(ctx.v0,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = rotl64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx v13,r30,r4
	temp.u32 = ctx.r30.u32 + ctx.r4.u32;
	simd::store_shuffled(ctx.v13,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lvlx v12,r31,r4
	temp.u32 = ctx.r31.u32 + ctx.r4.u32;
	simd::store_shuffled(ctx.v12,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v11,r3,r4
	temp.u32 = ctx.r3.u32 + ctx.r4.u32;
	simd::store_shuffled(ctx.v11,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// bge cr6,0x8238c500
	if (!ctx.cr6.lt) goto loc_8238C500;
	// vmrglb v9,v10,v0
	simd::store_i8(ctx.v9.u8, simd::unpacklo_i8(simd::load_i8(ctx.v0.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v8,r30,r9
	temp.u32 = ctx.r30.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v8,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v7,v10,v0
	simd::store_i8(ctx.v7.u8, simd::unpackhi_i8(simd::load_i8(ctx.v0.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v6,0,r9
	temp.u32 = ctx.r0.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v6,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrglb v5,v10,v13
	simd::store_i8(ctx.v5.u8, simd::unpacklo_i8(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v4,r3,r9
	temp.u32 = ctx.r3.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v4,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v3,v10,v13
	simd::store_i8(ctx.v3.u8, simd::unpackhi_i8(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v2,r31,r9
	temp.u32 = ctx.r31.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v2,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrglb v1,v10,v12
	simd::store_i8(ctx.v1.u8, simd::unpacklo_i8(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v31,r24,r9
	temp.u32 = ctx.r24.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v31,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v30,v10,v12
	simd::store_i8(ctx.v30.u8, simd::unpackhi_i8(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v29,r25,r9
	temp.u32 = ctx.r25.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v29,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrglb v28,v10,v11
	simd::store_i8(ctx.v28.u8, simd::unpacklo_i8(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v27,r26,r9
	temp.u32 = ctx.r26.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v27,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v26,v10,v11
	simd::store_i8(ctx.v26.u8, simd::unpackhi_i8(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v25,r27,r9
	temp.u32 = ctx.r27.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v25,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vaddshs v24,v9,v8
	simd::store_i16(ctx.v24.s16, simd::add_saturate_i16(simd::load_i16(ctx.v9.s16), simd::load_i16(ctx.v8.s16)));
	// vaddshs v23,v7,v6
	simd::store_i16(ctx.v23.s16, simd::add_saturate_i16(simd::load_i16(ctx.v7.s16), simd::load_i16(ctx.v6.s16)));
	// vaddshs v22,v5,v4
	simd::store_i16(ctx.v22.s16, simd::add_saturate_i16(simd::load_i16(ctx.v5.s16), simd::load_i16(ctx.v4.s16)));
	// vaddshs v21,v3,v2
	simd::store_i16(ctx.v21.s16, simd::add_saturate_i16(simd::load_i16(ctx.v3.s16), simd::load_i16(ctx.v2.s16)));
	// vaddshs v20,v1,v31
	simd::store_i16(ctx.v20.s16, simd::add_saturate_i16(simd::load_i16(ctx.v1.s16), simd::load_i16(ctx.v31.s16)));
	// vaddshs v19,v30,v29
	simd::store_i16(ctx.v19.s16, simd::add_saturate_i16(simd::load_i16(ctx.v30.s16), simd::load_i16(ctx.v29.s16)));
	// vpkshus v0,v23,v24
	simd::store_i8(ctx.v0.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v24.s16), simd::load_i16(ctx.v23.s16)));
	// vaddshs v18,v28,v27
	simd::store_i16(ctx.v18.s16, simd::add_saturate_i16(simd::load_i16(ctx.v28.s16), simd::load_i16(ctx.v27.s16)));
	// vaddshs v17,v26,v25
	simd::store_i16(ctx.v17.s16, simd::add_saturate_i16(simd::load_i16(ctx.v26.s16), simd::load_i16(ctx.v25.s16)));
	// vpkshus v13,v21,v22
	simd::store_i8(ctx.v13.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v22.s16), simd::load_i16(ctx.v21.s16)));
	// vpkshus v12,v19,v20
	simd::store_i8(ctx.v12.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v20.s16), simd::load_i16(ctx.v19.s16)));
	// vpkshus v11,v17,v18
	simd::store_i8(ctx.v11.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v18.s16), simd::load_i16(ctx.v17.s16)));
loc_8238C500:
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// vsldoi128 v63,v0,v0,8
	simd::store_i8(ctx.v63.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v0.u8), simd::load_i8(ctx.v0.u8), 8));
	// vsldoi128 v62,v13,v13,8
	simd::store_i8(ctx.v62.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v13.u8), 8));
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// vsldoi128 v61,v12,v12,8
	simd::store_i8(ctx.v61.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v12.u8), 8));
	// vsldoi128 v60,v11,v11,8
	simd::store_i8(ctx.v60.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v11.u8), 8));
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bne cr6,0x8238c588
	if (!ctx.cr6.eq) goto loc_8238C588;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stvrx128 v63,r10,r28
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r28.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v63), i));
}
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r22,r8,8
	ctx.r22.s64 = ctx.r8.s64 + 8;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r23,r11,4
	ctx.r23.s64 = ctx.r11.s64 + 4;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r21,r11,8
	ctx.r21.s64 = ctx.r11.s64 + 8;
	// addi r20,r11,2
	ctx.r20.s64 = ctx.r11.s64 + 2;
	// rlwinm r19,r11,3,0,28
	ctx.r19.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r18,r8,8
	ctx.r18.s64 = ctx.r8.s64 + 8;
	// rlwinm r23,r23,1,0,30
	ctx.r23.u64 = rotl64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// stvrx v0,r10,r21
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r21.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v0), i));
}
	// rlwinm r7,r20,2,0,29
	ctx.r7.u64 = rotl64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r11,r19
	ctx.r11.s64 = ctx.r19.s64 - ctx.r11.s64;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stvrx128 v62,r10,r23
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r23.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v62), i));
}
	// stvrx v13,r10,r22
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r22.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v13), i));
}
	// stvrx128 v61,r10,r7
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v61), i));
}
	// stvrx v12,r10,r18
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r18.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v12), i));
}
	// stvrx128 v60,r10,r8
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v60), i));
}
	// stvrx v11,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v11), i));
}
	// b 0x8238c5d0
	goto loc_8238C5D0;
loc_8238C588:
	// rlwinm r23,r11,1,0,30
	ctx.r23.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stvlx v0,0,r10
{
	uint32_t addr = 
ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v0), 15 - i));
}
	// add r22,r11,r8
	ctx.r22.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stvlx128 v63,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v63), 15 - i));
}
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stvlx v13,r10,r23
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r23.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v13), 15 - i));
}
	// rlwinm r21,r11,2,0,29
	ctx.r21.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r23,r11,3,0,28
	ctx.r23.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stvlx128 v62,r10,r22
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r22.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v62), 15 - i));
}
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r11,r23
	ctx.r11.s64 = ctx.r23.s64 - ctx.r11.s64;
	// stvlx v12,r10,r21
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r21.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v12), 15 - i));
}
	// stvlx128 v61,r10,r7
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v61), 15 - i));
}
	// stvlx v11,r10,r8
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v11), 15 - i));
}
	// stvlx128 v60,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v60), 15 - i));
}
loc_8238C5D0:
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// addi r4,r4,64
	ctx.r4.s64 = ctx.r4.s64 + 64;
	// rlwinm r5,r5,1,0,30
	ctx.r5.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// bdnz 0x8238c418
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8238C418;
	// b 0x8233e490
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238C5E8"))) PPC_WEAK_FUNC(sub_8238C5E8);
PPC_FUNC_IMPL(__imp__sub_8238C5E8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e440
	ctx.lr = 0x8238C5F0;
	__restfpr_18(ctx, base);
	// lwz r8,8(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,6
	ctx.r11.s64 = 6;
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r10,r4,4
	ctx.r10.s64 = ctx.r4.s64 + 4;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// vspltisw v10,0
	simd::store_i32(ctx.v10.u32, simd::set1_i32(int32_t(0x0)));
	// subf r7,r8,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r8.s64;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// li r29,16
	ctx.r29.s64 = 16;
	// li r30,32
	ctx.r30.s64 = 32;
	// li r31,48
	ctx.r31.s64 = 48;
	// li r24,80
	ctx.r24.s64 = 80;
	// li r25,64
	ctx.r25.s64 = 64;
	// li r26,112
	ctx.r26.s64 = 112;
	// li r27,96
	ctx.r27.s64 = 96;
	// li r28,8
	ctx.r28.s64 = 8;
loc_8238C638:
	// lvlx v13,0,r8
	temp.u32 = ctx.r0.u32 + ctx.r8.u32;
	simd::store_shuffled(ctx.v13,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lwz r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// lvlx v0,0,r7
	temp.u32 = ctx.r0.u32 + ctx.r7.u32;
	simd::store_shuffled(ctx.v0,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lwz r11,4(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// lvlx v12,r29,r7
	temp.u32 = ctx.r29.u32 + ctx.r7.u32;
	simd::store_shuffled(ctx.v12,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vavgub v0,v13,v0
	simd::store_u8(ctx.v0.u8, simd::avg_u8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v0.u8)));
	// lvlx v11,r29,r8
	temp.u32 = ctx.r29.u32 + ctx.r8.u32;
	simd::store_shuffled(ctx.v11,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lvlx v9,r30,r7
	temp.u32 = ctx.r30.u32 + ctx.r7.u32;
	simd::store_shuffled(ctx.v9,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vavgub v13,v11,v12
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v11.u8), simd::load_u8(ctx.v12.u8)));
	// lvlx v8,r30,r8
	temp.u32 = ctx.r30.u32 + ctx.r8.u32;
	simd::store_shuffled(ctx.v8,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v7,r31,r7
	temp.u32 = ctx.r31.u32 + ctx.r7.u32;
	simd::store_shuffled(ctx.v7,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vavgub v12,v8,v9
	simd::store_u8(ctx.v12.u8, simd::avg_u8(simd::load_u8(ctx.v8.u8), simd::load_u8(ctx.v9.u8)));
	// lvlx v6,r31,r8
	temp.u32 = ctx.r31.u32 + ctx.r8.u32;
	simd::store_shuffled(ctx.v6,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vavgub v11,v6,v7
	simd::store_u8(ctx.v11.u8, simd::avg_u8(simd::load_u8(ctx.v6.u8), simd::load_u8(ctx.v7.u8)));
	// bge cr6,0x8238c6e8
	if (!ctx.cr6.lt) goto loc_8238C6E8;
	// vmrglb v9,v10,v0
	simd::store_i8(ctx.v9.u8, simd::unpacklo_i8(simd::load_i8(ctx.v0.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v8,r29,r9
	temp.u32 = ctx.r29.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v8,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v7,v10,v0
	simd::store_i8(ctx.v7.u8, simd::unpackhi_i8(simd::load_i8(ctx.v0.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v6,0,r9
	temp.u32 = ctx.r0.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v6,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrglb v5,v10,v13
	simd::store_i8(ctx.v5.u8, simd::unpacklo_i8(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v4,r31,r9
	temp.u32 = ctx.r31.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v4,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v3,v10,v13
	simd::store_i8(ctx.v3.u8, simd::unpackhi_i8(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v2,r30,r9
	temp.u32 = ctx.r30.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v2,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrglb v1,v10,v12
	simd::store_i8(ctx.v1.u8, simd::unpacklo_i8(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v31,r24,r9
	temp.u32 = ctx.r24.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v31,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v30,v10,v12
	simd::store_i8(ctx.v30.u8, simd::unpackhi_i8(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v29,r25,r9
	temp.u32 = ctx.r25.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v29,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrglb v28,v10,v11
	simd::store_i8(ctx.v28.u8, simd::unpacklo_i8(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v27,r26,r9
	temp.u32 = ctx.r26.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v27,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v26,v10,v11
	simd::store_i8(ctx.v26.u8, simd::unpackhi_i8(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v25,r27,r9
	temp.u32 = ctx.r27.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v25,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vaddshs v24,v9,v8
	simd::store_i16(ctx.v24.s16, simd::add_saturate_i16(simd::load_i16(ctx.v9.s16), simd::load_i16(ctx.v8.s16)));
	// vaddshs v23,v7,v6
	simd::store_i16(ctx.v23.s16, simd::add_saturate_i16(simd::load_i16(ctx.v7.s16), simd::load_i16(ctx.v6.s16)));
	// vaddshs v22,v5,v4
	simd::store_i16(ctx.v22.s16, simd::add_saturate_i16(simd::load_i16(ctx.v5.s16), simd::load_i16(ctx.v4.s16)));
	// vaddshs v21,v3,v2
	simd::store_i16(ctx.v21.s16, simd::add_saturate_i16(simd::load_i16(ctx.v3.s16), simd::load_i16(ctx.v2.s16)));
	// vaddshs v20,v1,v31
	simd::store_i16(ctx.v20.s16, simd::add_saturate_i16(simd::load_i16(ctx.v1.s16), simd::load_i16(ctx.v31.s16)));
	// vaddshs v19,v30,v29
	simd::store_i16(ctx.v19.s16, simd::add_saturate_i16(simd::load_i16(ctx.v30.s16), simd::load_i16(ctx.v29.s16)));
	// vpkshus v0,v23,v24
	simd::store_i8(ctx.v0.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v24.s16), simd::load_i16(ctx.v23.s16)));
	// vaddshs v18,v28,v27
	simd::store_i16(ctx.v18.s16, simd::add_saturate_i16(simd::load_i16(ctx.v28.s16), simd::load_i16(ctx.v27.s16)));
	// vaddshs v17,v26,v25
	simd::store_i16(ctx.v17.s16, simd::add_saturate_i16(simd::load_i16(ctx.v26.s16), simd::load_i16(ctx.v25.s16)));
	// vpkshus v13,v21,v22
	simd::store_i8(ctx.v13.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v22.s16), simd::load_i16(ctx.v21.s16)));
	// vpkshus v12,v19,v20
	simd::store_i8(ctx.v12.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v20.s16), simd::load_i16(ctx.v19.s16)));
	// vpkshus v11,v17,v18
	simd::store_i8(ctx.v11.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v18.s16), simd::load_i16(ctx.v17.s16)));
loc_8238C6E8:
	// clrlwi r6,r10,28
	ctx.r6.u64 = ctx.r10.u32 & 0xF;
	// vsldoi128 v63,v0,v0,8
	simd::store_i8(ctx.v63.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v0.u8), simd::load_i8(ctx.v0.u8), 8));
	// vsldoi128 v62,v13,v13,8
	simd::store_i8(ctx.v62.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v13.u8), 8));
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// vsldoi128 v61,v12,v12,8
	simd::store_i8(ctx.v61.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v12.u8), 8));
	// vsldoi128 v60,v11,v11,8
	simd::store_i8(ctx.v60.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v11.u8), 8));
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bne cr6,0x8238c770
	if (!ctx.cr6.eq) goto loc_8238C770;
	// add r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 + ctx.r6.u64;
	// stvrx128 v63,r10,r28
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r28.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v63), i));
}
	// rlwinm r4,r11,1,0,30
	ctx.r4.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r22,r6,8
	ctx.r22.s64 = ctx.r6.s64 + 8;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r23,r11,4
	ctx.r23.s64 = ctx.r11.s64 + 4;
	// add r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 + ctx.r6.u64;
	// add r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r21,r11,8
	ctx.r21.s64 = ctx.r11.s64 + 8;
	// addi r20,r11,2
	ctx.r20.s64 = ctx.r11.s64 + 2;
	// rlwinm r19,r11,3,0,28
	ctx.r19.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r18,r6,8
	ctx.r18.s64 = ctx.r6.s64 + 8;
	// rlwinm r23,r23,1,0,30
	ctx.r23.u64 = rotl64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r4,1,0,30
	ctx.r6.u64 = rotl64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// stvrx v0,r10,r21
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r21.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v0), i));
}
	// rlwinm r4,r20,2,0,29
	ctx.r4.u64 = rotl64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r11,r19
	ctx.r11.s64 = ctx.r19.s64 - ctx.r11.s64;
	// addi r6,r6,8
	ctx.r6.s64 = ctx.r6.s64 + 8;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stvrx128 v62,r10,r23
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r23.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v62), i));
}
	// stvrx v13,r10,r22
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r22.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v13), i));
}
	// stvrx128 v61,r10,r4
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v61), i));
}
	// stvrx v12,r10,r18
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r18.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v12), i));
}
	// stvrx128 v60,r10,r6
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r6.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v60), i));
}
	// stvrx v11,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v11), i));
}
	// b 0x8238c7b8
	goto loc_8238C7B8;
loc_8238C770:
	// rlwinm r23,r11,1,0,30
	ctx.r23.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stvlx v0,0,r10
{
	uint32_t addr = 
ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v0), 15 - i));
}
	// add r22,r11,r6
	ctx.r22.u64 = ctx.r11.u64 + ctx.r6.u64;
	// stvlx128 v63,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v63), 15 - i));
}
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 + ctx.r6.u64;
	// stvlx v13,r10,r23
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r23.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v13), 15 - i));
}
	// rlwinm r21,r11,2,0,29
	ctx.r21.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r23,r11,3,0,28
	ctx.r23.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stvlx128 v62,r10,r22
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r22.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v62), 15 - i));
}
	// add r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 + ctx.r4.u64;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = rotl64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r11,r23
	ctx.r11.s64 = ctx.r23.s64 - ctx.r11.s64;
	// stvlx v12,r10,r21
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r21.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v12), 15 - i));
}
	// stvlx128 v61,r10,r4
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v61), 15 - i));
}
	// stvlx v11,r10,r6
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r6.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v11), 15 - i));
}
	// stvlx128 v60,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v60), 15 - i));
}
loc_8238C7B8:
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// addi r8,r8,64
	ctx.r8.s64 = ctx.r8.s64 + 64;
	// addi r7,r7,64
	ctx.r7.s64 = ctx.r7.s64 + 64;
	// rlwinm r5,r5,1,0,30
	ctx.r5.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// bdnz 0x8238c638
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8238C638;
	// b 0x8233e490
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238C7D4"))) PPC_WEAK_FUNC(sub_8238C7D4);
PPC_FUNC_IMPL(__imp__sub_8238C7D4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238C7D8"))) PPC_WEAK_FUNC(sub_8238C7D8);
PPC_FUNC_IMPL(__imp__sub_8238C7D8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e43c
	ctx.lr = 0x8238C7E0;
	__restfpr_17(ctx, base);
	// lwz r11,8(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// li r10,6
	ctx.r10.s64 = 6;
	// lwz r7,12(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 12);
	// addi r28,r4,4
	ctx.r28.s64 = ctx.r4.s64 + 4;
	// lwz r9,4(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// subf r7,r11,r7
	ctx.r7.s64 = ctx.r7.s64 - ctx.r11.s64;
	// vspltisw v10,0
	simd::store_i32(ctx.v10.u32, simd::set1_i32(int32_t(0x0)));
	// li r29,16
	ctx.r29.s64 = 16;
	// add r3,r7,r11
	ctx.r3.u64 = ctx.r7.u64 + ctx.r11.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r30,32
	ctx.r30.s64 = 32;
	// li r31,48
	ctx.r31.s64 = 48;
	// li r23,80
	ctx.r23.s64 = 80;
	// li r24,64
	ctx.r24.s64 = 64;
	// li r25,112
	ctx.r25.s64 = 112;
	// li r26,96
	ctx.r26.s64 = 96;
	// li r27,8
	ctx.r27.s64 = 8;
loc_8238C828:
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// lwz r11,4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// bge cr6,0x8238c884
	if (!ctx.cr6.lt) goto loc_8238C884;
	// dcbzl r0,r10
	memset(base + ((ctx.r10.u32) & ~127), 0, 128);
	// dcbzl r11,r10
	memset(base + ((ctx.r11.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbzl r8,r10
	memset(base + ((ctx.r8.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r11,r8
	ctx.r7.u64 = ctx.r11.u64 + ctx.r8.u64;
	// dcbzl r7,r10
	memset(base + ((ctx.r7.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbzl r8,r10
	memset(base + ((ctx.r8.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r8
	ctx.r7.u64 = ctx.r11.u64 + ctx.r8.u64;
	// dcbzl r7,r10
	memset(base + ((ctx.r7.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbzl r7,r10
	memset(base + ((ctx.r7.u32 + ctx.r10.u32) & ~127), 0, 128);
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// dcbzl r7,r10
	memset(base + ((ctx.r7.u32 + ctx.r10.u32) & ~127), 0, 128);
loc_8238C884:
	// lvlx v13,0,r4
	temp.u32 = ctx.r0.u32 + ctx.r4.u32;
	simd::store_shuffled(ctx.v13,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = rotl64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx v0,0,r3
	temp.u32 = ctx.r0.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v0,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lvlx v12,r29,r3
	temp.u32 = ctx.r29.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v12,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vavgub v0,v13,v0
	simd::store_u8(ctx.v0.u8, simd::avg_u8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v0.u8)));
	// lvlx v11,r29,r4
	temp.u32 = ctx.r29.u32 + ctx.r4.u32;
	simd::store_shuffled(ctx.v11,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v9,r30,r3
	temp.u32 = ctx.r30.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v9,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vavgub v13,v11,v12
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v11.u8), simd::load_u8(ctx.v12.u8)));
	// lvlx v8,r30,r4
	temp.u32 = ctx.r30.u32 + ctx.r4.u32;
	simd::store_shuffled(ctx.v8,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v7,r31,r3
	temp.u32 = ctx.r31.u32 + ctx.r3.u32;
	simd::store_shuffled(ctx.v7,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vavgub v12,v8,v9
	simd::store_u8(ctx.v12.u8, simd::avg_u8(simd::load_u8(ctx.v8.u8), simd::load_u8(ctx.v9.u8)));
	// lvlx v6,r31,r4
	temp.u32 = ctx.r31.u32 + ctx.r4.u32;
	simd::store_shuffled(ctx.v6,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vavgub v11,v6,v7
	simd::store_u8(ctx.v11.u8, simd::avg_u8(simd::load_u8(ctx.v6.u8), simd::load_u8(ctx.v7.u8)));
	// bge cr6,0x8238c930
	if (!ctx.cr6.lt) goto loc_8238C930;
	// vmrglb v9,v10,v0
	simd::store_i8(ctx.v9.u8, simd::unpacklo_i8(simd::load_i8(ctx.v0.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v8,r29,r9
	temp.u32 = ctx.r29.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v8,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v7,v10,v0
	simd::store_i8(ctx.v7.u8, simd::unpackhi_i8(simd::load_i8(ctx.v0.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v6,0,r9
	temp.u32 = ctx.r0.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v6,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrglb v5,v10,v13
	simd::store_i8(ctx.v5.u8, simd::unpacklo_i8(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v4,r31,r9
	temp.u32 = ctx.r31.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v4,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v3,v10,v13
	simd::store_i8(ctx.v3.u8, simd::unpackhi_i8(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v2,r30,r9
	temp.u32 = ctx.r30.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v2,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrglb v1,v10,v12
	simd::store_i8(ctx.v1.u8, simd::unpacklo_i8(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v31,r23,r9
	temp.u32 = ctx.r23.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v31,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v30,v10,v12
	simd::store_i8(ctx.v30.u8, simd::unpackhi_i8(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v29,r24,r9
	temp.u32 = ctx.r24.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v29,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrglb v28,v10,v11
	simd::store_i8(ctx.v28.u8, simd::unpacklo_i8(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v27,r25,r9
	temp.u32 = ctx.r25.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v27,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vmrghb v26,v10,v11
	simd::store_i8(ctx.v26.u8, simd::unpackhi_i8(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8)));
	// lvlx v25,r26,r9
	temp.u32 = ctx.r26.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v25,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vaddshs v24,v9,v8
	simd::store_i16(ctx.v24.s16, simd::add_saturate_i16(simd::load_i16(ctx.v9.s16), simd::load_i16(ctx.v8.s16)));
	// vaddshs v23,v7,v6
	simd::store_i16(ctx.v23.s16, simd::add_saturate_i16(simd::load_i16(ctx.v7.s16), simd::load_i16(ctx.v6.s16)));
	// vaddshs v22,v5,v4
	simd::store_i16(ctx.v22.s16, simd::add_saturate_i16(simd::load_i16(ctx.v5.s16), simd::load_i16(ctx.v4.s16)));
	// vaddshs v21,v3,v2
	simd::store_i16(ctx.v21.s16, simd::add_saturate_i16(simd::load_i16(ctx.v3.s16), simd::load_i16(ctx.v2.s16)));
	// vaddshs v20,v1,v31
	simd::store_i16(ctx.v20.s16, simd::add_saturate_i16(simd::load_i16(ctx.v1.s16), simd::load_i16(ctx.v31.s16)));
	// vaddshs v19,v30,v29
	simd::store_i16(ctx.v19.s16, simd::add_saturate_i16(simd::load_i16(ctx.v30.s16), simd::load_i16(ctx.v29.s16)));
	// vpkshus v0,v23,v24
	simd::store_i8(ctx.v0.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v24.s16), simd::load_i16(ctx.v23.s16)));
	// vaddshs v18,v28,v27
	simd::store_i16(ctx.v18.s16, simd::add_saturate_i16(simd::load_i16(ctx.v28.s16), simd::load_i16(ctx.v27.s16)));
	// vaddshs v17,v26,v25
	simd::store_i16(ctx.v17.s16, simd::add_saturate_i16(simd::load_i16(ctx.v26.s16), simd::load_i16(ctx.v25.s16)));
	// vpkshus v13,v21,v22
	simd::store_i8(ctx.v13.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v22.s16), simd::load_i16(ctx.v21.s16)));
	// vpkshus v12,v19,v20
	simd::store_i8(ctx.v12.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v20.s16), simd::load_i16(ctx.v19.s16)));
	// vpkshus v11,v17,v18
	simd::store_i8(ctx.v11.u8, simd::pack_u16_to_i8(simd::load_i16(ctx.v18.s16), simd::load_i16(ctx.v17.s16)));
loc_8238C930:
	// clrlwi r8,r10,28
	ctx.r8.u64 = ctx.r10.u32 & 0xF;
	// vsldoi128 v63,v0,v0,8
	simd::store_i8(ctx.v63.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v0.u8), simd::load_i8(ctx.v0.u8), 8));
	// vsldoi128 v62,v13,v13,8
	simd::store_i8(ctx.v62.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v13.u8), 8));
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// vsldoi128 v61,v12,v12,8
	simd::store_i8(ctx.v61.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v12.u8), 8));
	// vsldoi128 v60,v11,v11,8
	simd::store_i8(ctx.v60.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v11.u8), 8));
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// bne cr6,0x8238c9b8
	if (!ctx.cr6.eq) goto loc_8238C9B8;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stvrx128 v63,r10,r27
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r27.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v63), i));
}
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r21,r8,8
	ctx.r21.s64 = ctx.r8.s64 + 8;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r22,r11,4
	ctx.r22.s64 = ctx.r11.s64 + 4;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r20,r11,8
	ctx.r20.s64 = ctx.r11.s64 + 8;
	// addi r19,r11,2
	ctx.r19.s64 = ctx.r11.s64 + 2;
	// rlwinm r18,r11,3,0,28
	ctx.r18.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r17,r8,8
	ctx.r17.s64 = ctx.r8.s64 + 8;
	// rlwinm r22,r22,1,0,30
	ctx.r22.u64 = rotl64(ctx.r22.u32 | (ctx.r22.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r7,1,0,30
	ctx.r8.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// stvrx v0,r10,r20
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r20.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v0), i));
}
	// rlwinm r7,r19,2,0,29
	ctx.r7.u64 = rotl64(ctx.r19.u32 | (ctx.r19.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r11,r18
	ctx.r11.s64 = ctx.r18.s64 - ctx.r11.s64;
	// addi r8,r8,8
	ctx.r8.s64 = ctx.r8.s64 + 8;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stvrx128 v62,r10,r22
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r22.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v62), i));
}
	// stvrx v13,r10,r21
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r21.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v13), i));
}
	// stvrx128 v61,r10,r7
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v61), i));
}
	// stvrx v12,r10,r17
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r17.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v12), i));
}
	// stvrx128 v60,r10,r8
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v60), i));
}
	// stvrx v11,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < tmp_off; i++)
		PPC_STORE_U8(addr - i - 1, simd::extract_u8(simd::to_vec128i(ctx.v11), i));
}
	// b 0x8238ca00
	goto loc_8238CA00;
loc_8238C9B8:
	// rlwinm r22,r11,1,0,30
	ctx.r22.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stvlx v0,0,r10
{
	uint32_t addr = 
ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v0), 15 - i));
}
	// add r21,r11,r8
	ctx.r21.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stvlx128 v63,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v63), 15 - i));
}
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stvlx v13,r10,r22
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r22.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v13), 15 - i));
}
	// rlwinm r20,r11,2,0,29
	ctx.r20.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r22,r11,3,0,28
	ctx.r22.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stvlx128 v62,r10,r21
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r21.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v62), 15 - i));
}
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r11,r22
	ctx.r11.s64 = ctx.r22.s64 - ctx.r11.s64;
	// stvlx v12,r10,r20
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r20.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v12), 15 - i));
}
	// stvlx128 v61,r10,r7
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v61), 15 - i));
}
	// stvlx v11,r10,r8
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v11), 15 - i));
}
	// stvlx128 v60,r10,r11
{
	uint32_t addr = 
ctx.r10.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v60), 15 - i));
}
loc_8238CA00:
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// addi r4,r4,64
	ctx.r4.s64 = ctx.r4.s64 + 64;
	// addi r3,r3,64
	ctx.r3.s64 = ctx.r3.s64 + 64;
	// rlwinm r5,r5,1,0,30
	ctx.r5.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r28,r28,8
	ctx.r28.s64 = ctx.r28.s64 + 8;
	// bdnz 0x8238c828
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8238C828;
	// b 0x8233e48c
	__restgprlr_17(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238CA1C"))) PPC_WEAK_FUNC(sub_8238CA1C);
PPC_FUNC_IMPL(__imp__sub_8238CA1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238CA20"))) PPC_WEAK_FUNC(sub_8238CA20);
PPC_FUNC_IMPL(__imp__sub_8238CA20) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e46c
	ctx.lr = 0x8238CA28;
	__restfpr_29(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r4,24(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r9,r10,1712
	ctx.r9.s64 = ctx.r10.s64 + 1712;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// clrlwi r8,r11,28
	ctx.r8.u64 = ctx.r11.u32 & 0xF;
	// lvlx128 v63,r0,r11
	temp.u32 = ctx.r0.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v63,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// lvlx v0,0,r9
	temp.u32 = ctx.r0.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v0,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v62,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bgt cr6,0x8238caa0
	if (ctx.cr6.gt) goto loc_8238CAA0;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r10,3,0,28
	ctx.r6.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r3,r10,1,0,30
	ctx.r3.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r31,r10,2,0,29
	ctx.r31.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r6,r10,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r10.s64;
	// lvlx128 v61,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v61,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v60,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v59,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v59,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v58,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v57,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v56,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// b 0x8238cb40
	goto loc_8238CB40;
loc_8238CAA0:
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v60,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r3,r10,3,0,28
	ctx.r3.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvrx128 v61,r5,r11
	temp.u32 = ctx.r5.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v61.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// vor128 v63,v63,v61
	simd::store_i8(ctx.v63.u8, simd::or_i8(simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v61.u8)));
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r7,r10,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r10.s64;
	// addi r3,r10,8
	ctx.r3.s64 = ctx.r10.s64 + 8;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r31,r10,4
	ctx.r31.s64 = ctx.r10.s64 + 4;
	// lvlx128 v57,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r30,r10,16
	ctx.r30.s64 = ctx.r10.s64 + 16;
	// lvlx128 v56,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r29,r10,1,0,30
	ctx.r29.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v58,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lvrx128 v54,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v54.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r31,r31,2,0,29
	ctx.r31.u64 = rotl64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// lvrx128 v55,r30,r11
	temp.u32 = ctx.r30.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v55.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// lvlx128 v53,r29,r11
	temp.u32 = ctx.r29.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v53,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r3,r7,16
	ctx.r3.s64 = ctx.r7.s64 + 16;
	// lvrx128 v52,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v52.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvrx128 v51,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v51.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v62,v62,v55
	simd::store_i8(ctx.v62.u8, simd::or_i8(simd::load_i8(ctx.v62.u8), simd::load_i8(ctx.v55.u8)));
	// lvlx128 v50,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v50,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v61,v53,v54
	simd::store_i8(ctx.v61.u8, simd::or_i8(simd::load_i8(ctx.v53.u8), simd::load_i8(ctx.v54.u8)));
	// lvrx128 v49,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v49.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v60,v60,v52
	simd::store_i8(ctx.v60.u8, simd::or_i8(simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v52.u8)));
	// lvrx128 v48,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v48.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v59,v50,v51
	simd::store_i8(ctx.v59.u8, simd::or_i8(simd::load_i8(ctx.v50.u8), simd::load_i8(ctx.v51.u8)));
	// lvrx128 v47,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v47.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v58,v58,v49
	simd::store_i8(ctx.v58.u8, simd::or_i8(simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v49.u8)));
	// vor128 v57,v57,v48
	simd::store_i8(ctx.v57.u8, simd::or_i8(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v48.u8)));
	// vor128 v56,v56,v47
	simd::store_i8(ctx.v56.u8, simd::or_i8(simd::load_i8(ctx.v56.u8), simd::load_i8(ctx.v47.u8)));
loc_8238CB40:
	// vperm128 v46,v63,v62,v0
	simd::store_i8(ctx.v46.u8, simd::permute_bytes(simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v62.u8), simd::load_i8(ctx.v0.u8)));
	// li r11,32
	ctx.r11.s64 = 32;
	// vperm128 v45,v61,v60,v0
	simd::store_i8(ctx.v45.u8, simd::permute_bytes(simd::load_i8(ctx.v61.u8), simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v0.u8)));
	// li r10,48
	ctx.r10.s64 = 48;
	// vperm128 v44,v59,v58,v0
	simd::store_i8(ctx.v44.u8, simd::permute_bytes(simd::load_i8(ctx.v59.u8), simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v0.u8)));
	// vperm128 v43,v57,v56,v0
	simd::store_i8(ctx.v43.u8, simd::permute_bytes(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v56.u8), simd::load_i8(ctx.v0.u8)));
	// stvlx128 v46,r0,r4
{
	uint32_t addr = 
ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v46), 15 - i));
}
	// stvlx128 v45,r4,r5
{
	uint32_t addr = 
ctx.r4.u32 + ctx.r5.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v45), 15 - i));
}
	// stvlx128 v44,r4,r11
{
	uint32_t addr = 
ctx.r4.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v44), 15 - i));
}
	// stvlx128 v43,r4,r10
{
	uint32_t addr = 
ctx.r4.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v43), 15 - i));
}
	// b 0x8233e4bc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238CB6C"))) PPC_WEAK_FUNC(sub_8238CB6C);
PPC_FUNC_IMPL(__imp__sub_8238CB6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238CB70"))) PPC_WEAK_FUNC(sub_8238CB70);
PPC_FUNC_IMPL(__imp__sub_8238CB70) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e464
	ctx.lr = 0x8238CB78;
	__restfpr_27(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r4,24(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r9,r10,1712
	ctx.r9.s64 = ctx.r10.s64 + 1712;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// clrlwi r8,r11,28
	ctx.r8.u64 = ctx.r11.u32 & 0xF;
	// cmplwi cr6,r8,8
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 8, ctx.xer);
	// lvlx v5,0,r9
	temp.u32 = ctx.r0.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v5,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bgt cr6,0x8238cbf8
	if (ctx.cr6.gt) goto loc_8238CBF8;
	// rlwinm r3,r10,1,0,30
	ctx.r3.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx v7,0,r11
	temp.u32 = ctx.r0.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v7,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx v0,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v0,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r10,3,0,28
	ctx.r6.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lvlx v13,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v13,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r31,r10,2,0,29
	ctx.r31.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r6,r10,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r10.s64;
	// rlwinm r3,r10,3,0,28
	ctx.r3.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx v12,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v12,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v11,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v11,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v10,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v10,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v9,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v9,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v8,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v8,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v6,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v6,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// b 0x8238ccb8
	goto loc_8238CCB8;
loc_8238CBF8:
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v60,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r3,r10,3,0,28
	ctx.r3.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx128 v63,r0,r11
	temp.u32 = ctx.r0.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v63,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lvlx128 v62,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lvrx128 v61,r5,r11
	temp.u32 = ctx.r5.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v61.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// vor128 v7,v63,v61
	simd::store_i8(ctx.v7.u8, simd::or_i8(simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v61.u8)));
	// subf r7,r10,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r10.s64;
	// addi r3,r10,8
	ctx.r3.s64 = ctx.r10.s64 + 8;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lvlx128 v58,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r31,r10,4
	ctx.r31.s64 = ctx.r10.s64 + 4;
	// lvlx128 v57,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r30,r10,2
	ctx.r30.s64 = ctx.r10.s64 + 2;
	// lvlx128 v59,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v59,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r29,r10,16
	ctx.r29.s64 = ctx.r10.s64 + 16;
	// lvrx128 v55,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v55.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r3,r7,16
	ctx.r3.s64 = ctx.r7.s64 + 16;
	// lvrx128 v53,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v53.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r28,r10,1,0,30
	ctx.r28.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r31,r31,2,0,29
	ctx.r31.u64 = rotl64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// vor128 v12,v60,v53
	simd::store_i8(ctx.v12.u8, simd::or_i8(simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v53.u8)));
	// rlwinm r27,r10,2,0,29
	ctx.r27.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// lvrx128 v56,r29,r11
	temp.u32 = ctx.r29.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v56.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// lvrx128 v48,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v48.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r9,r30,3,0,28
	ctx.r9.u64 = rotl64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx128 v54,r28,r11
	temp.u32 = ctx.r28.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v54,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r7,r10,3,0,28
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvrx128 v52,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v52.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvlx128 v51,r27,r11
	temp.u32 = ctx.r27.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v51,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v0,v62,v56
	simd::store_i8(ctx.v0.u8, simd::or_i8(simd::load_i8(ctx.v62.u8), simd::load_i8(ctx.v56.u8)));
	// lvrx128 v50,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v50.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v13,v54,v55
	simd::store_i8(ctx.v13.u8, simd::or_i8(simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v55.u8)));
	// lvrx128 v49,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v49.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v11,v51,v52
	simd::store_i8(ctx.v11.u8, simd::or_i8(simd::load_i8(ctx.v51.u8), simd::load_i8(ctx.v52.u8)));
	// lvrx128 v47,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v47.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v10,v59,v50
	simd::store_i8(ctx.v10.u8, simd::or_i8(simd::load_i8(ctx.v59.u8), simd::load_i8(ctx.v50.u8)));
	// lvlx128 v46,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v46,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v9,v58,v49
	simd::store_i8(ctx.v9.u8, simd::or_i8(simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v49.u8)));
	// vor128 v8,v57,v48
	simd::store_i8(ctx.v8.u8, simd::or_i8(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v48.u8)));
	// vor128 v6,v46,v47
	simd::store_i8(ctx.v6.u8, simd::or_i8(simd::load_i8(ctx.v46.u8), simd::load_i8(ctx.v47.u8)));
loc_8238CCB8:
	// vavgub v4,v0,v13
	simd::store_u8(ctx.v4.u8, simd::avg_u8(simd::load_u8(ctx.v0.u8), simd::load_u8(ctx.v13.u8)));
	// li r11,32
	ctx.r11.s64 = 32;
	// vavgub v3,v7,v0
	simd::store_u8(ctx.v3.u8, simd::avg_u8(simd::load_u8(ctx.v7.u8), simd::load_u8(ctx.v0.u8)));
	// li r10,48
	ctx.r10.s64 = 48;
	// vavgub v2,v12,v11
	simd::store_u8(ctx.v2.u8, simd::avg_u8(simd::load_u8(ctx.v12.u8), simd::load_u8(ctx.v11.u8)));
	// vavgub v1,v13,v12
	simd::store_u8(ctx.v1.u8, simd::avg_u8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v12.u8)));
	// vavgub v31,v10,v9
	simd::store_u8(ctx.v31.u8, simd::avg_u8(simd::load_u8(ctx.v10.u8), simd::load_u8(ctx.v9.u8)));
	// vavgub v30,v11,v10
	simd::store_u8(ctx.v30.u8, simd::avg_u8(simd::load_u8(ctx.v11.u8), simd::load_u8(ctx.v10.u8)));
	// vperm128 v45,v3,v4,v5
	simd::store_i8(ctx.v45.u8, simd::permute_bytes(simd::load_i8(ctx.v3.u8), simd::load_i8(ctx.v4.u8), simd::load_i8(ctx.v5.u8)));
	// vavgub v29,v8,v6
	simd::store_u8(ctx.v29.u8, simd::avg_u8(simd::load_u8(ctx.v8.u8), simd::load_u8(ctx.v6.u8)));
	// vavgub v28,v9,v8
	simd::store_u8(ctx.v28.u8, simd::avg_u8(simd::load_u8(ctx.v9.u8), simd::load_u8(ctx.v8.u8)));
	// vperm128 v44,v1,v2,v5
	simd::store_i8(ctx.v44.u8, simd::permute_bytes(simd::load_i8(ctx.v1.u8), simd::load_i8(ctx.v2.u8), simd::load_i8(ctx.v5.u8)));
	// vperm128 v43,v30,v31,v5
	simd::store_i8(ctx.v43.u8, simd::permute_bytes(simd::load_i8(ctx.v30.u8), simd::load_i8(ctx.v31.u8), simd::load_i8(ctx.v5.u8)));
	// vperm128 v42,v28,v29,v5
	simd::store_i8(ctx.v42.u8, simd::permute_bytes(simd::load_i8(ctx.v28.u8), simd::load_i8(ctx.v29.u8), simd::load_i8(ctx.v5.u8)));
	// stvlx128 v45,r0,r4
{
	uint32_t addr = 
ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v45), 15 - i));
}
	// stvlx128 v44,r4,r5
{
	uint32_t addr = 
ctx.r4.u32 + ctx.r5.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v44), 15 - i));
}
	// stvlx128 v43,r4,r11
{
	uint32_t addr = 
ctx.r4.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v43), 15 - i));
}
	// stvlx128 v42,r4,r10
{
	uint32_t addr = 
ctx.r4.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v42), 15 - i));
}
	// b 0x8233e4b4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238CD04"))) PPC_WEAK_FUNC(sub_8238CD04);
PPC_FUNC_IMPL(__imp__sub_8238CD04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238CD08"))) PPC_WEAK_FUNC(sub_8238CD08);
PPC_FUNC_IMPL(__imp__sub_8238CD08) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e46c
	ctx.lr = 0x8238CD10;
	__restfpr_29(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r4,24(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r9,r10,1712
	ctx.r9.s64 = ctx.r10.s64 + 1712;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// clrlwi r8,r11,28
	ctx.r8.u64 = ctx.r11.u32 & 0xF;
	// cmplwi cr6,r8,7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 7, ctx.xer);
	// lvlx v6,0,r9
	temp.u32 = ctx.r0.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v6,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// bgt cr6,0x8238cd88
	if (ctx.cr6.gt) goto loc_8238CD88;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx v0,0,r11
	temp.u32 = ctx.r0.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v0,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx v13,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v13,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r6,r10,3,0,28
	ctx.r6.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r3,r10,1,0,30
	ctx.r3.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r31,r10,2,0,29
	ctx.r31.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r6,r10,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r10.s64;
	// lvlx v12,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v12,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v11,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v11,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v10,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v10,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v9,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v9,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v8,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v8,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v7,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v7,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// b 0x8238ce30
	goto loc_8238CE30;
loc_8238CD88:
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v62,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r3,r10,3,0,28
	ctx.r3.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx128 v60,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lvlx128 v63,r0,r11
	temp.u32 = ctx.r0.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v63,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lvrx128 v61,r5,r11
	temp.u32 = ctx.r5.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v61.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r6,r7,1,0,30
	ctx.r6.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// vor128 v0,v63,v61
	simd::store_i8(ctx.v0.u8, simd::or_i8(simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v61.u8)));
	// subf r7,r10,r3
	ctx.r7.s64 = ctx.r3.s64 - ctx.r10.s64;
	// addi r3,r10,8
	ctx.r3.s64 = ctx.r10.s64 + 8;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r31,r10,4
	ctx.r31.s64 = ctx.r10.s64 + 4;
	// lvlx128 v58,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r30,r10,16
	ctx.r30.s64 = ctx.r10.s64 + 16;
	// lvlx128 v57,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r29,r10,1,0,30
	ctx.r29.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v59,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v59,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lvrx128 v55,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v55.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r31,r31,2,0,29
	ctx.r31.u64 = rotl64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// lvrx128 v56,r30,r11
	temp.u32 = ctx.r30.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v56.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// lvlx128 v54,r29,r11
	temp.u32 = ctx.r29.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v54,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r3,r7,16
	ctx.r3.s64 = ctx.r7.s64 + 16;
	// lvrx128 v53,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v53.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvrx128 v52,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v52.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v13,v62,v56
	simd::store_i8(ctx.v13.u8, simd::or_i8(simd::load_i8(ctx.v62.u8), simd::load_i8(ctx.v56.u8)));
	// lvlx128 v51,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v51,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v12,v54,v55
	simd::store_i8(ctx.v12.u8, simd::or_i8(simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v55.u8)));
	// lvrx128 v50,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v50.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v11,v60,v53
	simd::store_i8(ctx.v11.u8, simd::or_i8(simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v53.u8)));
	// lvrx128 v49,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v49.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v10,v51,v52
	simd::store_i8(ctx.v10.u8, simd::or_i8(simd::load_i8(ctx.v51.u8), simd::load_i8(ctx.v52.u8)));
	// lvrx128 v48,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v48.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v9,v59,v50
	simd::store_i8(ctx.v9.u8, simd::or_i8(simd::load_i8(ctx.v59.u8), simd::load_i8(ctx.v50.u8)));
	// vor128 v8,v58,v49
	simd::store_i8(ctx.v8.u8, simd::or_i8(simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v49.u8)));
	// vor128 v7,v57,v48
	simd::store_i8(ctx.v7.u8, simd::or_i8(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v48.u8)));
loc_8238CE30:
	// vsldoi v5,v13,v13,1
	simd::store_i8(ctx.v5.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v13.u8), 15));
	// li r11,32
	ctx.r11.s64 = 32;
	// vsldoi v4,v0,v0,1
	simd::store_i8(ctx.v4.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v0.u8), simd::load_i8(ctx.v0.u8), 15));
	// li r10,48
	ctx.r10.s64 = 48;
	// vsldoi v3,v11,v11,1
	simd::store_i8(ctx.v3.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v11.u8), 15));
	// vsldoi v2,v12,v12,1
	simd::store_i8(ctx.v2.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v12.u8), 15));
	// vsldoi v1,v9,v9,1
	simd::store_i8(ctx.v1.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v9.u8), simd::load_i8(ctx.v9.u8), 15));
	// vavgub v31,v13,v5
	simd::store_u8(ctx.v31.u8, simd::avg_u8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v5.u8)));
	// vsldoi v30,v10,v10,1
	simd::store_i8(ctx.v30.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v10.u8), simd::load_i8(ctx.v10.u8), 15));
	// vavgub v29,v0,v4
	simd::store_u8(ctx.v29.u8, simd::avg_u8(simd::load_u8(ctx.v0.u8), simd::load_u8(ctx.v4.u8)));
	// vsldoi v28,v7,v7,1
	simd::store_i8(ctx.v28.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v7.u8), simd::load_i8(ctx.v7.u8), 15));
	// vavgub v27,v11,v3
	simd::store_u8(ctx.v27.u8, simd::avg_u8(simd::load_u8(ctx.v11.u8), simd::load_u8(ctx.v3.u8)));
	// vsldoi v26,v8,v8,1
	simd::store_i8(ctx.v26.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v8.u8), simd::load_i8(ctx.v8.u8), 15));
	// vavgub v25,v12,v2
	simd::store_u8(ctx.v25.u8, simd::avg_u8(simd::load_u8(ctx.v12.u8), simd::load_u8(ctx.v2.u8)));
	// vavgub v24,v9,v1
	simd::store_u8(ctx.v24.u8, simd::avg_u8(simd::load_u8(ctx.v9.u8), simd::load_u8(ctx.v1.u8)));
	// vavgub v23,v10,v30
	simd::store_u8(ctx.v23.u8, simd::avg_u8(simd::load_u8(ctx.v10.u8), simd::load_u8(ctx.v30.u8)));
	// vperm128 v47,v29,v31,v6
	simd::store_i8(ctx.v47.u8, simd::permute_bytes(simd::load_i8(ctx.v29.u8), simd::load_i8(ctx.v31.u8), simd::load_i8(ctx.v6.u8)));
	// vavgub v22,v7,v28
	simd::store_u8(ctx.v22.u8, simd::avg_u8(simd::load_u8(ctx.v7.u8), simd::load_u8(ctx.v28.u8)));
	// vavgub v21,v8,v26
	simd::store_u8(ctx.v21.u8, simd::avg_u8(simd::load_u8(ctx.v8.u8), simd::load_u8(ctx.v26.u8)));
	// vperm128 v46,v25,v27,v6
	simd::store_i8(ctx.v46.u8, simd::permute_bytes(simd::load_i8(ctx.v25.u8), simd::load_i8(ctx.v27.u8), simd::load_i8(ctx.v6.u8)));
	// vperm128 v45,v23,v24,v6
	simd::store_i8(ctx.v45.u8, simd::permute_bytes(simd::load_i8(ctx.v23.u8), simd::load_i8(ctx.v24.u8), simd::load_i8(ctx.v6.u8)));
	// vperm128 v44,v21,v22,v6
	simd::store_i8(ctx.v44.u8, simd::permute_bytes(simd::load_i8(ctx.v21.u8), simd::load_i8(ctx.v22.u8), simd::load_i8(ctx.v6.u8)));
	// stvlx128 v47,r0,r4
{
	uint32_t addr = 
ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v47), 15 - i));
}
	// stvlx128 v46,r4,r5
{
	uint32_t addr = 
ctx.r4.u32 + ctx.r5.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v46), 15 - i));
}
	// stvlx128 v45,r4,r11
{
	uint32_t addr = 
ctx.r4.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v45), 15 - i));
}
	// stvlx128 v44,r4,r10
{
	uint32_t addr = 
ctx.r4.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v44), 15 - i));
}
	// b 0x8233e4bc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238CE9C"))) PPC_WEAK_FUNC(sub_8238CE9C);
PPC_FUNC_IMPL(__imp__sub_8238CE9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238CEA0"))) PPC_WEAK_FUNC(sub_8238CEA0);
PPC_FUNC_IMPL(__imp__sub_8238CEA0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e464
	ctx.lr = 0x8238CEA8;
	__restfpr_27(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r4,24(r3)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r9,r10,1712
	ctx.r9.s64 = ctx.r10.s64 + 1712;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// clrlwi r8,r11,28
	ctx.r8.u64 = ctx.r11.u32 & 0xF;
	// vspltisb v0,1
	simd::store_i8(ctx.v0.u8, simd::set1_i8(int8_t(0x1)));
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cmplwi cr6,r8,7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 7, ctx.xer);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx v2,0,r9
	temp.u32 = ctx.r0.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v2,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// bgt cr6,0x8238cf2c
	if (ctx.cr6.gt) goto loc_8238CF2C;
	// rlwinm r3,r10,1,0,30
	ctx.r3.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx v11,0,r11
	temp.u32 = ctx.r0.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v11,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lvlx v10,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v10,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r6,r10,3,0,28
	ctx.r6.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r31,r10,2,0,29
	ctx.r31.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx v9,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v9,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r6,r10,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r10.s64;
	// rlwinm r3,r10,3,0,28
	ctx.r3.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx v8,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v8,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v7,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v7,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v6,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v6,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v5,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v5,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v4,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v4,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v3,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v3,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// b 0x8238cfe8
	goto loc_8238CFE8;
loc_8238CF2C:
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lvlx128 v62,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lvlx128 v63,r0,r11
	temp.u32 = ctx.r0.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v63,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r3,r10,3,0,28
	ctx.r3.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvrx128 v61,r5,r11
	temp.u32 = ctx.r5.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v61.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// add r8,r10,r7
	ctx.r8.u64 = ctx.r10.u64 + ctx.r7.u64;
	// vor128 v11,v63,v61
	simd::store_i8(ctx.v11.u8, simd::or_i8(simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v61.u8)));
	// rlwinm r7,r6,1,0,30
	ctx.r7.u64 = rotl64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r6,r10,r3
	ctx.r6.s64 = ctx.r3.s64 - ctx.r10.s64;
	// addi r3,r10,8
	ctx.r3.s64 = ctx.r10.s64 + 8;
	// lvlx128 v60,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r31,r10,4
	ctx.r31.s64 = ctx.r10.s64 + 4;
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v59,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v59,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r30,r10,2
	ctx.r30.s64 = ctx.r10.s64 + 2;
	// lvlx128 v58,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v57,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r29,r10,16
	ctx.r29.s64 = ctx.r10.s64 + 16;
	// rlwinm r28,r10,1,0,30
	ctx.r28.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r27,r10,2,0,29
	ctx.r27.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lvrx128 v55,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v55.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rlwinm r31,r31,2,0,29
	ctx.r31.u64 = rotl64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// lvrx128 v56,r29,r11
	temp.u32 = ctx.r29.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v56.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// lvlx128 v54,r28,r11
	temp.u32 = ctx.r28.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v54,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// lvlx128 v51,r27,r11
	temp.u32 = ctx.r27.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v51,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r3,r30,3,0,28
	ctx.r3.u64 = rotl64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lvrx128 v53,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v53.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvrx128 v52,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v52.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvrx128 v50,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v50.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v10,v62,v56
	simd::store_i8(ctx.v10.u8, simd::or_i8(simd::load_i8(ctx.v62.u8), simd::load_i8(ctx.v56.u8)));
	// lvrx128 v49,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v49.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v9,v54,v55
	simd::store_i8(ctx.v9.u8, simd::or_i8(simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v55.u8)));
	// lvrx128 v48,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v48.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v8,v60,v53
	simd::store_i8(ctx.v8.u8, simd::or_i8(simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v53.u8)));
	// lvrx128 v47,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v47.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v7,v51,v52
	simd::store_i8(ctx.v7.u8, simd::or_i8(simd::load_i8(ctx.v51.u8), simd::load_i8(ctx.v52.u8)));
	// lvlx128 v46,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v46,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v6,v59,v50
	simd::store_i8(ctx.v6.u8, simd::or_i8(simd::load_i8(ctx.v59.u8), simd::load_i8(ctx.v50.u8)));
	// vor128 v5,v58,v49
	simd::store_i8(ctx.v5.u8, simd::or_i8(simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v49.u8)));
	// vor128 v4,v57,v48
	simd::store_i8(ctx.v4.u8, simd::or_i8(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v48.u8)));
	// vor128 v3,v46,v47
	simd::store_i8(ctx.v3.u8, simd::or_i8(simd::load_i8(ctx.v46.u8), simd::load_i8(ctx.v47.u8)));
loc_8238CFE8:
	// vsldoi v1,v11,v11,1
	simd::store_i8(ctx.v1.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v11.u8), 15));
	// li r11,32
	ctx.r11.s64 = 32;
	// vsldoi v31,v10,v10,1
	simd::store_i8(ctx.v31.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v10.u8), simd::load_i8(ctx.v10.u8), 15));
	// li r10,48
	ctx.r10.s64 = 48;
	// vsldoi v30,v9,v9,1
	simd::store_i8(ctx.v30.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v9.u8), simd::load_i8(ctx.v9.u8), 15));
	// vsldoi v29,v8,v8,1
	simd::store_i8(ctx.v29.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v8.u8), simd::load_i8(ctx.v8.u8), 15));
	// vavgub v25,v11,v1
	simd::store_u8(ctx.v25.u8, simd::avg_u8(simd::load_u8(ctx.v11.u8), simd::load_u8(ctx.v1.u8)));
	// vsldoi v28,v7,v7,1
	simd::store_i8(ctx.v28.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v7.u8), simd::load_i8(ctx.v7.u8), 15));
	// vavgub v13,v10,v31
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v10.u8), simd::load_u8(ctx.v31.u8)));
	// vsldoi v27,v6,v6,1
	simd::store_i8(ctx.v27.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v6.u8), simd::load_i8(ctx.v6.u8), 15));
	// vavgub v12,v9,v30
	simd::store_u8(ctx.v12.u8, simd::avg_u8(simd::load_u8(ctx.v9.u8), simd::load_u8(ctx.v30.u8)));
	// vsldoi v26,v5,v5,1
	simd::store_i8(ctx.v26.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v5.u8), simd::load_i8(ctx.v5.u8), 15));
	// vxor128 v45,v11,v1
	simd::store_u8(ctx.v45.u8, simd::xor_i8(simd::load_u8(ctx.v11.u8), simd::load_u8(ctx.v1.u8)));
	// vavgub v11,v7,v28
	simd::store_u8(ctx.v11.u8, simd::avg_u8(simd::load_u8(ctx.v7.u8), simd::load_u8(ctx.v28.u8)));
	// vxor128 v44,v25,v13
	simd::store_u8(ctx.v44.u8, simd::xor_i8(simd::load_u8(ctx.v25.u8), simd::load_u8(ctx.v13.u8)));
	// vxor128 v43,v13,v12
	simd::store_u8(ctx.v43.u8, simd::xor_i8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v12.u8)));
	// vavgub v1,v13,v12
	simd::store_u8(ctx.v1.u8, simd::avg_u8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v12.u8)));
	// vavgub v25,v25,v13
	simd::store_u8(ctx.v25.u8, simd::avg_u8(simd::load_u8(ctx.v25.u8), simd::load_u8(ctx.v13.u8)));
	// vavgub v13,v8,v29
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v8.u8), simd::load_u8(ctx.v29.u8)));
	// vxor128 v42,v10,v31
	simd::store_u8(ctx.v42.u8, simd::xor_i8(simd::load_u8(ctx.v10.u8), simd::load_u8(ctx.v31.u8)));
	// vsldoi v10,v4,v4,1
	simd::store_i8(ctx.v10.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v4.u8), simd::load_i8(ctx.v4.u8), 15));
	// vxor128 v41,v9,v30
	simd::store_u8(ctx.v41.u8, simd::xor_i8(simd::load_u8(ctx.v9.u8), simd::load_u8(ctx.v30.u8)));
	// vsldoi v31,v3,v3,1
	simd::store_i8(ctx.v31.u8, simd::shift_left_insert_bytes(simd::load_i8(ctx.v3.u8), simd::load_i8(ctx.v3.u8), 15));
	// vxor128 v40,v8,v29
	simd::store_u8(ctx.v40.u8, simd::xor_i8(simd::load_u8(ctx.v8.u8), simd::load_u8(ctx.v29.u8)));
	// vxor128 v39,v13,v11
	simd::store_u8(ctx.v39.u8, simd::xor_i8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v11.u8)));
	// vavgub v24,v13,v11
	simd::store_u8(ctx.v24.u8, simd::avg_u8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v11.u8)));
	// vxor128 v38,v12,v13
	simd::store_u8(ctx.v38.u8, simd::xor_i8(simd::load_u8(ctx.v12.u8), simd::load_u8(ctx.v13.u8)));
	// vavgub v23,v12,v13
	simd::store_u8(ctx.v23.u8, simd::avg_u8(simd::load_u8(ctx.v12.u8), simd::load_u8(ctx.v13.u8)));
	// vxor128 v37,v7,v28
	simd::store_u8(ctx.v37.u8, simd::xor_i8(simd::load_u8(ctx.v7.u8), simd::load_u8(ctx.v28.u8)));
	// vavgub v13,v6,v27
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v6.u8), simd::load_u8(ctx.v27.u8)));
	// vavgub v12,v5,v26
	simd::store_u8(ctx.v12.u8, simd::avg_u8(simd::load_u8(ctx.v5.u8), simd::load_u8(ctx.v26.u8)));
	// vxor128 v36,v6,v27
	simd::store_u8(ctx.v36.u8, simd::xor_i8(simd::load_u8(ctx.v6.u8), simd::load_u8(ctx.v27.u8)));
	// vxor128 v35,v5,v26
	simd::store_u8(ctx.v35.u8, simd::xor_i8(simd::load_u8(ctx.v5.u8), simd::load_u8(ctx.v26.u8)));
	// vor128 v33,v45,v42
	simd::store_i8(ctx.v33.u8, simd::or_i8(simd::load_i8(ctx.v45.u8), simd::load_i8(ctx.v42.u8)));
	// vor128 v34,v42,v41
	simd::store_i8(ctx.v34.u8, simd::or_i8(simd::load_i8(ctx.v42.u8), simd::load_i8(ctx.v41.u8)));
	// vor128 v32,v41,v40
	simd::store_i8(ctx.v32.u8, simd::or_i8(simd::load_i8(ctx.v41.u8), simd::load_i8(ctx.v40.u8)));
	// vor128 v63,v40,v37
	simd::store_i8(ctx.v63.u8, simd::or_i8(simd::load_i8(ctx.v40.u8), simd::load_i8(ctx.v37.u8)));
	// vxor128 v62,v11,v13
	simd::store_u8(ctx.v62.u8, simd::xor_i8(simd::load_u8(ctx.v11.u8), simd::load_u8(ctx.v13.u8)));
	// vxor128 v61,v13,v12
	simd::store_u8(ctx.v61.u8, simd::xor_i8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v12.u8)));
	// vor128 v60,v37,v36
	simd::store_i8(ctx.v60.u8, simd::or_i8(simd::load_i8(ctx.v37.u8), simd::load_i8(ctx.v36.u8)));
	// vor128 v59,v36,v35
	simd::store_i8(ctx.v59.u8, simd::or_i8(simd::load_i8(ctx.v36.u8), simd::load_i8(ctx.v35.u8)));
	// vand128 v58,v34,v43
	simd::store_u8(ctx.v58.u8, simd::and_u8(simd::load_u8(ctx.v34.u8), simd::load_u8(ctx.v43.u8)));
	// vand128 v57,v33,v44
	simd::store_u8(ctx.v57.u8, simd::and_u8(simd::load_u8(ctx.v33.u8), simd::load_u8(ctx.v44.u8)));
	// vand128 v56,v32,v38
	simd::store_u8(ctx.v56.u8, simd::and_u8(simd::load_u8(ctx.v32.u8), simd::load_u8(ctx.v38.u8)));
	// vand128 v55,v63,v39
	simd::store_u8(ctx.v55.u8, simd::and_u8(simd::load_u8(ctx.v63.u8), simd::load_u8(ctx.v39.u8)));
	// vand128 v54,v60,v62
	simd::store_u8(ctx.v54.u8, simd::and_u8(simd::load_u8(ctx.v60.u8), simd::load_u8(ctx.v62.u8)));
	// vand128 v53,v59,v61
	simd::store_u8(ctx.v53.u8, simd::and_u8(simd::load_u8(ctx.v59.u8), simd::load_u8(ctx.v61.u8)));
	// vand128 v22,v58,v0
	simd::store_u8(ctx.v22.u8, simd::and_u8(simd::load_u8(ctx.v58.u8), simd::load_u8(ctx.v0.u8)));
	// vand128 v21,v57,v0
	simd::store_u8(ctx.v21.u8, simd::and_u8(simd::load_u8(ctx.v57.u8), simd::load_u8(ctx.v0.u8)));
	// vand128 v20,v56,v0
	simd::store_u8(ctx.v20.u8, simd::and_u8(simd::load_u8(ctx.v56.u8), simd::load_u8(ctx.v0.u8)));
	// vand128 v19,v55,v0
	simd::store_u8(ctx.v19.u8, simd::and_u8(simd::load_u8(ctx.v55.u8), simd::load_u8(ctx.v0.u8)));
	// vavgub v18,v11,v13
	simd::store_u8(ctx.v18.u8, simd::avg_u8(simd::load_u8(ctx.v11.u8), simd::load_u8(ctx.v13.u8)));
	// vavgub v17,v13,v12
	simd::store_u8(ctx.v17.u8, simd::avg_u8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v12.u8)));
	// vand128 v16,v54,v0
	simd::store_u8(ctx.v16.u8, simd::and_u8(simd::load_u8(ctx.v54.u8), simd::load_u8(ctx.v0.u8)));
	// vand128 v15,v53,v0
	simd::store_u8(ctx.v15.u8, simd::and_u8(simd::load_u8(ctx.v53.u8), simd::load_u8(ctx.v0.u8)));
	// vsububs v13,v25,v21
	simd::store_u8(ctx.v13.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v25.u8), simd::load_u8(ctx.v21.u8)));
	// vsububs v14,v1,v22
	simd::store_u8(ctx.v14.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v1.u8), simd::load_u8(ctx.v22.u8)));
	// vavgub v11,v4,v10
	simd::store_u8(ctx.v11.u8, simd::avg_u8(simd::load_u8(ctx.v4.u8), simd::load_u8(ctx.v10.u8)));
	// vavgub v9,v3,v31
	simd::store_u8(ctx.v9.u8, simd::avg_u8(simd::load_u8(ctx.v3.u8), simd::load_u8(ctx.v31.u8)));
	// vsububs v8,v23,v20
	simd::store_u8(ctx.v8.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v23.u8), simd::load_u8(ctx.v20.u8)));
	// vsububs v7,v24,v19
	simd::store_u8(ctx.v7.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v24.u8), simd::load_u8(ctx.v19.u8)));
	// vperm128 v52,v13,v14,v2
	simd::store_i8(ctx.v52.u8, simd::permute_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v14.u8), simd::load_i8(ctx.v2.u8)));
	// vsububs v6,v18,v16
	simd::store_u8(ctx.v6.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v18.u8), simd::load_u8(ctx.v16.u8)));
	// vsububs v5,v17,v15
	simd::store_u8(ctx.v5.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v17.u8), simd::load_u8(ctx.v15.u8)));
	// vor v13,v11,v11
	simd::store_i8(ctx.v13.u8, simd::load_i8(ctx.v11.u8));
	// vxor128 v50,v4,v10
	simd::store_u8(ctx.v50.u8, simd::xor_i8(simd::load_u8(ctx.v4.u8), simd::load_u8(ctx.v10.u8)));
	// vperm128 v51,v8,v7,v2
	simd::store_i8(ctx.v51.u8, simd::permute_bytes(simd::load_i8(ctx.v8.u8), simd::load_i8(ctx.v7.u8), simd::load_i8(ctx.v2.u8)));
	// vor v11,v9,v9
	simd::store_i8(ctx.v11.u8, simd::load_i8(ctx.v9.u8));
	// vxor128 v49,v3,v31
	simd::store_u8(ctx.v49.u8, simd::xor_i8(simd::load_u8(ctx.v3.u8), simd::load_u8(ctx.v31.u8)));
	// vperm128 v48,v6,v5,v2
	simd::store_i8(ctx.v48.u8, simd::permute_bytes(simd::load_i8(ctx.v6.u8), simd::load_i8(ctx.v5.u8), simd::load_i8(ctx.v2.u8)));
	// vxor128 v47,v12,v13
	simd::store_u8(ctx.v47.u8, simd::xor_i8(simd::load_u8(ctx.v12.u8), simd::load_u8(ctx.v13.u8)));
	// stvlx128 v52,r0,r4
{
	uint32_t addr = 
ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v52), 15 - i));
}
	// vor128 v45,v35,v50
	simd::store_i8(ctx.v45.u8, simd::or_i8(simd::load_i8(ctx.v35.u8), simd::load_i8(ctx.v50.u8)));
	// vxor128 v46,v13,v11
	simd::store_u8(ctx.v46.u8, simd::xor_i8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v11.u8)));
	// vor128 v44,v50,v49
	simd::store_i8(ctx.v44.u8, simd::or_i8(simd::load_i8(ctx.v50.u8), simd::load_i8(ctx.v49.u8)));
	// stvlx128 v51,r4,r5
{
	uint32_t addr = 
ctx.r4.u32 + ctx.r5.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v51), 15 - i));
}
	// vavgub v4,v13,v11
	simd::store_u8(ctx.v4.u8, simd::avg_u8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v11.u8)));
	// vavgub v3,v12,v13
	simd::store_u8(ctx.v3.u8, simd::avg_u8(simd::load_u8(ctx.v12.u8), simd::load_u8(ctx.v13.u8)));
	// stvlx128 v48,r4,r11
{
	uint32_t addr = 
ctx.r4.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v48), 15 - i));
}
	// vand128 v43,v45,v47
	simd::store_u8(ctx.v43.u8, simd::and_u8(simd::load_u8(ctx.v45.u8), simd::load_u8(ctx.v47.u8)));
	// vand128 v42,v44,v46
	simd::store_u8(ctx.v42.u8, simd::and_u8(simd::load_u8(ctx.v44.u8), simd::load_u8(ctx.v46.u8)));
	// vand128 v1,v42,v0
	simd::store_u8(ctx.v1.u8, simd::and_u8(simd::load_u8(ctx.v42.u8), simd::load_u8(ctx.v0.u8)));
	// vand128 v31,v43,v0
	simd::store_u8(ctx.v31.u8, simd::and_u8(simd::load_u8(ctx.v43.u8), simd::load_u8(ctx.v0.u8)));
	// vsububs v30,v4,v1
	simd::store_u8(ctx.v30.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v4.u8), simd::load_u8(ctx.v1.u8)));
	// vsububs v29,v3,v31
	simd::store_u8(ctx.v29.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v3.u8), simd::load_u8(ctx.v31.u8)));
	// vperm128 v41,v29,v30,v2
	simd::store_i8(ctx.v41.u8, simd::permute_bytes(simd::load_i8(ctx.v29.u8), simd::load_i8(ctx.v30.u8), simd::load_i8(ctx.v2.u8)));
	// stvlx128 v41,r4,r10
{
	uint32_t addr = 
ctx.r4.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v41), 15 - i));
}
	// b 0x8233e4b4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238D148"))) PPC_WEAK_FUNC(sub_8238D148);
PPC_FUNC_IMPL(__imp__sub_8238D148) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e458
	ctx.lr = 0x8238D150;
	__restfpr_24(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r9,-16
	ctx.r9.s64 = -16;
	// lwz r29,24(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r10,1728
	ctx.r8.s64 = ctx.r10.s64 + 1728;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// clrlwi r7,r11,28
	ctx.r7.u64 = ctx.r11.u32 & 0xF;
	// li r30,16
	ctx.r30.s64 = 16;
	// lvlx128 v63,r0,r11
	temp.u32 = ctx.r0.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v63,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// lvlx v0,r8,r9
	temp.u32 = ctx.r8.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v0,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx v7,0,r8
	temp.u32 = ctx.r0.u32 + ctx.r8.u32;
	simd::store_shuffled(ctx.v7,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx128 v62,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// bne cr6,0x8238d230
	if (!ctx.cr6.eq) goto loc_8238D230;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r27,r10,1,0,30
	ctx.r27.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v61,r27,r11
	temp.u32 = ctx.r27.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v61,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v60,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r4,r10,3,0,28
	ctx.r4.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx128 v58,r5,r11
	temp.u32 = ctx.r5.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r31,r10,3,0,28
	ctx.r31.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx128 v57,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lvlx128 v54,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v54,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// subf r4,r10,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r10.s64;
	// lvlx128 v53,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v53,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r28,r10,4,0,27
	ctx.r28.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r26,r10,2,0,29
	ctx.r26.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r31,r10,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r10.s64;
	// rlwinm r27,r10,3,0,28
	ctx.r27.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mulli r6,r10,11
	ctx.r6.s64 = ctx.r10.s64 * 11;
	// lvlx128 v59,r26,r11
	temp.u32 = ctx.r26.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v59,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v56,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v55,r27,r11
	temp.u32 = ctx.r27.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v55,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v52,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v52,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// mulli r3,r10,13
	ctx.r3.s64 = ctx.r10.s64 * 13;
	// lvlx128 v51,r5,r11
	temp.u32 = ctx.r5.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v51,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v50,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v50,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = rotl64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r10,r28
	ctx.r8.s64 = ctx.r28.s64 - ctx.r10.s64;
	// lvlx128 v49,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v49,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v48,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v48,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// b 0x8238d38c
	goto loc_8238D38C;
loc_8238D230:
	// rlwinm r4,r10,1,0,30
	ctx.r4.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v58,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r5,r10,1,0,30
	ctx.r5.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvrx128 v61,r30,r11
	temp.u32 = ctx.r30.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v61.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// add r9,r10,r4
	ctx.r9.u64 = ctx.r10.u64 + ctx.r4.u64;
	// vor128 v63,v63,v61
	simd::store_i8(ctx.v63.u8, simd::or_i8(simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v61.u8)));
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r28,r10,r5
	ctx.r28.u64 = ctx.r10.u64 + ctx.r5.u64;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// rlwinm r5,r10,3,0,28
	ctx.r5.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx128 v57,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// rlwinm r31,r3,1,0,30
	ctx.r31.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r3,r10,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r10.s64;
	// rlwinm r4,r6,1,0,30
	ctx.r4.u64 = rotl64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// lvrx128 v50,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v50.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r28,2,0,29
	ctx.r6.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx128 v56,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// mulli r5,r10,11
	ctx.r5.s64 = ctx.r10.s64 * 11;
	// lvlx128 v55,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v55,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v53,r4,r11
	temp.u32 = ctx.r4.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v53,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v60,v57,v50
	simd::store_i8(ctx.v60.u8, simd::or_i8(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v50.u8)));
	// lvrx128 v49,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v49.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvlx128 v44,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v44,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v58,v58,v49
	simd::store_i8(ctx.v58.u8, simd::or_i8(simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v49.u8)));
	// lvlx128 v51,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v51,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v52,r5,r11
	temp.u32 = ctx.r5.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v52,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r7,r10,3,0,28
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r28,r10,8
	ctx.r28.s64 = ctx.r10.s64 + 8;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// addi r4,r4,16
	ctx.r4.s64 = ctx.r4.s64 + 16;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r28,r28,1,0,30
	ctx.r28.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r8,r31,16
	ctx.r8.s64 = ctx.r31.s64 + 16;
	// addi r9,r5,16
	ctx.r9.s64 = ctx.r5.s64 + 16;
	// lvrx128 v42,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v42.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r5,r10,3,0,28
	ctx.r5.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvrx128 v38,r4,r11
	temp.u32 = ctx.r4.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v38.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r27,r10,4
	ctx.r27.s64 = ctx.r10.s64 + 4;
	// lvlx128 v54,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v54,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r26,r10,2
	ctx.r26.s64 = ctx.r10.s64 + 2;
	// lvrx128 v47,r28,r11
	temp.u32 = ctx.r28.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v47.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// subf r3,r10,r5
	ctx.r3.s64 = ctx.r5.s64 - ctx.r10.s64;
	// lvrx128 v43,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v43.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r4,r10,4,0,27
	ctx.r4.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lvrx128 v37,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v37.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r25,r10,16
	ctx.r25.s64 = ctx.r10.s64 + 16;
	// vor128 v57,v56,v43
	simd::store_i8(ctx.v57.u8, simd::or_i8(simd::load_i8(ctx.v56.u8), simd::load_i8(ctx.v43.u8)));
	// rlwinm r24,r10,1,0,30
	ctx.r24.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// vor128 v56,v55,v42
	simd::store_i8(ctx.v56.u8, simd::or_i8(simd::load_i8(ctx.v55.u8), simd::load_i8(ctx.v42.u8)));
	// rlwinm r28,r10,3,0,28
	ctx.r28.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// vor128 v53,v53,v38
	simd::store_i8(ctx.v53.u8, simd::or_i8(simd::load_i8(ctx.v53.u8), simd::load_i8(ctx.v38.u8)));
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// vor128 v52,v52,v37
	simd::store_i8(ctx.v52.u8, simd::or_i8(simd::load_i8(ctx.v52.u8), simd::load_i8(ctx.v37.u8)));
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// rlwinm r27,r27,2,0,29
	ctx.r27.u64 = rotl64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lvrx128 v48,r25,r11
	temp.u32 = ctx.r25.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v48.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r31,r26,3,0,28
	ctx.r31.u64 = rotl64(ctx.r26.u32 | (ctx.r26.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx128 v46,r24,r11
	temp.u32 = ctx.r24.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v46,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// mulli r8,r10,13
	ctx.r8.s64 = ctx.r10.s64 * 13;
	// lvlx128 v40,r28,r11
	temp.u32 = ctx.r28.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v40,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvrx128 v39,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v39.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v62,v62,v48
	simd::store_i8(ctx.v62.u8, simd::or_i8(simd::load_i8(ctx.v62.u8), simd::load_i8(ctx.v48.u8)));
	// lvrx128 v36,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v36.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v61,v46,v47
	simd::store_i8(ctx.v61.u8, simd::or_i8(simd::load_i8(ctx.v46.u8), simd::load_i8(ctx.v47.u8)));
	// lvrx128 v45,r27,r11
	temp.u32 = ctx.r27.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v45.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v54,v54,v39
	simd::store_i8(ctx.v54.u8, simd::or_i8(simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v39.u8)));
	// lvrx128 v41,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v41.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v59,v44,v45
	simd::store_i8(ctx.v59.u8, simd::or_i8(simd::load_i8(ctx.v44.u8), simd::load_i8(ctx.v45.u8)));
	// lvlx128 v35,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v35,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v55,v40,v41
	simd::store_i8(ctx.v55.u8, simd::or_i8(simd::load_i8(ctx.v40.u8), simd::load_i8(ctx.v41.u8)));
	// vor128 v51,v51,v36
	simd::store_i8(ctx.v51.u8, simd::or_i8(simd::load_i8(ctx.v51.u8), simd::load_i8(ctx.v36.u8)));
	// rlwinm r9,r3,1,0,30
	ctx.r9.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r10,r4
	ctx.r10.s64 = ctx.r4.s64 - ctx.r10.s64;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// addi r7,r9,16
	ctx.r7.s64 = ctx.r9.s64 + 16;
	// addi r6,r10,16
	ctx.r6.s64 = ctx.r10.s64 + 16;
	// lvlx128 v34,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v34,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v33,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v33,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvrx128 v32,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v32.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvrx128 v49,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v49.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v50,v35,v32
	simd::store_i8(ctx.v50.u8, simd::or_i8(simd::load_i8(ctx.v35.u8), simd::load_i8(ctx.v32.u8)));
	// lvrx128 v48,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v48.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v49,v34,v49
	simd::store_i8(ctx.v49.u8, simd::or_i8(simd::load_i8(ctx.v34.u8), simd::load_i8(ctx.v49.u8)));
	// vor128 v48,v33,v48
	simd::store_i8(ctx.v48.u8, simd::or_i8(simd::load_i8(ctx.v33.u8), simd::load_i8(ctx.v48.u8)));
loc_8238D38C:
	// vperm128 v47,v63,v62,v0
	simd::store_i8(ctx.v47.u8, simd::permute_bytes(simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v62.u8), simd::load_i8(ctx.v0.u8)));
	// li r11,32
	ctx.r11.s64 = 32;
	// vperm128 v46,v61,v60,v0
	simd::store_i8(ctx.v46.u8, simd::permute_bytes(simd::load_i8(ctx.v61.u8), simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v0.u8)));
	// li r10,48
	ctx.r10.s64 = 48;
	// vperm128 v45,v59,v58,v0
	simd::store_i8(ctx.v45.u8, simd::permute_bytes(simd::load_i8(ctx.v59.u8), simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v0.u8)));
	// li r9,64
	ctx.r9.s64 = 64;
	// vperm128 v44,v57,v56,v0
	simd::store_i8(ctx.v44.u8, simd::permute_bytes(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v56.u8), simd::load_i8(ctx.v0.u8)));
	// li r8,80
	ctx.r8.s64 = 80;
	// vperm128 v43,v63,v62,v7
	simd::store_i8(ctx.v43.u8, simd::permute_bytes(simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v62.u8), simd::load_i8(ctx.v7.u8)));
	// li r7,96
	ctx.r7.s64 = 96;
	// vperm128 v42,v61,v60,v7
	simd::store_i8(ctx.v42.u8, simd::permute_bytes(simd::load_i8(ctx.v61.u8), simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v7.u8)));
	// li r6,112
	ctx.r6.s64 = 112;
	// vperm128 v41,v59,v58,v7
	simd::store_i8(ctx.v41.u8, simd::permute_bytes(simd::load_i8(ctx.v59.u8), simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v7.u8)));
	// li r5,128
	ctx.r5.s64 = 128;
	// vperm128 v40,v57,v56,v7
	simd::store_i8(ctx.v40.u8, simd::permute_bytes(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v56.u8), simd::load_i8(ctx.v7.u8)));
	// stvlx128 v47,r0,r29
{
	uint32_t addr = 
ctx.r29.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v47), 15 - i));
}
	// vperm128 v39,v55,v54,v0
	simd::store_i8(ctx.v39.u8, simd::permute_bytes(simd::load_i8(ctx.v55.u8), simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v0.u8)));
	// stvlx128 v46,r29,r30
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r30.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v46), 15 - i));
}
	// vperm128 v38,v53,v52,v0
	simd::store_i8(ctx.v38.u8, simd::permute_bytes(simd::load_i8(ctx.v53.u8), simd::load_i8(ctx.v52.u8), simd::load_i8(ctx.v0.u8)));
	// stvlx128 v45,r29,r11
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v45), 15 - i));
}
	// vperm128 v37,v51,v50,v0
	simd::store_i8(ctx.v37.u8, simd::permute_bytes(simd::load_i8(ctx.v51.u8), simd::load_i8(ctx.v50.u8), simd::load_i8(ctx.v0.u8)));
	// stvlx128 v44,r29,r10
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v44), 15 - i));
}
	// li r4,144
	ctx.r4.s64 = 144;
	// vperm128 v36,v49,v48,v0
	simd::store_i8(ctx.v36.u8, simd::permute_bytes(simd::load_i8(ctx.v49.u8), simd::load_i8(ctx.v48.u8), simd::load_i8(ctx.v0.u8)));
	// stvlx128 v43,r29,r9
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r9.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v43), 15 - i));
}
	// li r3,160
	ctx.r3.s64 = 160;
	// vperm128 v35,v55,v54,v7
	simd::store_i8(ctx.v35.u8, simd::permute_bytes(simd::load_i8(ctx.v55.u8), simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v7.u8)));
	// stvlx128 v42,r29,r8
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v42), 15 - i));
}
	// li r11,176
	ctx.r11.s64 = 176;
	// vperm128 v34,v53,v52,v7
	simd::store_i8(ctx.v34.u8, simd::permute_bytes(simd::load_i8(ctx.v53.u8), simd::load_i8(ctx.v52.u8), simd::load_i8(ctx.v7.u8)));
	// stvlx128 v41,r29,r7
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v41), 15 - i));
}
	// li r10,192
	ctx.r10.s64 = 192;
	// vperm128 v33,v51,v50,v7
	simd::store_i8(ctx.v33.u8, simd::permute_bytes(simd::load_i8(ctx.v51.u8), simd::load_i8(ctx.v50.u8), simd::load_i8(ctx.v7.u8)));
	// stvlx128 v40,r29,r6
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r6.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v40), 15 - i));
}
	// li r9,208
	ctx.r9.s64 = 208;
	// vperm128 v32,v49,v48,v7
	simd::store_i8(ctx.v32.u8, simd::permute_bytes(simd::load_i8(ctx.v49.u8), simd::load_i8(ctx.v48.u8), simd::load_i8(ctx.v7.u8)));
	// stvlx128 v39,r29,r5
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r5.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v39), 15 - i));
}
	// li r8,224
	ctx.r8.s64 = 224;
	// stvlx128 v38,r29,r4
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v38), 15 - i));
}
	// li r7,240
	ctx.r7.s64 = 240;
	// stvlx128 v37,r29,r3
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r3.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v37), 15 - i));
}
	// stvlx128 v36,r29,r11
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v36), 15 - i));
}
	// stvlx128 v35,r29,r10
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v35), 15 - i));
}
	// stvlx128 v34,r29,r9
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r9.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v34), 15 - i));
}
	// stvlx128 v33,r29,r8
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v33), 15 - i));
}
	// stvlx128 v32,r29,r7
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v32), 15 - i));
}
	// b 0x8233e4a8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238D448"))) PPC_WEAK_FUNC(sub_8238D448);
PPC_FUNC_IMPL(__imp__sub_8238D448) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e458
	ctx.lr = 0x8238D450;
	__restfpr_24(ctx, base);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// lwz r11,36(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r9,-16
	ctx.r9.s64 = -16;
	// lwz r29,24(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r10,1728
	ctx.r8.s64 = ctx.r10.s64 + 1728;
	// lwz r10,32(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// clrlwi r7,r11,28
	ctx.r7.u64 = ctx.r11.u32 & 0xF;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// li r30,16
	ctx.r30.s64 = 16;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// lvlx v0,r8,r9
	temp.u32 = ctx.r8.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v0,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx v7,0,r8
	temp.u32 = ctx.r0.u32 + ctx.r8.u32;
	simd::store_shuffled(ctx.v7,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r6,r10,r6
	ctx.r6.u64 = ctx.r10.u64 + ctx.r6.u64;
	// bne cr6,0x8238d538
	if (!ctx.cr6.eq) goto loc_8238D538;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx v10,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v10,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lvlx v13,0,r11
	temp.u32 = ctx.r0.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v13,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx v12,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v12,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// rlwinm r27,r10,1,0,30
	ctx.r27.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx v8,r5,r11
	temp.u32 = ctx.r5.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v8,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r4,r10,3,0,28
	ctx.r4.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx v11,r27,r11
	temp.u32 = ctx.r27.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v11,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lvlx v6,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v6,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r31,r10,3,0,28
	ctx.r31.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx v3,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v3,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// subf r4,r10,r4
	ctx.r4.s64 = ctx.r4.s64 - ctx.r10.s64;
	// lvlx v2,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v2,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r28,r10,4,0,27
	ctx.r28.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r26,r10,2,0,29
	ctx.r26.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r31,r10,r31
	ctx.r31.s64 = ctx.r31.s64 - ctx.r10.s64;
	// rlwinm r27,r10,3,0,28
	ctx.r27.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mulli r6,r10,11
	ctx.r6.s64 = ctx.r10.s64 * 11;
	// lvlx v31,r5,r11
	temp.u32 = ctx.r5.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v31,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v9,r26,r11
	temp.u32 = ctx.r26.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v9,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v5,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v5,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v4,r27,r11
	temp.u32 = ctx.r27.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v4,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v1,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v1,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// mulli r3,r10,13
	ctx.r3.s64 = ctx.r10.s64 * 13;
	// lvlx v30,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v30,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = rotl64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r10,r28
	ctx.r8.s64 = ctx.r28.s64 - ctx.r10.s64;
	// rlwinm r7,r10,4,0,27
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lvlx v29,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v29,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v28,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v28,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v27,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v27,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// b 0x8238d6ac
	goto loc_8238D6AC;
loc_8238D538:
	// rlwinm r4,r10,2,0,29
	ctx.r4.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx128 v62,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r28,r10,r8
	ctx.r28.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lvlx128 v63,r0,r11
	temp.u32 = ctx.r0.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v63,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// lvrx128 v61,r30,r11
	temp.u32 = ctx.r30.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v61.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r7,r10,3,0,28
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// vor128 v13,v63,v61
	simd::store_i8(ctx.v13.u8, simd::or_i8(simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v61.u8)));
	// rlwinm r27,r10,3,0,28
	ctx.r27.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// rlwinm r31,r3,1,0,30
	ctx.r31.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v59,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v59,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// rlwinm r5,r10,1,0,30
	ctx.r5.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r3,r10,r27
	ctx.r3.s64 = ctx.r27.s64 - ctx.r10.s64;
	// addi r27,r10,4
	ctx.r27.s64 = ctx.r10.s64 + 4;
	// lvlx128 v60,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r9,r10,r5
	ctx.r9.u64 = ctx.r10.u64 + ctx.r5.u64;
	// lvlx128 v57,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvrx128 v52,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v52.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r8,r27,2,0,29
	ctx.r8.u64 = rotl64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// vor128 v8,v59,v52
	simd::store_i8(ctx.v8.u8, simd::or_i8(simd::load_i8(ctx.v59.u8), simd::load_i8(ctx.v52.u8)));
	// lvlx128 v56,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r4,r28,1,0,30
	ctx.r4.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r3,16
	ctx.r3.s64 = ctx.r3.s64 + 16;
	// lvlx128 v58,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// addi r28,r10,8
	ctx.r28.s64 = ctx.r10.s64 + 8;
	// lvrx128 v46,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v46.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r8,r4,16
	ctx.r8.s64 = ctx.r4.s64 + 16;
	// lvrx128 v51,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v51.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// mulli r5,r10,11
	ctx.r5.s64 = ctx.r10.s64 * 11;
	// lvlx128 v55,r4,r11
	temp.u32 = ctx.r4.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v55,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvrx128 v43,r3,r11
	temp.u32 = ctx.r3.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v43.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v3,v60,v51
	simd::store_i8(ctx.v3.u8, simd::or_i8(simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v51.u8)));
	// lvrx128 v47,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v47.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v5,v56,v43
	simd::store_i8(ctx.v5.u8, simd::or_i8(simd::load_i8(ctx.v56.u8), simd::load_i8(ctx.v43.u8)));
	// vor128 v10,v58,v47
	simd::store_i8(ctx.v10.u8, simd::or_i8(simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v47.u8)));
	// lvrx128 v40,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v40.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvlx128 v54,r5,r11
	temp.u32 = ctx.r5.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v54,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v2,v55,v40
	simd::store_i8(ctx.v2.u8, simd::or_i8(simd::load_i8(ctx.v55.u8), simd::load_i8(ctx.v40.u8)));
	// rlwinm r28,r28,1,0,30
	ctx.r28.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r10,3,0,28
	ctx.r3.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = rotl64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r10,3,0,28
	ctx.r9.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r26,r10,2
	ctx.r26.s64 = ctx.r10.s64 + 2;
	// lvrx128 v49,r28,r11
	temp.u32 = ctx.r28.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v49.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// subf r8,r10,r3
	ctx.r8.s64 = ctx.r3.s64 - ctx.r10.s64;
	// lvlx128 v45,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v45,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r25,r10,16
	ctx.r25.s64 = ctx.r10.s64 + 16;
	// vor128 v9,v45,v46
	simd::store_i8(ctx.v9.u8, simd::or_i8(simd::load_i8(ctx.v45.u8), simd::load_i8(ctx.v46.u8)));
	// rlwinm r24,r10,1,0,30
	ctx.r24.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v53,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v53,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r4,r6,16
	ctx.r4.s64 = ctx.r6.s64 + 16;
	// lvlx128 v41,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v41,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// rlwinm r28,r26,3,0,28
	ctx.r28.u64 = rotl64(ctx.r26.u32 | (ctx.r26.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r5,r5,16
	ctx.r5.s64 = ctx.r5.s64 + 16;
	// lvrx128 v50,r25,r11
	temp.u32 = ctx.r25.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v50.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// mulli r7,r10,13
	ctx.r7.s64 = ctx.r10.s64 * 13;
	// lvlx128 v48,r24,r11
	temp.u32 = ctx.r24.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v48,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvrx128 v38,r4,r11
	temp.u32 = ctx.r4.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v38.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v12,v62,v50
	simd::store_i8(ctx.v12.u8, simd::or_i8(simd::load_i8(ctx.v62.u8), simd::load_i8(ctx.v50.u8)));
	// lvrx128 v44,r31,r11
	temp.u32 = ctx.r31.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v44.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v11,v48,v49
	simd::store_i8(ctx.v11.u8, simd::or_i8(simd::load_i8(ctx.v48.u8), simd::load_i8(ctx.v49.u8)));
	// lvrx128 v42,r28,r11
	temp.u32 = ctx.r28.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v42.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v6,v57,v44
	simd::store_i8(ctx.v6.u8, simd::or_i8(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v44.u8)));
	// lvrx128 v39,r5,r11
	temp.u32 = ctx.r5.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v39.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v4,v41,v42
	simd::store_i8(ctx.v4.u8, simd::or_i8(simd::load_i8(ctx.v41.u8), simd::load_i8(ctx.v42.u8)));
	// lvlx128 v37,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v37,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v1,v54,v39
	simd::store_i8(ctx.v1.u8, simd::or_i8(simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v39.u8)));
	// vor128 v31,v53,v38
	simd::store_i8(ctx.v31.u8, simd::or_i8(simd::load_i8(ctx.v53.u8), simd::load_i8(ctx.v38.u8)));
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// subf r9,r10,r9
	ctx.r9.s64 = ctx.r9.s64 - ctx.r10.s64;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lvlx128 v36,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v36,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r6,r8,16
	ctx.r6.s64 = ctx.r8.s64 + 16;
	// addi r5,r9,16
	ctx.r5.s64 = ctx.r9.s64 + 16;
	// lvlx128 v35,r9,r11
	temp.u32 = ctx.r9.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v35,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r4,r10,16
	ctx.r4.s64 = ctx.r10.s64 + 16;
	// lvlx128 v34,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simd::store_shuffled(ctx.v34,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvrx128 v33,r7,r11
	temp.u32 = ctx.r7.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v33.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvrx128 v32,r6,r11
	temp.u32 = ctx.r6.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v32.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v30,v37,v33
	simd::store_i8(ctx.v30.u8, simd::or_i8(simd::load_i8(ctx.v37.u8), simd::load_i8(ctx.v33.u8)));
	// vor128 v29,v36,v32
	simd::store_i8(ctx.v29.u8, simd::or_i8(simd::load_i8(ctx.v36.u8), simd::load_i8(ctx.v32.u8)));
	// lvrx128 v63,r5,r11
	temp.u32 = ctx.r5.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v63.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvrx128 v62,r4,r11
	temp.u32 = ctx.r4.u32 + ctx.r11.u32;
	simd::store_i8(ctx.v62.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v28,v35,v63
	simd::store_i8(ctx.v28.u8, simd::or_i8(simd::load_i8(ctx.v35.u8), simd::load_i8(ctx.v63.u8)));
	// vor128 v27,v34,v62
	simd::store_i8(ctx.v27.u8, simd::or_i8(simd::load_i8(ctx.v34.u8), simd::load_i8(ctx.v62.u8)));
loc_8238D6AC:
	// vavgub v13,v13,v12
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v12.u8)));
	// li r11,32
	ctx.r11.s64 = 32;
	// vavgub v12,v12,v11
	simd::store_u8(ctx.v12.u8, simd::avg_u8(simd::load_u8(ctx.v12.u8), simd::load_u8(ctx.v11.u8)));
	// li r10,48
	ctx.r10.s64 = 48;
	// vavgub v11,v11,v10
	simd::store_u8(ctx.v11.u8, simd::avg_u8(simd::load_u8(ctx.v11.u8), simd::load_u8(ctx.v10.u8)));
	// li r9,64
	ctx.r9.s64 = 64;
	// vavgub v10,v10,v9
	simd::store_u8(ctx.v10.u8, simd::avg_u8(simd::load_u8(ctx.v10.u8), simd::load_u8(ctx.v9.u8)));
	// li r8,80
	ctx.r8.s64 = 80;
	// vavgub v9,v9,v8
	simd::store_u8(ctx.v9.u8, simd::avg_u8(simd::load_u8(ctx.v9.u8), simd::load_u8(ctx.v8.u8)));
	// li r7,96
	ctx.r7.s64 = 96;
	// vperm128 v61,v13,v12,v0
	simd::store_i8(ctx.v61.u8, simd::permute_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v0.u8)));
	// vavgub v8,v8,v6
	simd::store_u8(ctx.v8.u8, simd::avg_u8(simd::load_u8(ctx.v8.u8), simd::load_u8(ctx.v6.u8)));
	// vperm128 v60,v13,v12,v7
	simd::store_i8(ctx.v60.u8, simd::permute_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v7.u8)));
	// vavgub v6,v6,v5
	simd::store_u8(ctx.v6.u8, simd::avg_u8(simd::load_u8(ctx.v6.u8), simd::load_u8(ctx.v5.u8)));
	// vavgub v13,v5,v4
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v5.u8), simd::load_u8(ctx.v4.u8)));
	// vperm128 v59,v11,v10,v0
	simd::store_i8(ctx.v59.u8, simd::permute_bytes(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8), simd::load_i8(ctx.v0.u8)));
	// vperm128 v58,v11,v10,v7
	simd::store_i8(ctx.v58.u8, simd::permute_bytes(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8), simd::load_i8(ctx.v7.u8)));
	// vavgub v12,v4,v3
	simd::store_u8(ctx.v12.u8, simd::avg_u8(simd::load_u8(ctx.v4.u8), simd::load_u8(ctx.v3.u8)));
	// vavgub v11,v3,v2
	simd::store_u8(ctx.v11.u8, simd::avg_u8(simd::load_u8(ctx.v3.u8), simd::load_u8(ctx.v2.u8)));
	// vperm128 v57,v9,v8,v0
	simd::store_i8(ctx.v57.u8, simd::permute_bytes(simd::load_i8(ctx.v9.u8), simd::load_i8(ctx.v8.u8), simd::load_i8(ctx.v0.u8)));
	// vperm128 v56,v9,v8,v7
	simd::store_i8(ctx.v56.u8, simd::permute_bytes(simd::load_i8(ctx.v9.u8), simd::load_i8(ctx.v8.u8), simd::load_i8(ctx.v7.u8)));
	// vavgub v10,v2,v1
	simd::store_u8(ctx.v10.u8, simd::avg_u8(simd::load_u8(ctx.v2.u8), simd::load_u8(ctx.v1.u8)));
	// vperm128 v55,v6,v13,v0
	simd::store_i8(ctx.v55.u8, simd::permute_bytes(simd::load_i8(ctx.v6.u8), simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v0.u8)));
	// vavgub v9,v1,v31
	simd::store_u8(ctx.v9.u8, simd::avg_u8(simd::load_u8(ctx.v1.u8), simd::load_u8(ctx.v31.u8)));
	// vperm128 v54,v6,v13,v7
	simd::store_i8(ctx.v54.u8, simd::permute_bytes(simd::load_i8(ctx.v6.u8), simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v7.u8)));
	// vavgub v13,v31,v30
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v31.u8), simd::load_u8(ctx.v30.u8)));
	// vperm128 v53,v12,v11,v0
	simd::store_i8(ctx.v53.u8, simd::permute_bytes(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v0.u8)));
	// vavgub v8,v30,v29
	simd::store_u8(ctx.v8.u8, simd::avg_u8(simd::load_u8(ctx.v30.u8), simd::load_u8(ctx.v29.u8)));
	// vperm128 v52,v12,v11,v7
	simd::store_i8(ctx.v52.u8, simd::permute_bytes(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v7.u8)));
	// vavgub v6,v29,v28
	simd::store_u8(ctx.v6.u8, simd::avg_u8(simd::load_u8(ctx.v29.u8), simd::load_u8(ctx.v28.u8)));
	// vavgub v12,v28,v27
	simd::store_u8(ctx.v12.u8, simd::avg_u8(simd::load_u8(ctx.v28.u8), simd::load_u8(ctx.v27.u8)));
	// stvlx128 v61,r0,r29
{
	uint32_t addr = 
ctx.r29.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v61), 15 - i));
}
	// stvlx128 v59,r29,r30
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r30.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v59), 15 - i));
}
	// li r6,112
	ctx.r6.s64 = 112;
	// vperm128 v51,v10,v9,v0
	simd::store_i8(ctx.v51.u8, simd::permute_bytes(simd::load_i8(ctx.v10.u8), simd::load_i8(ctx.v9.u8), simd::load_i8(ctx.v0.u8)));
	// stvlx128 v57,r29,r11
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v57), 15 - i));
}
	// li r5,128
	ctx.r5.s64 = 128;
	// vperm128 v50,v13,v8,v0
	simd::store_i8(ctx.v50.u8, simd::permute_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v8.u8), simd::load_i8(ctx.v0.u8)));
	// stvlx128 v55,r29,r10
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v55), 15 - i));
}
	// li r4,144
	ctx.r4.s64 = 144;
	// vperm128 v49,v6,v12,v0
	simd::store_i8(ctx.v49.u8, simd::permute_bytes(simd::load_i8(ctx.v6.u8), simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v0.u8)));
	// stvlx128 v60,r29,r9
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r9.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v60), 15 - i));
}
	// li r3,160
	ctx.r3.s64 = 160;
	// stvlx128 v58,r29,r8
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v58), 15 - i));
}
	// li r11,176
	ctx.r11.s64 = 176;
	// vperm128 v48,v10,v9,v7
	simd::store_i8(ctx.v48.u8, simd::permute_bytes(simd::load_i8(ctx.v10.u8), simd::load_i8(ctx.v9.u8), simd::load_i8(ctx.v7.u8)));
	// stvlx128 v56,r29,r7
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v56), 15 - i));
}
	// li r10,192
	ctx.r10.s64 = 192;
	// vperm128 v47,v13,v8,v7
	simd::store_i8(ctx.v47.u8, simd::permute_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v8.u8), simd::load_i8(ctx.v7.u8)));
	// stvlx128 v54,r29,r6
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r6.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v54), 15 - i));
}
	// li r9,208
	ctx.r9.s64 = 208;
	// vperm128 v46,v6,v12,v7
	simd::store_i8(ctx.v46.u8, simd::permute_bytes(simd::load_i8(ctx.v6.u8), simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v7.u8)));
	// stvlx128 v53,r29,r5
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r5.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v53), 15 - i));
}
	// li r8,224
	ctx.r8.s64 = 224;
	// stvlx128 v51,r29,r4
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v51), 15 - i));
}
	// li r7,240
	ctx.r7.s64 = 240;
	// stvlx128 v50,r29,r3
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r3.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v50), 15 - i));
}
	// stvlx128 v49,r29,r11
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v49), 15 - i));
}
	// stvlx128 v52,r29,r10
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v52), 15 - i));
}
	// stvlx128 v48,r29,r9
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r9.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v48), 15 - i));
}
	// stvlx128 v47,r29,r8
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v47), 15 - i));
}
	// stvlx128 v46,r29,r7
{
	uint32_t addr = 
ctx.r29.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v46), 15 - i));
}
	// b 0x8233e4a8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238D7A8"))) PPC_WEAK_FUNC(sub_8238D7A8);
PPC_FUNC_IMPL(__imp__sub_8238D7A8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e440
	ctx.lr = 0x8238D7B0;
	__restfpr_18(ctx, base);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r9,-16
	ctx.r9.s64 = -16;
	// lwz r23,24(r3)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r11,1728
	ctx.r8.s64 = ctx.r11.s64 + 1728;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// clrlwi r7,r10,28
	ctx.r7.u64 = ctx.r10.u32 & 0xF;
	// li r24,16
	ctx.r24.s64 = 16;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx v0,r8,r9
	temp.u32 = ctx.r8.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v0,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v7,0,r8
	temp.u32 = ctx.r0.u32 + ctx.r8.u32;
	simd::store_shuffled(ctx.v7,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// bne cr6,0x8238d8a0
	if (!ctx.cr6.eq) goto loc_8238D8A0;
	// rlwinm r9,r11,3,0,28
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx v27,0,r10
	temp.u32 = ctx.r0.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v27,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r31,r11,4,0,27
	ctx.r31.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lvlx v26,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v26,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// subf r3,r11,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r11.s64;
	// lvlx v22,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v22,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// subf r28,r11,r31
	ctx.r28.s64 = ctx.r31.s64 - ctx.r11.s64;
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// rlwinm r29,r3,1,0,30
	ctx.r29.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r3,r1,-160
	ctx.r3.s64 = ctx.r1.s64 + -160;
	// rlwinm r4,r11,2,0,29
	ctx.r4.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx128 v62,r28,r10
	temp.u32 = ctx.r28.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 + ctx.r6.u64;
	// stvx128 v62,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v62), &VectorMaskL[(ea & 0xF) * 16]);
	// add r30,r11,r7
	ctx.r30.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lvlx128 v63,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v63,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r25,r11,3,0,28
	ctx.r25.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v63), &VectorMaskL[(ea & 0xF) * 16]);
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 + ctx.r4.u64;
	// rlwinm r7,r6,1,0,30
	ctx.r7.u64 = rotl64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r6,r11,r25
	ctx.r6.s64 = ctx.r25.s64 - ctx.r11.s64;
	// rlwinm r31,r30,2,0,29
	ctx.r31.u64 = rotl64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r27,r11,1,0,30
	ctx.r27.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r26,r11,2,0,29
	ctx.r26.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx v21,r7,r10
	temp.u32 = ctx.r7.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v21,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r25,r11,3,0,28
	ctx.r25.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx v20,r6,r10
	temp.u32 = ctx.r6.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v20,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// lvlx v15,r31,r10
	temp.u32 = ctx.r31.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v15,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r4,r4,1,0,30
	ctx.r4.u64 = rotl64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx v25,r27,r10
	temp.u32 = ctx.r27.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v25,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// mulli r3,r11,11
	ctx.r3.s64 = ctx.r11.s64 * 11;
	// lvlx v24,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v24,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v23,r26,r10
	temp.u32 = ctx.r26.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v23,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v19,r25,r10
	temp.u32 = ctx.r25.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v19,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v18,r5,r10
	temp.u32 = ctx.r5.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v18,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v17,r4,r10
	temp.u32 = ctx.r4.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v17,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v16,r3,r10
	temp.u32 = ctx.r3.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v16,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// mulli r30,r11,13
	ctx.r30.s64 = ctx.r11.s64 * 13;
	// lvlx v14,r30,r10
	temp.u32 = ctx.r30.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v14,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// b 0x8238da18
	goto loc_8238DA18;
loc_8238D8A0:
	// rlwinm r5,r11,1,0,30
	ctx.r5.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v61,r0,r10
	temp.u32 = ctx.r0.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v61,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r29,r11,4
	ctx.r29.s64 = ctx.r11.s64 + 4;
	// lvlx128 v60,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r4,r11,r5
	ctx.r4.u64 = ctx.r11.u64 + ctx.r5.u64;
	// lvrx128 v59,r24,r10
	temp.u32 = ctx.r24.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v59.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r29,r29,2,0,29
	ctx.r29.u64 = rotl64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx128 v57,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r5,r11,3,0,28
	ctx.r5.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// vor128 v27,v61,v59
	simd::store_i8(ctx.v27.u8, simd::or_i8(simd::load_i8(ctx.v61.u8), simd::load_i8(ctx.v59.u8)));
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lvrx128 v45,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v45.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// add r3,r11,r6
	ctx.r3.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rlwinm r30,r30,1,0,30
	ctx.r30.u64 = rotl64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r31,r11,r7
	ctx.r31.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r29,r5,16
	ctx.r29.s64 = ctx.r5.s64 + 16;
	// lvlx128 v54,r5,r10
	temp.u32 = ctx.r5.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v54,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r6,r11,3,0,28
	ctx.r6.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r7,r4,1,0,30
	ctx.r7.u64 = rotl64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lvrx128 v48,r30,r10
	temp.u32 = ctx.r30.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v48.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// subf r6,r11,r6
	ctx.r6.s64 = ctx.r6.s64 - ctx.r11.s64;
	// addi r25,r11,16
	ctx.r25.s64 = ctx.r11.s64 + 16;
	// lvrx128 v39,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v39.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r22,r9,16
	ctx.r22.s64 = ctx.r9.s64 + 16;
	// vor128 v18,v54,v39
	simd::store_i8(ctx.v18.u8, simd::or_i8(simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v39.u8)));
	// addi r21,r8,16
	ctx.r21.s64 = ctx.r8.s64 + 16;
	// lvlx128 v56,r7,r10
	temp.u32 = ctx.r7.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r20,r7,16
	ctx.r20.s64 = ctx.r7.s64 + 16;
	// lvlx128 v58,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r30,r6,16
	ctx.r30.s64 = ctx.r6.s64 + 16;
	// lvlx128 v55,r6,r10
	temp.u32 = ctx.r6.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v55,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r28,r11,2
	ctx.r28.s64 = ctx.r11.s64 + 2;
	// lvrx128 v50,r25,r10
	temp.u32 = ctx.r25.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v50.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r4,r3,1,0,30
	ctx.r4.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lvrx128 v47,r22,r10
	temp.u32 = ctx.r22.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v47.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r29,r11,3,0,28
	ctx.r29.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lvrx128 v44,r21,r10
	temp.u32 = ctx.r21.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v44.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// mulli r3,r11,11
	ctx.r3.s64 = ctx.r11.s64 * 11;
	// lvrx128 v43,r20,r10
	temp.u32 = ctx.r20.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v43.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvrx128 v42,r30,r10
	temp.u32 = ctx.r30.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v42.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v26,v60,v50
	simd::store_i8(ctx.v26.u8, simd::or_i8(simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v50.u8)));
	// vor128 v24,v58,v47
	simd::store_i8(ctx.v24.u8, simd::or_i8(simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v47.u8)));
	// lvlx128 v53,r4,r10
	temp.u32 = ctx.r4.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v53,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v22,v57,v44
	simd::store_i8(ctx.v22.u8, simd::or_i8(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v44.u8)));
	// vor128 v21,v56,v43
	simd::store_i8(ctx.v21.u8, simd::or_i8(simd::load_i8(ctx.v56.u8), simd::load_i8(ctx.v43.u8)));
	// lvlx128 v52,r3,r10
	temp.u32 = ctx.r3.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v52,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v20,v55,v42
	simd::store_i8(ctx.v20.u8, simd::or_i8(simd::load_i8(ctx.v55.u8), simd::load_i8(ctx.v42.u8)));
	// rlwinm r31,r31,2,0,29
	ctx.r31.u64 = rotl64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r28,r28,3,0,28
	ctx.r28.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r29,r11,r29
	ctx.r29.s64 = ctx.r29.s64 - ctx.r11.s64;
	// addi r22,r4,16
	ctx.r22.s64 = ctx.r4.s64 + 16;
	// rlwinm r27,r11,1,0,30
	ctx.r27.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r26,r11,2,0,29
	ctx.r26.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx128 v51,r31,r10
	temp.u32 = ctx.r31.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v51,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r25,r11,3,0,28
	ctx.r25.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lvrx128 v40,r28,r10
	temp.u32 = ctx.r28.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v40.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r21,r3,16
	ctx.r21.s64 = ctx.r3.s64 + 16;
	// addi r20,r31,16
	ctx.r20.s64 = ctx.r31.s64 + 16;
	// lvrx128 v38,r22,r10
	temp.u32 = ctx.r22.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v38.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r29,r29,1,0,30
	ctx.r29.u64 = rotl64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v49,r27,r10
	temp.u32 = ctx.r27.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v49,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// mulli r30,r11,13
	ctx.r30.s64 = ctx.r11.s64 * 13;
	// lvlx128 v46,r26,r10
	temp.u32 = ctx.r26.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v46,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v41,r25,r10
	temp.u32 = ctx.r25.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v41,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v25,v49,v48
	simd::store_i8(ctx.v25.u8, simd::or_i8(simd::load_i8(ctx.v49.u8), simd::load_i8(ctx.v48.u8)));
	// lvrx128 v37,r21,r10
	temp.u32 = ctx.r21.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v37.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v23,v46,v45
	simd::store_i8(ctx.v23.u8, simd::or_i8(simd::load_i8(ctx.v46.u8), simd::load_i8(ctx.v45.u8)));
	// lvrx128 v36,r20,r10
	temp.u32 = ctx.r20.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v36.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v19,v41,v40
	simd::store_i8(ctx.v19.u8, simd::or_i8(simd::load_i8(ctx.v41.u8), simd::load_i8(ctx.v40.u8)));
	// lvlx128 v34,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v34,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v17,v53,v38
	simd::store_i8(ctx.v17.u8, simd::or_i8(simd::load_i8(ctx.v53.u8), simd::load_i8(ctx.v38.u8)));
	// lvlx128 v35,r30,r10
	temp.u32 = ctx.r30.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v35,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v16,v52,v37
	simd::store_i8(ctx.v16.u8, simd::or_i8(simd::load_i8(ctx.v52.u8), simd::load_i8(ctx.v37.u8)));
	// vor128 v15,v51,v36
	simd::store_i8(ctx.v15.u8, simd::or_i8(simd::load_i8(ctx.v51.u8), simd::load_i8(ctx.v36.u8)));
	// rlwinm r28,r11,4,0,27
	ctx.r28.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r22,r29,16
	ctx.r22.s64 = ctx.r29.s64 + 16;
	// subf r28,r11,r28
	ctx.r28.s64 = ctx.r28.s64 - ctx.r11.s64;
	// addi r21,r28,16
	ctx.r21.s64 = ctx.r28.s64 + 16;
	// lvlx128 v33,r28,r10
	temp.u32 = ctx.r28.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v33,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r20,r30,16
	ctx.r20.s64 = ctx.r30.s64 + 16;
	// lvrx128 v32,r22,r10
	temp.u32 = ctx.r22.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v32.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r19,r1,-160
	ctx.r19.s64 = ctx.r1.s64 + -160;
	// vor128 v62,v34,v32
	simd::store_i8(ctx.v62.u8, simd::or_i8(simd::load_i8(ctx.v34.u8), simd::load_i8(ctx.v32.u8)));
	// addi r18,r1,-144
	ctx.r18.s64 = ctx.r1.s64 + -144;
	// lvrx128 v63,r21,r10
	temp.u32 = ctx.r21.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v63.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v61,v33,v63
	simd::store_i8(ctx.v61.u8, simd::or_i8(simd::load_i8(ctx.v33.u8), simd::load_i8(ctx.v63.u8)));
	// lvrx128 v60,r20,r10
	temp.u32 = ctx.r20.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v60.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v14,v35,v60
	simd::store_i8(ctx.v14.u8, simd::or_i8(simd::load_i8(ctx.v35.u8), simd::load_i8(ctx.v60.u8)));
	// stvx128 v62,r0,r19
	ea = (ctx.r19.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v62), &VectorMaskL[(ea & 0xF) * 16]);
	// stvx128 v61,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v61), &VectorMaskL[(ea & 0xF) * 16]);
loc_8238DA18:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r22,r10,28
	ctx.r22.u64 = ctx.r10.u32 & 0xF;
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// bne cr6,0x8238da6c
	if (!ctx.cr6.eq) goto loc_8238DA6C;
	// lvlx v13,0,r10
	temp.u32 = ctx.r0.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v13,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v12,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v12,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v11,r27,r10
	temp.u32 = ctx.r27.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v11,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v10,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v10,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v9,r26,r10
	temp.u32 = ctx.r26.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v9,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v8,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v8,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v6,r7,r10
	temp.u32 = ctx.r7.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v6,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v5,r6,r10
	temp.u32 = ctx.r6.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v5,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v4,r25,r10
	temp.u32 = ctx.r25.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v4,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v3,r5,r10
	temp.u32 = ctx.r5.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v3,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v2,r4,r10
	temp.u32 = ctx.r4.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v2,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v1,r3,r10
	temp.u32 = ctx.r3.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v1,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v31,r31,r10
	temp.u32 = ctx.r31.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v31,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v30,r30,r10
	temp.u32 = ctx.r30.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v30,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v29,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v29,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v28,r28,r10
	temp.u32 = ctx.r28.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v28,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// b 0x8238db74
	goto loc_8238DB74;
loc_8238DA6C:
	// lvlx128 v58,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r22,r11,8
	ctx.r22.s64 = ctx.r11.s64 + 8;
	// addi r21,r11,4
	ctx.r21.s64 = ctx.r11.s64 + 4;
	// lvlx128 v57,r27,r10
	temp.u32 = ctx.r27.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r20,r11,2
	ctx.r20.s64 = ctx.r11.s64 + 2;
	// lvlx128 v56,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// lvlx128 v55,r26,r10
	temp.u32 = ctx.r26.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v55,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v54,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v54,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r27,r22,1,0,30
	ctx.r27.u64 = rotl64(ctx.r22.u32 | (ctx.r22.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v53,r7,r10
	temp.u32 = ctx.r7.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v53,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lvlx128 v52,r6,r10
	temp.u32 = ctx.r6.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v52,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r26,r21,2,0,29
	ctx.r26.u64 = rotl64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// lvlx128 v59,r0,r10
	temp.u32 = ctx.r0.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v59,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvrx128 v50,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v50.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// lvrx128 v49,r27,r10
	temp.u32 = ctx.r27.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v49.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r11,r20,3,0,28
	ctx.r11.u64 = rotl64(ctx.r20.u32 | (ctx.r20.u64 << 32), 3) & 0xFFFFFFF8;
	// lvrx128 v48,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v48.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvrx128 v47,r26,r10
	temp.u32 = ctx.r26.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v47.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r27,r5,16
	ctx.r27.s64 = ctx.r5.s64 + 16;
	// lvrx128 v46,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v46.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r9,r4,16
	ctx.r9.s64 = ctx.r4.s64 + 16;
	// lvrx128 v45,r7,r10
	temp.u32 = ctx.r7.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v45.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r26,r3,16
	ctx.r26.s64 = ctx.r3.s64 + 16;
	// lvrx128 v44,r6,r10
	temp.u32 = ctx.r6.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v44.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r8,r31,16
	ctx.r8.s64 = ctx.r31.s64 + 16;
	// lvrx128 v43,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v43.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r7,r30,16
	ctx.r7.s64 = ctx.r30.s64 + 16;
	// addi r6,r29,16
	ctx.r6.s64 = ctx.r29.s64 + 16;
	// lvrx128 v51,r24,r10
	temp.u32 = ctx.r24.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v51.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r11,r28,16
	ctx.r11.s64 = ctx.r28.s64 + 16;
	// lvlx128 v42,r25,r10
	temp.u32 = ctx.r25.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v42,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvrx128 v41,r27,r10
	temp.u32 = ctx.r27.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v41.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v13,v59,v51
	simd::store_i8(ctx.v13.u8, simd::or_i8(simd::load_i8(ctx.v59.u8), simd::load_i8(ctx.v51.u8)));
	// lvlx128 v40,r5,r10
	temp.u32 = ctx.r5.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v40,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v12,v58,v50
	simd::store_i8(ctx.v12.u8, simd::or_i8(simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v50.u8)));
	// lvrx128 v39,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v39.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v11,v57,v49
	simd::store_i8(ctx.v11.u8, simd::or_i8(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v49.u8)));
	// lvlx128 v38,r4,r10
	temp.u32 = ctx.r4.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v38,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v10,v56,v48
	simd::store_i8(ctx.v10.u8, simd::or_i8(simd::load_i8(ctx.v56.u8), simd::load_i8(ctx.v48.u8)));
	// lvrx128 v37,r26,r10
	temp.u32 = ctx.r26.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v37.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v9,v55,v47
	simd::store_i8(ctx.v9.u8, simd::or_i8(simd::load_i8(ctx.v55.u8), simd::load_i8(ctx.v47.u8)));
	// lvlx128 v36,r3,r10
	temp.u32 = ctx.r3.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v36,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v8,v54,v46
	simd::store_i8(ctx.v8.u8, simd::or_i8(simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v46.u8)));
	// lvrx128 v35,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v35.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v6,v53,v45
	simd::store_i8(ctx.v6.u8, simd::or_i8(simd::load_i8(ctx.v53.u8), simd::load_i8(ctx.v45.u8)));
	// lvlx128 v34,r31,r10
	temp.u32 = ctx.r31.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v34,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v5,v52,v44
	simd::store_i8(ctx.v5.u8, simd::or_i8(simd::load_i8(ctx.v52.u8), simd::load_i8(ctx.v44.u8)));
	// lvrx128 v33,r7,r10
	temp.u32 = ctx.r7.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v33.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v4,v42,v43
	simd::store_i8(ctx.v4.u8, simd::or_i8(simd::load_i8(ctx.v42.u8), simd::load_i8(ctx.v43.u8)));
	// lvlx128 v32,r30,r10
	temp.u32 = ctx.r30.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v32,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v3,v40,v41
	simd::store_i8(ctx.v3.u8, simd::or_i8(simd::load_i8(ctx.v40.u8), simd::load_i8(ctx.v41.u8)));
	// lvrx128 v63,r6,r10
	temp.u32 = ctx.r6.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v63.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v2,v38,v39
	simd::store_i8(ctx.v2.u8, simd::or_i8(simd::load_i8(ctx.v38.u8), simd::load_i8(ctx.v39.u8)));
	// lvlx128 v62,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v1,v36,v37
	simd::store_i8(ctx.v1.u8, simd::or_i8(simd::load_i8(ctx.v36.u8), simd::load_i8(ctx.v37.u8)));
	// lvrx128 v61,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v61.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v31,v34,v35
	simd::store_i8(ctx.v31.u8, simd::or_i8(simd::load_i8(ctx.v34.u8), simd::load_i8(ctx.v35.u8)));
	// lvlx128 v60,r28,r10
	temp.u32 = ctx.r28.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v30,v32,v33
	simd::store_i8(ctx.v30.u8, simd::or_i8(simd::load_i8(ctx.v32.u8), simd::load_i8(ctx.v33.u8)));
	// vor128 v29,v62,v63
	simd::store_i8(ctx.v29.u8, simd::or_i8(simd::load_i8(ctx.v62.u8), simd::load_i8(ctx.v63.u8)));
	// vor128 v28,v60,v61
	simd::store_i8(ctx.v28.u8, simd::or_i8(simd::load_i8(ctx.v60.u8), simd::load_i8(ctx.v61.u8)));
loc_8238DB74:
	// vavgub v13,v27,v13
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v27.u8), simd::load_u8(ctx.v13.u8)));
	// addi r11,r1,-160
	ctx.r11.s64 = ctx.r1.s64 + -160;
	// vavgub v12,v26,v12
	simd::store_u8(ctx.v12.u8, simd::avg_u8(simd::load_u8(ctx.v26.u8), simd::load_u8(ctx.v12.u8)));
	// addi r10,r1,-144
	ctx.r10.s64 = ctx.r1.s64 + -144;
	// vavgub v11,v25,v11
	simd::store_u8(ctx.v11.u8, simd::avg_u8(simd::load_u8(ctx.v25.u8), simd::load_u8(ctx.v11.u8)));
	// li r9,32
	ctx.r9.s64 = 32;
	// vavgub v10,v24,v10
	simd::store_u8(ctx.v10.u8, simd::avg_u8(simd::load_u8(ctx.v24.u8), simd::load_u8(ctx.v10.u8)));
	// li r8,48
	ctx.r8.s64 = 48;
	// vavgub v9,v23,v9
	simd::store_u8(ctx.v9.u8, simd::avg_u8(simd::load_u8(ctx.v23.u8), simd::load_u8(ctx.v9.u8)));
	// li r7,64
	ctx.r7.s64 = 64;
	// vperm128 v59,v13,v12,v0
	simd::store_i8(ctx.v59.u8, simd::permute_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v0.u8)));
	// stvlx128 v59,r0,r23
{
	uint32_t addr = 
ctx.r23.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v59), 15 - i));
}
	// vperm128 v58,v13,v12,v7
	simd::store_i8(ctx.v58.u8, simd::permute_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v7.u8)));
	// vavgub v8,v22,v8
	simd::store_u8(ctx.v8.u8, simd::avg_u8(simd::load_u8(ctx.v22.u8), simd::load_u8(ctx.v8.u8)));
	// vavgub v6,v21,v6
	simd::store_u8(ctx.v6.u8, simd::avg_u8(simd::load_u8(ctx.v21.u8), simd::load_u8(ctx.v6.u8)));
	// vperm128 v57,v11,v10,v0
	simd::store_i8(ctx.v57.u8, simd::permute_bytes(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8), simd::load_i8(ctx.v0.u8)));
	// vavgub v13,v20,v5
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v20.u8), simd::load_u8(ctx.v5.u8)));
	// vperm128 v56,v11,v10,v7
	simd::store_i8(ctx.v56.u8, simd::permute_bytes(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8), simd::load_i8(ctx.v7.u8)));
	// vavgub v12,v19,v4
	simd::store_u8(ctx.v12.u8, simd::avg_u8(simd::load_u8(ctx.v19.u8), simd::load_u8(ctx.v4.u8)));
	// li r6,80
	ctx.r6.s64 = 80;
	// vperm128 v55,v9,v8,v0
	simd::store_i8(ctx.v55.u8, simd::permute_bytes(simd::load_i8(ctx.v9.u8), simd::load_i8(ctx.v8.u8), simd::load_i8(ctx.v0.u8)));
	// vavgub v11,v18,v3
	simd::store_u8(ctx.v11.u8, simd::avg_u8(simd::load_u8(ctx.v18.u8), simd::load_u8(ctx.v3.u8)));
	// vperm128 v54,v9,v8,v7
	simd::store_i8(ctx.v54.u8, simd::permute_bytes(simd::load_i8(ctx.v9.u8), simd::load_i8(ctx.v8.u8), simd::load_i8(ctx.v7.u8)));
	// vavgub v8,v14,v30
	simd::store_u8(ctx.v8.u8, simd::avg_u8(simd::load_u8(ctx.v14.u8), simd::load_u8(ctx.v30.u8)));
	// vperm128 v53,v6,v13,v0
	simd::store_i8(ctx.v53.u8, simd::permute_bytes(simd::load_i8(ctx.v6.u8), simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v0.u8)));
	// vavgub v10,v17,v2
	simd::store_u8(ctx.v10.u8, simd::avg_u8(simd::load_u8(ctx.v17.u8), simd::load_u8(ctx.v2.u8)));
	// vperm128 v52,v6,v13,v7
	simd::store_i8(ctx.v52.u8, simd::permute_bytes(simd::load_i8(ctx.v6.u8), simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v7.u8)));
	// vavgub v13,v15,v31
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v15.u8), simd::load_u8(ctx.v31.u8)));
	// vperm128 v51,v12,v11,v0
	simd::store_i8(ctx.v51.u8, simd::permute_bytes(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v0.u8)));
	// vavgub v9,v16,v1
	simd::store_u8(ctx.v9.u8, simd::avg_u8(simd::load_u8(ctx.v16.u8), simd::load_u8(ctx.v1.u8)));
	// vperm128 v50,v12,v11,v7
	simd::store_i8(ctx.v50.u8, simd::permute_bytes(simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v7.u8)));
	// li r5,96
	ctx.r5.s64 = 96;
	// li r4,112
	ctx.r4.s64 = 112;
	// vperm128 v47,v13,v8,v0
	simd::store_i8(ctx.v47.u8, simd::permute_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v8.u8), simd::load_i8(ctx.v0.u8)));
	// li r3,128
	ctx.r3.s64 = 128;
	// vperm128 v46,v13,v8,v7
	simd::store_i8(ctx.v46.u8, simd::permute_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v8.u8), simd::load_i8(ctx.v7.u8)));
	// li r31,144
	ctx.r31.s64 = 144;
	// vperm128 v49,v10,v9,v0
	simd::store_i8(ctx.v49.u8, simd::permute_bytes(simd::load_i8(ctx.v10.u8), simd::load_i8(ctx.v9.u8), simd::load_i8(ctx.v0.u8)));
	// li r30,160
	ctx.r30.s64 = 160;
	// vperm128 v48,v10,v9,v7
	simd::store_i8(ctx.v48.u8, simd::permute_bytes(simd::load_i8(ctx.v10.u8), simd::load_i8(ctx.v9.u8), simd::load_i8(ctx.v7.u8)));
	// li r29,176
	ctx.r29.s64 = 176;
	// li r28,192
	ctx.r28.s64 = 192;
	// li r27,208
	ctx.r27.s64 = 208;
	// li r26,224
	ctx.r26.s64 = 224;
	// li r25,240
	ctx.r25.s64 = 240;
	// lvx128 v13,r0,r11
	simd::store_shuffled(ctx.v13, simd::load_and_shuffle(base + ((ctx.r11.u32) & ~0xF), VectorMaskL));
	// lvx128 v12,r0,r10
	simd::store_shuffled(ctx.v12, simd::load_and_shuffle(base + ((ctx.r10.u32) & ~0xF), VectorMaskL));
	// vavgub v6,v13,v29
	simd::store_u8(ctx.v6.u8, simd::avg_u8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v29.u8)));
	// vavgub v12,v12,v28
	simd::store_u8(ctx.v12.u8, simd::avg_u8(simd::load_u8(ctx.v12.u8), simd::load_u8(ctx.v28.u8)));
	// stvlx128 v57,r23,r24
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r24.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v57), 15 - i));
}
	// stvlx128 v55,r23,r9
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r9.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v55), 15 - i));
}
	// stvlx128 v53,r23,r8
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v53), 15 - i));
}
	// stvlx128 v58,r23,r7
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v58), 15 - i));
}
	// vperm128 v45,v6,v12,v0
	simd::store_i8(ctx.v45.u8, simd::permute_bytes(simd::load_i8(ctx.v6.u8), simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v0.u8)));
	// stvlx128 v56,r23,r6
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r6.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v56), 15 - i));
}
	// stvlx128 v54,r23,r5
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r5.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v54), 15 - i));
}
	// vperm128 v44,v6,v12,v7
	simd::store_i8(ctx.v44.u8, simd::permute_bytes(simd::load_i8(ctx.v6.u8), simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v7.u8)));
	// stvlx128 v52,r23,r4
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v52), 15 - i));
}
	// stvlx128 v51,r23,r3
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r3.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v51), 15 - i));
}
	// stvlx128 v49,r23,r31
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r31.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v49), 15 - i));
}
	// stvlx128 v47,r23,r30
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r30.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v47), 15 - i));
}
	// stvlx128 v45,r23,r29
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r29.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v45), 15 - i));
}
	// stvlx128 v50,r23,r28
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r28.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v50), 15 - i));
}
	// stvlx128 v48,r23,r27
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r27.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v48), 15 - i));
}
	// stvlx128 v46,r23,r26
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r26.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v46), 15 - i));
}
	// stvlx128 v44,r23,r25
{
	uint32_t addr = 
ctx.r23.u32 + ctx.r25.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v44), 15 - i));
}
	// b 0x8233e490
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238DC80"))) PPC_WEAK_FUNC(sub_8238DC80);
PPC_FUNC_IMPL(__imp__sub_8238DC80) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e434
	ctx.lr = 0x8238DC88;
	__restfpr_15(ctx, base);
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lwz r10,36(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// li r9,-16
	ctx.r9.s64 = -16;
	// lwz r22,24(r3)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r3.u32 + 24);
	// addi r8,r11,1728
	ctx.r8.s64 = ctx.r11.s64 + 1728;
	// lwz r11,32(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 32);
	// clrlwi r7,r10,28
	ctx.r7.u64 = ctx.r10.u32 & 0xF;
	// vspltisb v0,1
	simd::store_i8(ctx.v0.u8, simd::set1_i8(int8_t(0x1)));
	// li r23,16
	ctx.r23.s64 = 16;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx v7,r8,r9
	temp.u32 = ctx.r8.u32 + ctx.r9.u32;
	simd::store_shuffled(ctx.v7,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx v6,0,r8
	temp.u32 = ctx.r0.u32 + ctx.r8.u32;
	simd::store_shuffled(ctx.v6,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r24,r11,3,0,28
	ctx.r24.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// bne cr6,0x8238ddc4
	if (!ctx.cr6.eq) goto loc_8238DDC4;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v61,r24,r10
	temp.u32 = ctx.r24.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v61,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r31,r11,r8
	ctx.r31.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lvlx v31,0,r10
	temp.u32 = ctx.r0.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v31,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lvlx v30,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v30,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r30,r11,3,0,28
	ctx.r30.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r8,r11,r5
	ctx.r8.u64 = ctx.r11.u64 + ctx.r5.u64;
	// add r21,r11,r9
	ctx.r21.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r5,r11,r4
	ctx.r5.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rlwinm r4,r31,1,0,30
	ctx.r4.u64 = rotl64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r31,r7,2,0,29
	ctx.r31.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx v26,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v26,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// subf r6,r11,r30
	ctx.r6.s64 = ctx.r30.s64 - ctx.r11.s64;
	// addi r7,r1,-304
	ctx.r7.s64 = ctx.r1.s64 + -304;
	// lvlx128 v63,r5,r10
	temp.u32 = ctx.r5.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v63,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// mulli r30,r11,13
	ctx.r30.s64 = ctx.r11.s64 * 13;
	// lvlx v28,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v28,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v60,r4,r10
	temp.u32 = ctx.r4.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v60,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v58,r31,r10
	temp.u32 = ctx.r31.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v58,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v62,r6,r10
	temp.u32 = ctx.r6.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v62,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v62), &VectorMaskL[(ea & 0xF) * 16]);
	// lvlx128 v57,r30,r10
	temp.u32 = ctx.r30.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r26,r1,-288
	ctx.r26.s64 = ctx.r1.s64 + -288;
	// addi r25,r1,-224
	ctx.r25.s64 = ctx.r1.s64 + -224;
	// addi r20,r1,-320
	ctx.r20.s64 = ctx.r1.s64 + -320;
	// addi r7,r1,-272
	ctx.r7.s64 = ctx.r1.s64 + -272;
	// rlwinm r3,r11,3,0,28
	ctx.r3.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r28,r11,4,0,27
	ctx.r28.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// stvx128 v61,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v61), &VectorMaskL[(ea & 0xF) * 16]);
	// subf r29,r11,r3
	ctx.r29.s64 = ctx.r3.s64 - ctx.r11.s64;
	// stvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v63), &VectorMaskL[(ea & 0xF) * 16]);
	// mulli r3,r11,11
	ctx.r3.s64 = ctx.r11.s64 * 11;
	// stvx128 v60,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v60), &VectorMaskL[(ea & 0xF) * 16]);
	// stvx128 v57,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v57), &VectorMaskL[(ea & 0xF) * 16]);
	// lvlx128 v59,r3,r10
	temp.u32 = ctx.r3.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v59,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r29,r29,1,0,30
	ctx.r29.u64 = rotl64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r28,r11,r28
	ctx.r28.s64 = ctx.r28.s64 - ctx.r11.s64;
	// rlwinm r27,r11,4,0,27
	ctx.r27.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r19,r1,-192
	ctx.r19.s64 = ctx.r1.s64 + -192;
	// addi r18,r1,-176
	ctx.r18.s64 = ctx.r1.s64 + -176;
	// addi r17,r1,-240
	ctx.r17.s64 = ctx.r1.s64 + -240;
	// lvlx128 v56,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r16,r1,-208
	ctx.r16.s64 = ctx.r1.s64 + -208;
	// lvlx128 v55,r28,r10
	temp.u32 = ctx.r28.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v55,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r20,r1,-256
	ctx.r20.s64 = ctx.r1.s64 + -256;
	// lvlx128 v54,r27,r10
	temp.u32 = ctx.r27.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v54,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r26,r11,1,0,30
	ctx.r26.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stvx128 v59,r0,r19
	ea = (ctx.r19.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v59), &VectorMaskL[(ea & 0xF) * 16]);
	// rlwinm r25,r11,2,0,29
	ctx.r25.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stvx128 v58,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v58), &VectorMaskL[(ea & 0xF) * 16]);
	// rlwinm r7,r21,1,0,30
	ctx.r7.u64 = rotl64(ctx.r21.u32 | (ctx.r21.u64 << 32), 1) & 0xFFFFFFFE;
	// stvx128 v56,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v56), &VectorMaskL[(ea & 0xF) * 16]);
	// stvx128 v55,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v55), &VectorMaskL[(ea & 0xF) * 16]);
	// stvx128 v54,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v54), &VectorMaskL[(ea & 0xF) * 16]);
	// lvlx v29,r26,r10
	temp.u32 = ctx.r26.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v29,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v27,r25,r10
	temp.u32 = ctx.r25.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v27,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v14,r7,r10
	temp.u32 = ctx.r7.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v14,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// b 0x8238df84
	goto loc_8238DF84;
loc_8238DDC4:
	// rlwinm r7,r11,3,0,28
	ctx.r7.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// lvlx128 v47,r24,r10
	temp.u32 = ctx.r24.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v47,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lvlx128 v53,r0,r10
	temp.u32 = ctx.r0.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v53,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// lvrx128 v51,r23,r10
	temp.u32 = ctx.r23.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v51.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// subf r6,r11,r7
	ctx.r6.s64 = ctx.r7.s64 - ctx.r11.s64;
	// lvlx128 v52,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v52,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r31,r11,2
	ctx.r31.s64 = ctx.r11.s64 + 2;
	// vor128 v31,v53,v51
	simd::store_i8(ctx.v31.u8, simd::or_i8(simd::load_i8(ctx.v53.u8), simd::load_i8(ctx.v51.u8)));
	// addi r29,r6,16
	ctx.r29.s64 = ctx.r6.s64 + 16;
	// rlwinm r31,r31,3,0,28
	ctx.r31.u64 = rotl64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r11,r8
	ctx.r30.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lvlx128 v50,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v50,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v49,r6,r10
	temp.u32 = ctx.r6.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v49,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// add r8,r11,r5
	ctx.r8.u64 = ctx.r11.u64 + ctx.r5.u64;
	// lvrx128 v48,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v48.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r29,r11,8
	ctx.r29.s64 = ctx.r11.s64 + 8;
	// add r5,r11,r4
	ctx.r5.u64 = ctx.r11.u64 + ctx.r4.u64;
	// lvrx128 v46,r31,r10
	temp.u32 = ctx.r31.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v46.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r4,r30,1,0,30
	ctx.r4.u64 = rotl64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// vor128 v45,v49,v48
	simd::store_i8(ctx.v45.u8, simd::or_i8(simd::load_i8(ctx.v49.u8), simd::load_i8(ctx.v48.u8)));
	// add r28,r11,r7
	ctx.r28.u64 = ctx.r11.u64 + ctx.r7.u64;
	// vor128 v44,v47,v46
	simd::store_i8(ctx.v44.u8, simd::or_i8(simd::load_i8(ctx.v47.u8), simd::load_i8(ctx.v46.u8)));
	// rlwinm r29,r29,1,0,30
	ctx.r29.u64 = rotl64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v43,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v43,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r30,r11,16
	ctx.r30.s64 = ctx.r11.s64 + 16;
	// rlwinm r31,r28,2,0,29
	ctx.r31.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// lvlx128 v41,r5,r10
	temp.u32 = ctx.r5.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v41,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r7,r3,1,0,30
	ctx.r7.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v40,r4,r10
	temp.u32 = ctx.r4.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v40,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r27,r11,4
	ctx.r27.s64 = ctx.r11.s64 + 4;
	// addi r28,r9,16
	ctx.r28.s64 = ctx.r9.s64 + 16;
	// lvrx128 v35,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v35.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r27,r27,2,0,29
	ctx.r27.u64 = rotl64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// lvrx128 v37,r30,r10
	temp.u32 = ctx.r30.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v37.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r21,r7,16
	ctx.r21.s64 = ctx.r7.s64 + 16;
	// lvlx128 v38,r31,r10
	temp.u32 = ctx.r31.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v38,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r30,r8,16
	ctx.r30.s64 = ctx.r8.s64 + 16;
	// lvlx128 v42,r7,r10
	temp.u32 = ctx.r7.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v42,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r29,r5,16
	ctx.r29.s64 = ctx.r5.s64 + 16;
	// vor128 v30,v52,v37
	simd::store_i8(ctx.v30.u8, simd::or_i8(simd::load_i8(ctx.v52.u8), simd::load_i8(ctx.v37.u8)));
	// lvrx128 v34,r28,r10
	temp.u32 = ctx.r28.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v34.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// mulli r3,r11,11
	ctx.r3.s64 = ctx.r11.s64 * 11;
	// lvrx128 v32,r27,r10
	temp.u32 = ctx.r27.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v32.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v28,v50,v34
	simd::store_i8(ctx.v28.u8, simd::or_i8(simd::load_i8(ctx.v50.u8), simd::load_i8(ctx.v34.u8)));
	// lvrx128 v62,r21,r10
	temp.u32 = ctx.r21.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v62.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvrx128 v63,r30,r10
	temp.u32 = ctx.r30.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v63.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v14,v42,v62
	simd::store_i8(ctx.v14.u8, simd::or_i8(simd::load_i8(ctx.v42.u8), simd::load_i8(ctx.v62.u8)));
	// lvrx128 v61,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v61.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v26,v43,v63
	simd::store_i8(ctx.v26.u8, simd::or_i8(simd::load_i8(ctx.v43.u8), simd::load_i8(ctx.v63.u8)));
	// lvlx128 v39,r3,r10
	temp.u32 = ctx.r3.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v39,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v56,v41,v61
	simd::store_i8(ctx.v56.u8, simd::or_i8(simd::load_i8(ctx.v41.u8), simd::load_i8(ctx.v61.u8)));
	// addi r28,r1,-304
	ctx.r28.s64 = ctx.r1.s64 + -304;
	// addi r21,r31,16
	ctx.r21.s64 = ctx.r31.s64 + 16;
	// rlwinm r26,r11,1,0,30
	ctx.r26.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r25,r11,2,0,29
	ctx.r25.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r27,r4,16
	ctx.r27.s64 = ctx.r4.s64 + 16;
	// addi r19,r3,16
	ctx.r19.s64 = ctx.r3.s64 + 16;
	// stvx128 v45,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v45), &VectorMaskL[(ea & 0xF) * 16]);
	// addi r20,r1,-288
	ctx.r20.s64 = ctx.r1.s64 + -288;
	// lvrx128 v58,r21,r10
	temp.u32 = ctx.r21.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v58.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// mulli r30,r11,13
	ctx.r30.s64 = ctx.r11.s64 * 13;
	// lvlx128 v36,r26,r10
	temp.u32 = ctx.r26.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v36,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v33,r25,r10
	temp.u32 = ctx.r25.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v33,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v29,v36,v35
	simd::store_i8(ctx.v29.u8, simd::or_i8(simd::load_i8(ctx.v36.u8), simd::load_i8(ctx.v35.u8)));
	// lvrx128 v60,r27,r10
	temp.u32 = ctx.r27.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v60.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v27,v33,v32
	simd::store_i8(ctx.v27.u8, simd::or_i8(simd::load_i8(ctx.v33.u8), simd::load_i8(ctx.v32.u8)));
	// lvrx128 v59,r19,r10
	temp.u32 = ctx.r19.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v59.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v55,v40,v60
	simd::store_i8(ctx.v55.u8, simd::or_i8(simd::load_i8(ctx.v40.u8), simd::load_i8(ctx.v60.u8)));
	// stvx128 v44,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v44), &VectorMaskL[(ea & 0xF) * 16]);
	// vor128 v54,v39,v59
	simd::store_i8(ctx.v54.u8, simd::or_i8(simd::load_i8(ctx.v39.u8), simd::load_i8(ctx.v59.u8)));
	// lvlx128 v57,r30,r10
	temp.u32 = ctx.r30.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v57,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v53,v38,v58
	simd::store_i8(ctx.v53.u8, simd::or_i8(simd::load_i8(ctx.v38.u8), simd::load_i8(ctx.v58.u8)));
	// rlwinm r29,r11,3,0,28
	ctx.r29.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r28,r11,4,0,27
	ctx.r28.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r29,r11,r29
	ctx.r29.s64 = ctx.r29.s64 - ctx.r11.s64;
	// addi r21,r1,-224
	ctx.r21.s64 = ctx.r1.s64 + -224;
	// subf r28,r11,r28
	ctx.r28.s64 = ctx.r28.s64 - ctx.r11.s64;
	// rlwinm r29,r29,1,0,30
	ctx.r29.u64 = rotl64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r27,r11,4,0,27
	ctx.r27.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// stvx128 v56,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v56), &VectorMaskL[(ea & 0xF) * 16]);
	// addi r21,r30,16
	ctx.r21.s64 = ctx.r30.s64 + 16;
	// lvlx128 v52,r28,r10
	temp.u32 = ctx.r28.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v52,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r20,r29,16
	ctx.r20.s64 = ctx.r29.s64 + 16;
	// lvlx128 v51,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v51,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r19,r28,16
	ctx.r19.s64 = ctx.r28.s64 + 16;
	// addi r18,r27,16
	ctx.r18.s64 = ctx.r27.s64 + 16;
	// lvlx128 v50,r27,r10
	temp.u32 = ctx.r27.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v50,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r17,r1,-320
	ctx.r17.s64 = ctx.r1.s64 + -320;
	// lvrx128 v49,r21,r10
	temp.u32 = ctx.r21.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v49.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r21,r1,-192
	ctx.r21.s64 = ctx.r1.s64 + -192;
	// lvrx128 v48,r20,r10
	temp.u32 = ctx.r20.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v48.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r20,r1,-176
	ctx.r20.s64 = ctx.r1.s64 + -176;
	// lvrx128 v47,r19,r10
	temp.u32 = ctx.r19.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v47.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r19,r1,-272
	ctx.r19.s64 = ctx.r1.s64 + -272;
	// lvrx128 v46,r18,r10
	temp.u32 = ctx.r18.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v46.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r18,r1,-240
	ctx.r18.s64 = ctx.r1.s64 + -240;
	// addi r16,r1,-208
	ctx.r16.s64 = ctx.r1.s64 + -208;
	// vor128 v45,v57,v49
	simd::store_i8(ctx.v45.u8, simd::or_i8(simd::load_i8(ctx.v57.u8), simd::load_i8(ctx.v49.u8)));
	// addi r15,r1,-256
	ctx.r15.s64 = ctx.r1.s64 + -256;
	// vor128 v44,v51,v48
	simd::store_i8(ctx.v44.u8, simd::or_i8(simd::load_i8(ctx.v51.u8), simd::load_i8(ctx.v48.u8)));
	// vor128 v43,v52,v47
	simd::store_i8(ctx.v43.u8, simd::or_i8(simd::load_i8(ctx.v52.u8), simd::load_i8(ctx.v47.u8)));
	// stvx128 v55,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v55), &VectorMaskL[(ea & 0xF) * 16]);
	// vor128 v42,v50,v46
	simd::store_i8(ctx.v42.u8, simd::or_i8(simd::load_i8(ctx.v50.u8), simd::load_i8(ctx.v46.u8)));
	// stvx128 v54,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v54), &VectorMaskL[(ea & 0xF) * 16]);
	// stvx128 v53,r0,r20
	ea = (ctx.r20.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v53), &VectorMaskL[(ea & 0xF) * 16]);
	// stvx128 v45,r0,r19
	ea = (ctx.r19.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v45), &VectorMaskL[(ea & 0xF) * 16]);
	// stvx128 v44,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v44), &VectorMaskL[(ea & 0xF) * 16]);
	// stvx128 v43,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v43), &VectorMaskL[(ea & 0xF) * 16]);
	// stvx128 v42,r0,r15
	ea = (ctx.r15.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v42), &VectorMaskL[(ea & 0xF) * 16]);
loc_8238DF84:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r21,r10,28
	ctx.r21.u64 = ctx.r10.u32 & 0xF;
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// bne cr6,0x8238dfdc
	if (!ctx.cr6.eq) goto loc_8238DFDC;
	// lvlx v9,0,r10
	temp.u32 = ctx.r0.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v9,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v5,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v5,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v4,r26,r10
	temp.u32 = ctx.r26.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v4,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v3,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v3,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v2,r25,r10
	temp.u32 = ctx.r25.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v2,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v1,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v1,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v25,r7,r10
	temp.u32 = ctx.r7.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v25,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v24,r6,r10
	temp.u32 = ctx.r6.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v24,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v23,r24,r10
	temp.u32 = ctx.r24.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v23,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v22,r5,r10
	temp.u32 = ctx.r5.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v22,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v21,r4,r10
	temp.u32 = ctx.r4.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v21,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v20,r3,r10
	temp.u32 = ctx.r3.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v20,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v19,r31,r10
	temp.u32 = ctx.r31.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v19,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v18,r30,r10
	temp.u32 = ctx.r30.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v18,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v17,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v17,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v16,r28,r10
	temp.u32 = ctx.r28.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v16,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx v15,r27,r10
	temp.u32 = ctx.r27.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v15,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// b 0x8238e0f4
	goto loc_8238E0F4;
loc_8238DFDC:
	// lvlx128 v40,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v40,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r21,r11,8
	ctx.r21.s64 = ctx.r11.s64 + 8;
	// addi r20,r11,4
	ctx.r20.s64 = ctx.r11.s64 + 4;
	// lvlx128 v39,r26,r10
	temp.u32 = ctx.r26.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v39,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r19,r11,2
	ctx.r19.s64 = ctx.r11.s64 + 2;
	// lvlx128 v38,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v38,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// lvlx128 v37,r25,r10
	temp.u32 = ctx.r25.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v37,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvlx128 v36,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v36,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r26,r21,1,0,30
	ctx.r26.u64 = rotl64(ctx.r21.u32 | (ctx.r21.u64 << 32), 1) & 0xFFFFFFFE;
	// lvlx128 v35,r7,r10
	temp.u32 = ctx.r7.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v35,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// lvlx128 v34,r6,r10
	temp.u32 = ctx.r6.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v34,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// rlwinm r25,r20,2,0,29
	ctx.r25.u64 = rotl64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// lvlx128 v56,r24,r10
	temp.u32 = ctx.r24.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v56,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// lvrx128 v32,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v32.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// lvrx128 v63,r26,r10
	temp.u32 = ctx.r26.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v63.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// rlwinm r11,r19,3,0,28
	ctx.r11.u64 = rotl64(ctx.r19.u32 | (ctx.r19.u64 << 32), 3) & 0xFFFFFFF8;
	// lvrx128 v62,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v62.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvrx128 v61,r25,r10
	temp.u32 = ctx.r25.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v61.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r26,r5,16
	ctx.r26.s64 = ctx.r5.s64 + 16;
	// lvrx128 v60,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v60.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r9,r4,16
	ctx.r9.s64 = ctx.r4.s64 + 16;
	// lvrx128 v59,r7,r10
	temp.u32 = ctx.r7.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v59.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r25,r3,16
	ctx.r25.s64 = ctx.r3.s64 + 16;
	// lvrx128 v58,r6,r10
	temp.u32 = ctx.r6.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v58.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r8,r31,16
	ctx.r8.s64 = ctx.r31.s64 + 16;
	// lvrx128 v57,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v57.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r7,r30,16
	ctx.r7.s64 = ctx.r30.s64 + 16;
	// addi r6,r29,16
	ctx.r6.s64 = ctx.r29.s64 + 16;
	// lvlx128 v41,r0,r10
	temp.u32 = ctx.r0.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v41,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// addi r11,r28,16
	ctx.r11.s64 = ctx.r28.s64 + 16;
	// lvrx128 v33,r23,r10
	temp.u32 = ctx.r23.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v33.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// addi r24,r27,16
	ctx.r24.s64 = ctx.r27.s64 + 16;
	// vor128 v9,v41,v33
	simd::store_i8(ctx.v9.u8, simd::or_i8(simd::load_i8(ctx.v41.u8), simd::load_i8(ctx.v33.u8)));
	// vor128 v5,v40,v32
	simd::store_i8(ctx.v5.u8, simd::or_i8(simd::load_i8(ctx.v40.u8), simd::load_i8(ctx.v32.u8)));
	// lvrx128 v55,r26,r10
	temp.u32 = ctx.r26.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v55.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// lvlx128 v54,r5,r10
	temp.u32 = ctx.r5.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v54,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v4,v39,v63
	simd::store_i8(ctx.v4.u8, simd::or_i8(simd::load_i8(ctx.v39.u8), simd::load_i8(ctx.v63.u8)));
	// lvrx128 v53,r9,r10
	temp.u32 = ctx.r9.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v53.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v3,v38,v62
	simd::store_i8(ctx.v3.u8, simd::or_i8(simd::load_i8(ctx.v38.u8), simd::load_i8(ctx.v62.u8)));
	// lvlx128 v52,r4,r10
	temp.u32 = ctx.r4.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v52,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v2,v37,v61
	simd::store_i8(ctx.v2.u8, simd::or_i8(simd::load_i8(ctx.v37.u8), simd::load_i8(ctx.v61.u8)));
	// lvrx128 v51,r25,r10
	temp.u32 = ctx.r25.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v51.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v1,v36,v60
	simd::store_i8(ctx.v1.u8, simd::or_i8(simd::load_i8(ctx.v36.u8), simd::load_i8(ctx.v60.u8)));
	// lvlx128 v50,r3,r10
	temp.u32 = ctx.r3.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v50,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v25,v35,v59
	simd::store_i8(ctx.v25.u8, simd::or_i8(simd::load_i8(ctx.v35.u8), simd::load_i8(ctx.v59.u8)));
	// lvrx128 v49,r8,r10
	temp.u32 = ctx.r8.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v49.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v24,v34,v58
	simd::store_i8(ctx.v24.u8, simd::or_i8(simd::load_i8(ctx.v34.u8), simd::load_i8(ctx.v58.u8)));
	// lvlx128 v48,r31,r10
	temp.u32 = ctx.r31.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v48,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v23,v56,v57
	simd::store_i8(ctx.v23.u8, simd::or_i8(simd::load_i8(ctx.v56.u8), simd::load_i8(ctx.v57.u8)));
	// lvrx128 v47,r7,r10
	temp.u32 = ctx.r7.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v47.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v22,v54,v55
	simd::store_i8(ctx.v22.u8, simd::or_i8(simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v55.u8)));
	// lvlx128 v46,r30,r10
	temp.u32 = ctx.r30.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v46,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v21,v52,v53
	simd::store_i8(ctx.v21.u8, simd::or_i8(simd::load_i8(ctx.v52.u8), simd::load_i8(ctx.v53.u8)));
	// lvrx128 v45,r6,r10
	temp.u32 = ctx.r6.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v45.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v20,v50,v51
	simd::store_i8(ctx.v20.u8, simd::or_i8(simd::load_i8(ctx.v50.u8), simd::load_i8(ctx.v51.u8)));
	// lvlx128 v44,r29,r10
	temp.u32 = ctx.r29.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v44,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v19,v48,v49
	simd::store_i8(ctx.v19.u8, simd::or_i8(simd::load_i8(ctx.v48.u8), simd::load_i8(ctx.v49.u8)));
	// lvrx128 v43,r11,r10
	temp.u32 = ctx.r11.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v43.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v18,v46,v47
	simd::store_i8(ctx.v18.u8, simd::or_i8(simd::load_i8(ctx.v46.u8), simd::load_i8(ctx.v47.u8)));
	// lvlx128 v42,r28,r10
	temp.u32 = ctx.r28.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v42,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v17,v44,v45
	simd::store_i8(ctx.v17.u8, simd::or_i8(simd::load_i8(ctx.v44.u8), simd::load_i8(ctx.v45.u8)));
	// lvrx128 v41,r24,r10
	temp.u32 = ctx.r24.u32 + ctx.r10.u32;
	simd::store_i8(ctx.v41.u8, simd::load_unaligned_vector_right(base, temp.u32));
	// vor128 v16,v42,v43
	simd::store_i8(ctx.v16.u8, simd::or_i8(simd::load_i8(ctx.v42.u8), simd::load_i8(ctx.v43.u8)));
	// lvlx128 v40,r27,r10
	temp.u32 = ctx.r27.u32 + ctx.r10.u32;
	simd::store_shuffled(ctx.v40,
		simde_mm_shuffle_epi8(
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(base + ((temp).u32 & ~0xF))),
			simde_mm_load_si128(reinterpret_cast<const simde__m128i*>(&VectorMaskL[((temp).u32 & 0xF) * 16]))
		));
	// vor128 v15,v40,v41
	simd::store_i8(ctx.v15.u8, simd::or_i8(simd::load_i8(ctx.v40.u8), simd::load_i8(ctx.v41.u8)));
loc_8238E0F4:
	// vavgub v13,v30,v5
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v30.u8), simd::load_u8(ctx.v5.u8)));
	// addi r10,r1,-288
	ctx.r10.s64 = ctx.r1.s64 + -288;
	// vxor128 v39,v30,v5
	simd::store_u8(ctx.v39.u8, simd::xor_i8(simd::load_u8(ctx.v30.u8), simd::load_u8(ctx.v5.u8)));
	// addi r9,r1,-224
	ctx.r9.s64 = ctx.r1.s64 + -224;
	// vavgub v8,v31,v9
	simd::store_u8(ctx.v8.u8, simd::avg_u8(simd::load_u8(ctx.v31.u8), simd::load_u8(ctx.v9.u8)));
	// addi r8,r1,-320
	ctx.r8.s64 = ctx.r1.s64 + -320;
	// vxor128 v35,v31,v9
	simd::store_u8(ctx.v35.u8, simd::xor_i8(simd::load_u8(ctx.v31.u8), simd::load_u8(ctx.v9.u8)));
	// addi r11,r1,-304
	ctx.r11.s64 = ctx.r1.s64 + -304;
	// vavgub v12,v29,v4
	simd::store_u8(ctx.v12.u8, simd::avg_u8(simd::load_u8(ctx.v29.u8), simd::load_u8(ctx.v4.u8)));
	// addi r7,r1,-192
	ctx.r7.s64 = ctx.r1.s64 + -192;
	// vavgub v11,v28,v3
	simd::store_u8(ctx.v11.u8, simd::avg_u8(simd::load_u8(ctx.v28.u8), simd::load_u8(ctx.v3.u8)));
	// addi r28,r1,-224
	ctx.r28.s64 = ctx.r1.s64 + -224;
	// vxor128 v38,v29,v4
	simd::store_u8(ctx.v38.u8, simd::xor_i8(simd::load_u8(ctx.v29.u8), simd::load_u8(ctx.v4.u8)));
	// lvx128 v4,r0,r10
	simd::store_shuffled(ctx.v4, simd::load_and_shuffle(base + ((ctx.r10.u32) & ~0xF), VectorMaskL));
	// vxor128 v37,v28,v3
	simd::store_u8(ctx.v37.u8, simd::xor_i8(simd::load_u8(ctx.v28.u8), simd::load_u8(ctx.v3.u8)));
	// lvx128 v3,r0,r9
	simd::store_shuffled(ctx.v3, simd::load_and_shuffle(base + ((ctx.r9.u32) & ~0xF), VectorMaskL));
	// vavgub v10,v27,v2
	simd::store_u8(ctx.v10.u8, simd::avg_u8(simd::load_u8(ctx.v27.u8), simd::load_u8(ctx.v2.u8)));
	// addi r30,r1,-304
	ctx.r30.s64 = ctx.r1.s64 + -304;
	// vxor128 v34,v8,v13
	simd::store_u8(ctx.v34.u8, simd::xor_i8(simd::load_u8(ctx.v8.u8), simd::load_u8(ctx.v13.u8)));
	// addi r29,r1,-288
	ctx.r29.s64 = ctx.r1.s64 + -288;
	// vxor128 v36,v27,v2
	simd::store_u8(ctx.v36.u8, simd::xor_i8(simd::load_u8(ctx.v27.u8), simd::load_u8(ctx.v2.u8)));
	// lvx128 v2,r0,r8
	simd::store_shuffled(ctx.v2, simd::load_and_shuffle(base + ((ctx.r8.u32) & ~0xF), VectorMaskL));
	// vor128 v61,v35,v39
	simd::store_i8(ctx.v61.u8, simd::or_i8(simd::load_i8(ctx.v35.u8), simd::load_i8(ctx.v39.u8)));
	// addi r10,r1,-224
	ctx.r10.s64 = ctx.r1.s64 + -224;
	// vxor128 v33,v13,v12
	simd::store_u8(ctx.v33.u8, simd::xor_i8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v12.u8)));
	// lvx128 v5,r0,r11
	simd::store_shuffled(ctx.v5, simd::load_and_shuffle(base + ((ctx.r11.u32) & ~0xF), VectorMaskL));
	// vxor128 v32,v12,v11
	simd::store_u8(ctx.v32.u8, simd::xor_i8(simd::load_u8(ctx.v12.u8), simd::load_u8(ctx.v11.u8)));
	// addi r27,r1,-320
	ctx.r27.s64 = ctx.r1.s64 + -320;
	// vor128 v62,v39,v38
	simd::store_i8(ctx.v62.u8, simd::or_i8(simd::load_i8(ctx.v39.u8), simd::load_i8(ctx.v38.u8)));
	// addi r6,r1,-176
	ctx.r6.s64 = ctx.r1.s64 + -176;
	// vor128 v60,v38,v37
	simd::store_i8(ctx.v60.u8, simd::or_i8(simd::load_i8(ctx.v38.u8), simd::load_i8(ctx.v37.u8)));
	// addi r5,r1,-272
	ctx.r5.s64 = ctx.r1.s64 + -272;
	// vavgub v8,v8,v13
	simd::store_u8(ctx.v8.u8, simd::avg_u8(simd::load_u8(ctx.v8.u8), simd::load_u8(ctx.v13.u8)));
	// addi r9,r1,-288
	ctx.r9.s64 = ctx.r1.s64 + -288;
	// vxor128 v63,v11,v10
	simd::store_u8(ctx.v63.u8, simd::xor_i8(simd::load_u8(ctx.v11.u8), simd::load_u8(ctx.v10.u8)));
	// addi r8,r1,-304
	ctx.r8.s64 = ctx.r1.s64 + -304;
	// vor128 v59,v37,v36
	simd::store_i8(ctx.v59.u8, simd::or_i8(simd::load_i8(ctx.v37.u8), simd::load_i8(ctx.v36.u8)));
	// lvx128 v31,r0,r7
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r7.u32) & ~0xF), VectorMaskL));
	// vand128 v57,v61,v34
	simd::store_u8(ctx.v57.u8, simd::and_u8(simd::load_u8(ctx.v61.u8), simd::load_u8(ctx.v34.u8)));
	// addi r11,r1,-320
	ctx.r11.s64 = ctx.r1.s64 + -320;
	// vavgub v13,v13,v12
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v12.u8)));
	// addi r4,r1,-240
	ctx.r4.s64 = ctx.r1.s64 + -240;
	// vavgub v12,v12,v11
	simd::store_u8(ctx.v12.u8, simd::avg_u8(simd::load_u8(ctx.v12.u8), simd::load_u8(ctx.v11.u8)));
	// addi r3,r1,-208
	ctx.r3.s64 = ctx.r1.s64 + -208;
	// vavgub v11,v11,v10
	simd::store_u8(ctx.v11.u8, simd::avg_u8(simd::load_u8(ctx.v11.u8), simd::load_u8(ctx.v10.u8)));
	// addi r31,r1,-256
	ctx.r31.s64 = ctx.r1.s64 + -256;
	// vavgub v9,v26,v1
	simd::store_u8(ctx.v9.u8, simd::avg_u8(simd::load_u8(ctx.v26.u8), simd::load_u8(ctx.v1.u8)));
	// addi r7,r1,-160
	ctx.r7.s64 = ctx.r1.s64 + -160;
	// vxor128 v54,v26,v1
	simd::store_u8(ctx.v54.u8, simd::xor_i8(simd::load_u8(ctx.v26.u8), simd::load_u8(ctx.v1.u8)));
	// lvx128 v51,r0,r28
	simd::store_shuffled(ctx.v51, simd::load_and_shuffle(base + ((ctx.r28.u32) & ~0xF), VectorMaskL));
	// vand128 v58,v62,v33
	simd::store_u8(ctx.v58.u8, simd::and_u8(simd::load_u8(ctx.v62.u8), simd::load_u8(ctx.v33.u8)));
	// lvx128 v53,r0,r30
	simd::store_shuffled(ctx.v53, simd::load_and_shuffle(base + ((ctx.r30.u32) & ~0xF), VectorMaskL));
	// vand128 v56,v60,v32
	simd::store_u8(ctx.v56.u8, simd::and_u8(simd::load_u8(ctx.v60.u8), simd::load_u8(ctx.v32.u8)));
	// lvx128 v52,r0,r29
	simd::store_shuffled(ctx.v52, simd::load_and_shuffle(base + ((ctx.r29.u32) & ~0xF), VectorMaskL));
	// vand128 v1,v57,v0
	simd::store_u8(ctx.v1.u8, simd::and_u8(simd::load_u8(ctx.v57.u8), simd::load_u8(ctx.v0.u8)));
	// stvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v12), &VectorMaskL[(ea & 0xF) * 16]);
	// vand128 v55,v59,v63
	simd::store_u8(ctx.v55.u8, simd::and_u8(simd::load_u8(ctx.v59.u8), simd::load_u8(ctx.v63.u8)));
	// lvx128 v30,r0,r6
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r6.u32) & ~0xF), VectorMaskL));
	// lvx128 v29,r0,r5
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r5.u32) & ~0xF), VectorMaskL));
	// vor128 v49,v6,v6
	simd::store_i8(ctx.v49.u8, simd::load_i8(ctx.v6.u8));
	// lvx128 v50,r0,r27
	simd::store_shuffled(ctx.v50, simd::load_and_shuffle(base + ((ctx.r27.u32) & ~0xF), VectorMaskL));
	// vor128 v48,v7,v7
	simd::store_i8(ctx.v48.u8, simd::load_i8(ctx.v7.u8));
	// vavgub v12,v5,v24
	simd::store_u8(ctx.v12.u8, simd::avg_u8(simd::load_u8(ctx.v5.u8), simd::load_u8(ctx.v24.u8)));
	// stvx128 v11,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v11), &VectorMaskL[(ea & 0xF) * 16]);
	// stvx128 v8,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v8), &VectorMaskL[(ea & 0xF) * 16]);
	// vand128 v6,v58,v0
	simd::store_u8(ctx.v6.u8, simd::and_u8(simd::load_u8(ctx.v58.u8), simd::load_u8(ctx.v0.u8)));
	// vand128 v7,v56,v0
	simd::store_u8(ctx.v7.u8, simd::and_u8(simd::load_u8(ctx.v56.u8), simd::load_u8(ctx.v0.u8)));
	// stvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v13), &VectorMaskL[(ea & 0xF) * 16]);
	// vor128 v47,v0,v0
	simd::store_i8(ctx.v47.u8, simd::load_i8(ctx.v0.u8));
	// lvx128 v28,r0,r4
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r4.u32) & ~0xF), VectorMaskL));
	// vavgub v11,v4,v23
	simd::store_u8(ctx.v11.u8, simd::avg_u8(simd::load_u8(ctx.v4.u8), simd::load_u8(ctx.v23.u8)));
	// lvx128 v27,r0,r3
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r3.u32) & ~0xF), VectorMaskL));
	// vavgub v8,v3,v22
	simd::store_u8(ctx.v8.u8, simd::avg_u8(simd::load_u8(ctx.v3.u8), simd::load_u8(ctx.v22.u8)));
	// lvx128 v26,r0,r31
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r31.u32) & ~0xF), VectorMaskL));
	// vavgub v5,v2,v21
	simd::store_u8(ctx.v5.u8, simd::avg_u8(simd::load_u8(ctx.v2.u8), simd::load_u8(ctx.v21.u8)));
	// stvx128 v1,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v1), &VectorMaskL[(ea & 0xF) * 16]);
	// vand128 v0,v55,v0
	simd::store_u8(ctx.v0.u8, simd::and_u8(simd::load_u8(ctx.v55.u8), simd::load_u8(ctx.v0.u8)));
	// vavgub v13,v14,v25
	simd::store_u8(ctx.v13.u8, simd::avg_u8(simd::load_u8(ctx.v14.u8), simd::load_u8(ctx.v25.u8)));
	// vavgub v4,v31,v20
	simd::store_u8(ctx.v4.u8, simd::avg_u8(simd::load_u8(ctx.v31.u8), simd::load_u8(ctx.v20.u8)));
	// vavgub v3,v30,v19
	simd::store_u8(ctx.v3.u8, simd::avg_u8(simd::load_u8(ctx.v30.u8), simd::load_u8(ctx.v19.u8)));
	// vavgub v2,v29,v18
	simd::store_u8(ctx.v2.u8, simd::avg_u8(simd::load_u8(ctx.v29.u8), simd::load_u8(ctx.v18.u8)));
	// vavgub v1,v28,v17
	simd::store_u8(ctx.v1.u8, simd::avg_u8(simd::load_u8(ctx.v28.u8), simd::load_u8(ctx.v17.u8)));
	// lvx128 v28,r0,r7
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r7.u32) & ~0xF), VectorMaskL));
	// lvx128 v29,r0,r8
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r8.u32) & ~0xF), VectorMaskL));
	// vavgub v31,v27,v16
	simd::store_u8(ctx.v31.u8, simd::avg_u8(simd::load_u8(ctx.v27.u8), simd::load_u8(ctx.v16.u8)));
	// lvx128 v27,r0,r11
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32) & ~0xF), VectorMaskL));
	// vavgub v30,v26,v15
	simd::store_u8(ctx.v30.u8, simd::avg_u8(simd::load_u8(ctx.v26.u8), simd::load_u8(ctx.v15.u8)));
	// lvx128 v26,r0,r10
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r10.u32) & ~0xF), VectorMaskL));
	// vsububs v29,v29,v28
	simd::store_u8(ctx.v29.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v29.u8), simd::load_u8(ctx.v28.u8)));
	// vsububs v28,v27,v6
	simd::store_u8(ctx.v28.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v27.u8), simd::load_u8(ctx.v6.u8)));
	// addi r11,r1,-192
	ctx.r11.s64 = ctx.r1.s64 + -192;
	// vsububs v27,v26,v7
	simd::store_u8(ctx.v27.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v26.u8), simd::load_u8(ctx.v7.u8)));
	// lvx128 v26,r0,r9
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r9.u32) & ~0xF), VectorMaskL));
	// addi r10,r1,-176
	ctx.r10.s64 = ctx.r1.s64 + -176;
	// vxor128 v44,v14,v25
	simd::store_u8(ctx.v44.u8, simd::xor_i8(simd::load_u8(ctx.v14.u8), simd::load_u8(ctx.v25.u8)));
	// addi r9,r1,-272
	ctx.r9.s64 = ctx.r1.s64 + -272;
	// vxor128 v43,v53,v24
	simd::store_u8(ctx.v43.u8, simd::xor_i8(simd::load_u8(ctx.v53.u8), simd::load_u8(ctx.v24.u8)));
	// addi r8,r1,-240
	ctx.r8.s64 = ctx.r1.s64 + -240;
	// vxor128 v42,v52,v23
	simd::store_u8(ctx.v42.u8, simd::xor_i8(simd::load_u8(ctx.v52.u8), simd::load_u8(ctx.v23.u8)));
	// addi r7,r1,-208
	ctx.r7.s64 = ctx.r1.s64 + -208;
	// vxor128 v41,v51,v22
	simd::store_u8(ctx.v41.u8, simd::xor_i8(simd::load_u8(ctx.v51.u8), simd::load_u8(ctx.v22.u8)));
	// lvx128 v35,r0,r11
	simd::store_shuffled(ctx.v35, simd::load_and_shuffle(base + ((ctx.r11.u32) & ~0xF), VectorMaskL));
	// addi r6,r1,-256
	ctx.r6.s64 = ctx.r1.s64 + -256;
	// lvx128 v34,r0,r10
	simd::store_shuffled(ctx.v34, simd::load_and_shuffle(base + ((ctx.r10.u32) & ~0xF), VectorMaskL));
	// vor128 v45,v36,v54
	simd::store_i8(ctx.v45.u8, simd::or_i8(simd::load_i8(ctx.v36.u8), simd::load_i8(ctx.v54.u8)));
	// lvx128 v32,r0,r9
	simd::store_shuffled(ctx.v32, simd::load_and_shuffle(base + ((ctx.r9.u32) & ~0xF), VectorMaskL));
	// vxor128 v40,v50,v21
	simd::store_u8(ctx.v40.u8, simd::xor_i8(simd::load_u8(ctx.v50.u8), simd::load_u8(ctx.v21.u8)));
	// lvx128 v62,r0,r8
	simd::store_shuffled(ctx.v62, simd::load_and_shuffle(base + ((ctx.r8.u32) & ~0xF), VectorMaskL));
	// vxor128 v46,v10,v9
	simd::store_u8(ctx.v46.u8, simd::xor_i8(simd::load_u8(ctx.v10.u8), simd::load_u8(ctx.v9.u8)));
	// lvx128 v60,r0,r7
	simd::store_shuffled(ctx.v60, simd::load_and_shuffle(base + ((ctx.r7.u32) & ~0xF), VectorMaskL));
	// vxor128 v33,v35,v20
	simd::store_u8(ctx.v33.u8, simd::xor_i8(simd::load_u8(ctx.v35.u8), simd::load_u8(ctx.v20.u8)));
	// vxor128 v63,v34,v19
	simd::store_u8(ctx.v63.u8, simd::xor_i8(simd::load_u8(ctx.v34.u8), simd::load_u8(ctx.v19.u8)));
	// lvx128 v57,r0,r6
	simd::store_shuffled(ctx.v57, simd::load_and_shuffle(base + ((ctx.r6.u32) & ~0xF), VectorMaskL));
	// vxor128 v61,v32,v18
	simd::store_u8(ctx.v61.u8, simd::xor_i8(simd::load_u8(ctx.v32.u8), simd::load_u8(ctx.v18.u8)));
	// vxor128 v59,v62,v17
	simd::store_u8(ctx.v59.u8, simd::xor_i8(simd::load_u8(ctx.v62.u8), simd::load_u8(ctx.v17.u8)));
	// vor128 v55,v54,v44
	simd::store_i8(ctx.v55.u8, simd::or_i8(simd::load_i8(ctx.v54.u8), simd::load_i8(ctx.v44.u8)));
	// vxor128 v58,v60,v16
	simd::store_u8(ctx.v58.u8, simd::xor_i8(simd::load_u8(ctx.v60.u8), simd::load_u8(ctx.v16.u8)));
	// vor128 v54,v44,v43
	simd::store_i8(ctx.v54.u8, simd::or_i8(simd::load_i8(ctx.v44.u8), simd::load_i8(ctx.v43.u8)));
	// vor128 v53,v43,v42
	simd::store_i8(ctx.v53.u8, simd::or_i8(simd::load_i8(ctx.v43.u8), simd::load_i8(ctx.v42.u8)));
	// vor128 v52,v42,v41
	simd::store_i8(ctx.v52.u8, simd::or_i8(simd::load_i8(ctx.v42.u8), simd::load_i8(ctx.v41.u8)));
	// vxor128 v39,v9,v13
	simd::store_u8(ctx.v39.u8, simd::xor_i8(simd::load_u8(ctx.v9.u8), simd::load_u8(ctx.v13.u8)));
	// vxor128 v38,v13,v12
	simd::store_u8(ctx.v38.u8, simd::xor_i8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v12.u8)));
	// vxor128 v37,v12,v11
	simd::store_u8(ctx.v37.u8, simd::xor_i8(simd::load_u8(ctx.v12.u8), simd::load_u8(ctx.v11.u8)));
	// vxor128 v36,v11,v8
	simd::store_u8(ctx.v36.u8, simd::xor_i8(simd::load_u8(ctx.v11.u8), simd::load_u8(ctx.v8.u8)));
	// vor128 v51,v41,v40
	simd::store_i8(ctx.v51.u8, simd::or_i8(simd::load_i8(ctx.v41.u8), simd::load_i8(ctx.v40.u8)));
	// vand128 v50,v45,v46
	simd::store_u8(ctx.v50.u8, simd::and_u8(simd::load_u8(ctx.v45.u8), simd::load_u8(ctx.v46.u8)));
	// vor128 v45,v40,v33
	simd::store_i8(ctx.v45.u8, simd::or_i8(simd::load_i8(ctx.v40.u8), simd::load_i8(ctx.v33.u8)));
	// vor128 v43,v33,v63
	simd::store_i8(ctx.v43.u8, simd::or_i8(simd::load_i8(ctx.v33.u8), simd::load_i8(ctx.v63.u8)));
	// vor128 v41,v63,v61
	simd::store_i8(ctx.v41.u8, simd::or_i8(simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v61.u8)));
	// vor128 v35,v61,v59
	simd::store_i8(ctx.v35.u8, simd::or_i8(simd::load_i8(ctx.v61.u8), simd::load_i8(ctx.v59.u8)));
	// vxor128 v56,v8,v5
	simd::store_u8(ctx.v56.u8, simd::xor_i8(simd::load_u8(ctx.v8.u8), simd::load_u8(ctx.v5.u8)));
	// vsububs v26,v26,v0
	simd::store_u8(ctx.v26.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v26.u8), simd::load_u8(ctx.v0.u8)));
	// vor128 v0,v47,v47
	simd::store_i8(ctx.v0.u8, simd::load_i8(ctx.v47.u8));
	// vor128 v33,v59,v58
	simd::store_i8(ctx.v33.u8, simd::or_i8(simd::load_i8(ctx.v59.u8), simd::load_i8(ctx.v58.u8)));
	// vxor128 v32,v57,v15
	simd::store_u8(ctx.v32.u8, simd::xor_i8(simd::load_u8(ctx.v57.u8), simd::load_u8(ctx.v15.u8)));
	// vand128 v63,v55,v39
	simd::store_u8(ctx.v63.u8, simd::and_u8(simd::load_u8(ctx.v55.u8), simd::load_u8(ctx.v39.u8)));
	// vand128 v62,v54,v38
	simd::store_u8(ctx.v62.u8, simd::and_u8(simd::load_u8(ctx.v54.u8), simd::load_u8(ctx.v38.u8)));
	// vand128 v61,v53,v37
	simd::store_u8(ctx.v61.u8, simd::and_u8(simd::load_u8(ctx.v53.u8), simd::load_u8(ctx.v37.u8)));
	// vand128 v60,v52,v36
	simd::store_u8(ctx.v60.u8, simd::and_u8(simd::load_u8(ctx.v52.u8), simd::load_u8(ctx.v36.u8)));
	// vxor128 v46,v5,v4
	simd::store_u8(ctx.v46.u8, simd::xor_i8(simd::load_u8(ctx.v5.u8), simd::load_u8(ctx.v4.u8)));
	// vxor128 v44,v4,v3
	simd::store_u8(ctx.v44.u8, simd::xor_i8(simd::load_u8(ctx.v4.u8), simd::load_u8(ctx.v3.u8)));
	// vxor128 v42,v3,v2
	simd::store_u8(ctx.v42.u8, simd::xor_i8(simd::load_u8(ctx.v3.u8), simd::load_u8(ctx.v2.u8)));
	// vxor128 v40,v2,v1
	simd::store_u8(ctx.v40.u8, simd::xor_i8(simd::load_u8(ctx.v2.u8), simd::load_u8(ctx.v1.u8)));
	// vxor128 v34,v1,v31
	simd::store_u8(ctx.v34.u8, simd::xor_i8(simd::load_u8(ctx.v1.u8), simd::load_u8(ctx.v31.u8)));
	// vand128 v59,v51,v56
	simd::store_u8(ctx.v59.u8, simd::and_u8(simd::load_u8(ctx.v51.u8), simd::load_u8(ctx.v56.u8)));
	// vavgub v25,v10,v9
	simd::store_u8(ctx.v25.u8, simd::avg_u8(simd::load_u8(ctx.v10.u8), simd::load_u8(ctx.v9.u8)));
	// vavgub v24,v9,v13
	simd::store_u8(ctx.v24.u8, simd::avg_u8(simd::load_u8(ctx.v9.u8), simd::load_u8(ctx.v13.u8)));
	// vavgub v23,v13,v12
	simd::store_u8(ctx.v23.u8, simd::avg_u8(simd::load_u8(ctx.v13.u8), simd::load_u8(ctx.v12.u8)));
	// vavgub v22,v12,v11
	simd::store_u8(ctx.v22.u8, simd::avg_u8(simd::load_u8(ctx.v12.u8), simd::load_u8(ctx.v11.u8)));
	// vavgub v21,v11,v8
	simd::store_u8(ctx.v21.u8, simd::avg_u8(simd::load_u8(ctx.v11.u8), simd::load_u8(ctx.v8.u8)));
	// vand128 v57,v45,v46
	simd::store_u8(ctx.v57.u8, simd::and_u8(simd::load_u8(ctx.v45.u8), simd::load_u8(ctx.v46.u8)));
	// vand128 v56,v43,v44
	simd::store_u8(ctx.v56.u8, simd::and_u8(simd::load_u8(ctx.v43.u8), simd::load_u8(ctx.v44.u8)));
	// vand128 v55,v41,v42
	simd::store_u8(ctx.v55.u8, simd::and_u8(simd::load_u8(ctx.v41.u8), simd::load_u8(ctx.v42.u8)));
	// vand128 v54,v35,v40
	simd::store_u8(ctx.v54.u8, simd::and_u8(simd::load_u8(ctx.v35.u8), simd::load_u8(ctx.v40.u8)));
	// vand128 v53,v33,v34
	simd::store_u8(ctx.v53.u8, simd::and_u8(simd::load_u8(ctx.v33.u8), simd::load_u8(ctx.v34.u8)));
	// vxor128 v52,v31,v30
	simd::store_u8(ctx.v52.u8, simd::xor_i8(simd::load_u8(ctx.v31.u8), simd::load_u8(ctx.v30.u8)));
	// vor128 v51,v58,v32
	simd::store_i8(ctx.v51.u8, simd::or_i8(simd::load_i8(ctx.v58.u8), simd::load_i8(ctx.v32.u8)));
	// vand128 v20,v50,v0
	simd::store_u8(ctx.v20.u8, simd::and_u8(simd::load_u8(ctx.v50.u8), simd::load_u8(ctx.v0.u8)));
	// vand128 v19,v63,v0
	simd::store_u8(ctx.v19.u8, simd::and_u8(simd::load_u8(ctx.v63.u8), simd::load_u8(ctx.v0.u8)));
	// vand128 v18,v62,v0
	simd::store_u8(ctx.v18.u8, simd::and_u8(simd::load_u8(ctx.v62.u8), simd::load_u8(ctx.v0.u8)));
	// vand128 v17,v61,v0
	simd::store_u8(ctx.v17.u8, simd::and_u8(simd::load_u8(ctx.v61.u8), simd::load_u8(ctx.v0.u8)));
	// vand128 v16,v60,v0
	simd::store_u8(ctx.v16.u8, simd::and_u8(simd::load_u8(ctx.v60.u8), simd::load_u8(ctx.v0.u8)));
	// addi r5,r1,-256
	ctx.r5.s64 = ctx.r1.s64 + -256;
	// vand128 v12,v56,v0
	simd::store_u8(ctx.v12.u8, simd::and_u8(simd::load_u8(ctx.v56.u8), simd::load_u8(ctx.v0.u8)));
	// stvx128 v12,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v12), &VectorMaskL[(ea & 0xF) * 16]);
	// addi r3,r1,-208
	ctx.r3.s64 = ctx.r1.s64 + -208;
	// vand128 v11,v55,v0
	simd::store_u8(ctx.v11.u8, simd::and_u8(simd::load_u8(ctx.v55.u8), simd::load_u8(ctx.v0.u8)));
	// stvx128 v11,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v11), &VectorMaskL[(ea & 0xF) * 16]);
	// addi r11,r1,-240
	ctx.r11.s64 = ctx.r1.s64 + -240;
	// vand128 v10,v54,v0
	simd::store_u8(ctx.v10.u8, simd::and_u8(simd::load_u8(ctx.v54.u8), simd::load_u8(ctx.v0.u8)));
	// stvx128 v10,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v10), &VectorMaskL[(ea & 0xF) * 16]);
	// addi r6,r1,-160
	ctx.r6.s64 = ctx.r1.s64 + -160;
	// addi r10,r1,-272
	ctx.r10.s64 = ctx.r1.s64 + -272;
	// vand128 v13,v57,v0
	simd::store_u8(ctx.v13.u8, simd::and_u8(simd::load_u8(ctx.v57.u8), simd::load_u8(ctx.v0.u8)));
	// vand128 v9,v53,v0
	simd::store_u8(ctx.v9.u8, simd::and_u8(simd::load_u8(ctx.v53.u8), simd::load_u8(ctx.v0.u8)));
	// stvx128 v13,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v13), &VectorMaskL[(ea & 0xF) * 16]);
	// stvx128 v9,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v9), &VectorMaskL[(ea & 0xF) * 16]);
	// vor128 v7,v48,v48
	simd::store_i8(ctx.v7.u8, simd::load_i8(ctx.v48.u8));
	// vand128 v50,v51,v52
	simd::store_u8(ctx.v50.u8, simd::and_u8(simd::load_u8(ctx.v51.u8), simd::load_u8(ctx.v52.u8)));
	// li r4,48
	ctx.r4.s64 = 48;
	// vsububs v13,v25,v20
	simd::store_u8(ctx.v13.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v25.u8), simd::load_u8(ctx.v20.u8)));
	// li r9,112
	ctx.r9.s64 = 112;
	// vsububs v12,v24,v19
	simd::store_u8(ctx.v12.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v24.u8), simd::load_u8(ctx.v19.u8)));
	// li r8,128
	ctx.r8.s64 = 128;
	// vsububs v11,v23,v18
	simd::store_u8(ctx.v11.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v23.u8), simd::load_u8(ctx.v18.u8)));
	// vperm128 v48,v29,v28,v7
	simd::store_i8(ctx.v48.u8, simd::permute_bytes(simd::load_i8(ctx.v29.u8), simd::load_i8(ctx.v28.u8), simd::load_i8(ctx.v7.u8)));
	// vsububs v10,v22,v17
	simd::store_u8(ctx.v10.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v22.u8), simd::load_u8(ctx.v17.u8)));
	// vperm128 v47,v27,v26,v7
	simd::store_i8(ctx.v47.u8, simd::permute_bytes(simd::load_i8(ctx.v27.u8), simd::load_i8(ctx.v26.u8), simd::load_i8(ctx.v7.u8)));
	// vor128 v6,v49,v49
	simd::store_i8(ctx.v6.u8, simd::load_i8(ctx.v49.u8));
	// li r7,144
	ctx.r7.s64 = 144;
	// vavgub v14,v8,v5
	simd::store_u8(ctx.v14.u8, simd::avg_u8(simd::load_u8(ctx.v8.u8), simd::load_u8(ctx.v5.u8)));
	// vperm128 v46,v13,v12,v7
	simd::store_i8(ctx.v46.u8, simd::permute_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v7.u8)));
	// vand128 v25,v50,v0
	simd::store_u8(ctx.v25.u8, simd::and_u8(simd::load_u8(ctx.v50.u8), simd::load_u8(ctx.v0.u8)));
	// vavgub v24,v31,v30
	simd::store_u8(ctx.v24.u8, simd::avg_u8(simd::load_u8(ctx.v31.u8), simd::load_u8(ctx.v30.u8)));
	// vperm128 v45,v11,v10,v7
	simd::store_i8(ctx.v45.u8, simd::permute_bytes(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8), simd::load_i8(ctx.v7.u8)));
	// vavgub v5,v5,v4
	simd::store_u8(ctx.v5.u8, simd::avg_u8(simd::load_u8(ctx.v5.u8), simd::load_u8(ctx.v4.u8)));
	// vperm128 v44,v29,v28,v6
	simd::store_i8(ctx.v44.u8, simd::permute_bytes(simd::load_i8(ctx.v29.u8), simd::load_i8(ctx.v28.u8), simd::load_i8(ctx.v6.u8)));
	// vavgub v4,v4,v3
	simd::store_u8(ctx.v4.u8, simd::avg_u8(simd::load_u8(ctx.v4.u8), simd::load_u8(ctx.v3.u8)));
	// vperm128 v43,v27,v26,v6
	simd::store_i8(ctx.v43.u8, simd::permute_bytes(simd::load_i8(ctx.v27.u8), simd::load_i8(ctx.v26.u8), simd::load_i8(ctx.v6.u8)));
	// vavgub v3,v3,v2
	simd::store_u8(ctx.v3.u8, simd::avg_u8(simd::load_u8(ctx.v3.u8), simd::load_u8(ctx.v2.u8)));
	// vperm128 v42,v13,v12,v6
	simd::store_i8(ctx.v42.u8, simd::permute_bytes(simd::load_i8(ctx.v13.u8), simd::load_i8(ctx.v12.u8), simd::load_i8(ctx.v6.u8)));
	// vavgub v2,v2,v1
	simd::store_u8(ctx.v2.u8, simd::avg_u8(simd::load_u8(ctx.v2.u8), simd::load_u8(ctx.v1.u8)));
	// vperm128 v41,v11,v10,v6
	simd::store_i8(ctx.v41.u8, simd::permute_bytes(simd::load_i8(ctx.v11.u8), simd::load_i8(ctx.v10.u8), simd::load_i8(ctx.v6.u8)));
	// lvx128 v22,r0,r5
	simd::store_shuffled(ctx.v22, simd::load_and_shuffle(base + ((ctx.r5.u32) & ~0xF), VectorMaskL));
	// vsububs v9,v21,v16
	simd::store_u8(ctx.v9.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v21.u8), simd::load_u8(ctx.v16.u8)));
	// li r5,32
	ctx.r5.s64 = 32;
	// lvx128 v20,r0,r3
	simd::store_shuffled(ctx.v20, simd::load_and_shuffle(base + ((ctx.r3.u32) & ~0xF), VectorMaskL));
	// vand128 v15,v59,v0
	simd::store_u8(ctx.v15.u8, simd::and_u8(simd::load_u8(ctx.v59.u8), simd::load_u8(ctx.v0.u8)));
	// li r3,64
	ctx.r3.s64 = 64;
	// vavgub v1,v1,v31
	simd::store_u8(ctx.v1.u8, simd::avg_u8(simd::load_u8(ctx.v1.u8), simd::load_u8(ctx.v31.u8)));
	// lvx128 v19,r0,r11
	simd::store_shuffled(ctx.v19, simd::load_and_shuffle(base + ((ctx.r11.u32) & ~0xF), VectorMaskL));
	// vsububs v21,v24,v25
	simd::store_u8(ctx.v21.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v24.u8), simd::load_u8(ctx.v25.u8)));
	// li r11,80
	ctx.r11.s64 = 80;
	// lvx128 v23,r0,r6
	simd::store_shuffled(ctx.v23, simd::load_and_shuffle(base + ((ctx.r6.u32) & ~0xF), VectorMaskL));
	// vsububs v4,v4,v22
	simd::store_u8(ctx.v4.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v4.u8), simd::load_u8(ctx.v22.u8)));
	// lvx128 v18,r0,r10
	simd::store_shuffled(ctx.v18, simd::load_and_shuffle(base + ((ctx.r10.u32) & ~0xF), VectorMaskL));
	// li r10,96
	ctx.r10.s64 = 96;
	// stvlx128 v48,r0,r22
{
	uint32_t addr = 
ctx.r22.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v48), 15 - i));
}
	// vsububs v8,v14,v15
	simd::store_u8(ctx.v8.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v14.u8), simd::load_u8(ctx.v15.u8)));
	// stvlx128 v47,r22,r23
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r23.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v47), 15 - i));
}
	// vsububs v5,v5,v23
	simd::store_u8(ctx.v5.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v5.u8), simd::load_u8(ctx.v23.u8)));
	// stvlx128 v46,r22,r5
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r5.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v46), 15 - i));
}
	// vsububs v3,v3,v20
	simd::store_u8(ctx.v3.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v3.u8), simd::load_u8(ctx.v20.u8)));
	// vsububs v2,v2,v19
	simd::store_u8(ctx.v2.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v2.u8), simd::load_u8(ctx.v19.u8)));
	// stvlx128 v45,r22,r4
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v45), 15 - i));
}
	// vsububs v1,v1,v18
	simd::store_u8(ctx.v1.u8, simd::sub_saturate_u8(simd::load_u8(ctx.v1.u8), simd::load_u8(ctx.v18.u8)));
	// stvlx128 v44,r22,r3
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r3.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v44), 15 - i));
}
	// vor128 v63,v21,v21
	simd::store_i8(ctx.v63.u8, simd::load_i8(ctx.v21.u8));
	// stvlx128 v43,r22,r11
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v43), 15 - i));
}
	// stvlx128 v42,r22,r10
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v42), 15 - i));
}
	// vperm128 v40,v9,v8,v7
	simd::store_i8(ctx.v40.u8, simd::permute_bytes(simd::load_i8(ctx.v9.u8), simd::load_i8(ctx.v8.u8), simd::load_i8(ctx.v7.u8)));
	// vperm128 v39,v5,v4,v7
	simd::store_i8(ctx.v39.u8, simd::permute_bytes(simd::load_i8(ctx.v5.u8), simd::load_i8(ctx.v4.u8), simd::load_i8(ctx.v7.u8)));
	// li r6,160
	ctx.r6.s64 = 160;
	// vperm128 v38,v3,v2,v7
	simd::store_i8(ctx.v38.u8, simd::permute_bytes(simd::load_i8(ctx.v3.u8), simd::load_i8(ctx.v2.u8), simd::load_i8(ctx.v7.u8)));
	// li r5,176
	ctx.r5.s64 = 176;
	// vperm128 v37,v1,v63,v7
	simd::store_i8(ctx.v37.u8, simd::permute_bytes(simd::load_i8(ctx.v1.u8), simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v7.u8)));
	// li r4,192
	ctx.r4.s64 = 192;
	// vperm128 v36,v9,v8,v6
	simd::store_i8(ctx.v36.u8, simd::permute_bytes(simd::load_i8(ctx.v9.u8), simd::load_i8(ctx.v8.u8), simd::load_i8(ctx.v6.u8)));
	// stvlx128 v41,r22,r9
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r9.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v41), 15 - i));
}
	// vperm128 v35,v5,v4,v6
	simd::store_i8(ctx.v35.u8, simd::permute_bytes(simd::load_i8(ctx.v5.u8), simd::load_i8(ctx.v4.u8), simd::load_i8(ctx.v6.u8)));
	// li r3,208
	ctx.r3.s64 = 208;
	// vperm128 v34,v3,v2,v6
	simd::store_i8(ctx.v34.u8, simd::permute_bytes(simd::load_i8(ctx.v3.u8), simd::load_i8(ctx.v2.u8), simd::load_i8(ctx.v6.u8)));
	// vperm128 v33,v1,v63,v6
	simd::store_i8(ctx.v33.u8, simd::permute_bytes(simd::load_i8(ctx.v1.u8), simd::load_i8(ctx.v63.u8), simd::load_i8(ctx.v6.u8)));
	// stvlx128 v40,r22,r8
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r8.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v40), 15 - i));
}
	// li r11,224
	ctx.r11.s64 = 224;
	// stvlx128 v39,r22,r7
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r7.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v39), 15 - i));
}
	// li r10,240
	ctx.r10.s64 = 240;
	// stvlx128 v38,r22,r6
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r6.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v38), 15 - i));
}
	// stvlx128 v37,r22,r5
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r5.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v37), 15 - i));
}
	// stvlx128 v36,r22,r4
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r4.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v36), 15 - i));
}
	// stvlx128 v35,r22,r3
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r3.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v35), 15 - i));
}
	// stvlx128 v34,r22,r11
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r11.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v34), 15 - i));
}
	// stvlx128 v33,r22,r10
{
	uint32_t addr = 
ctx.r22.u32 + ctx.r10.u32;
	uint32_t tmp_off = addr & 0xF;
	for (size_t i = 0; i < (16 - tmp_off); i++)
		PPC_STORE_U8(addr + i, simd::extract_u8(simd::to_vec128i(ctx.v33), 15 - i));
}
	// b 0x8233e484
	__restgprlr_15(ctx, base);
	return;
}

