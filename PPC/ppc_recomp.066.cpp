#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_82383C90"))) PPC_WEAK_FUNC(sub_82383C90);
PPC_FUNC_IMPL(__imp__sub_82383C90) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,26516
	ctx.r31.s64 = ctx.r11.s64 + 26516;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82383d18
	if (ctx.cr6.eq) goto loc_82383D18;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82383cd0
	if (!ctx.cr6.eq) goto loc_82383CD0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82383CD0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82383d18
	if (ctx.cr6.eq) goto loc_82383D18;
loc_82383CD8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82383D08;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82383cd8
	if (!ctx.cr6.eq) goto loc_82383CD8;
loc_82383D18:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82383d34
	if (ctx.cr6.eq) goto loc_82383D34;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82383D34;
	sub_82246E18(ctx, base);
loc_82383D34:
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

__attribute__((alias("__imp__sub_82383D4C"))) PPC_WEAK_FUNC(sub_82383D4C);
PPC_FUNC_IMPL(__imp__sub_82383D4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383D50"))) PPC_WEAK_FUNC(sub_82383D50);
PPC_FUNC_IMPL(__imp__sub_82383D50) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,26572
	ctx.r31.s64 = ctx.r11.s64 + 26572;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82383dd8
	if (ctx.cr6.eq) goto loc_82383DD8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82383d90
	if (!ctx.cr6.eq) goto loc_82383D90;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82383D90:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82383dd8
	if (ctx.cr6.eq) goto loc_82383DD8;
loc_82383D98:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82383DC8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82383d98
	if (!ctx.cr6.eq) goto loc_82383D98;
loc_82383DD8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82383df4
	if (ctx.cr6.eq) goto loc_82383DF4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82383DF4;
	sub_82246E18(ctx, base);
loc_82383DF4:
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

__attribute__((alias("__imp__sub_82383E0C"))) PPC_WEAK_FUNC(sub_82383E0C);
PPC_FUNC_IMPL(__imp__sub_82383E0C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383E10"))) PPC_WEAK_FUNC(sub_82383E10);
PPC_FUNC_IMPL(__imp__sub_82383E10) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,26628
	ctx.r31.s64 = ctx.r11.s64 + 26628;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82383e98
	if (ctx.cr6.eq) goto loc_82383E98;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82383e50
	if (!ctx.cr6.eq) goto loc_82383E50;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82383E50:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82383e98
	if (ctx.cr6.eq) goto loc_82383E98;
loc_82383E58:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82383E88;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82383e58
	if (!ctx.cr6.eq) goto loc_82383E58;
loc_82383E98:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82383eb4
	if (ctx.cr6.eq) goto loc_82383EB4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82383EB4;
	sub_82246E18(ctx, base);
loc_82383EB4:
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

__attribute__((alias("__imp__sub_82383ECC"))) PPC_WEAK_FUNC(sub_82383ECC);
PPC_FUNC_IMPL(__imp__sub_82383ECC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383ED0"))) PPC_WEAK_FUNC(sub_82383ED0);
PPC_FUNC_IMPL(__imp__sub_82383ED0) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,26684
	ctx.r31.s64 = ctx.r11.s64 + 26684;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82383f58
	if (ctx.cr6.eq) goto loc_82383F58;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82383f10
	if (!ctx.cr6.eq) goto loc_82383F10;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82383F10:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82383f58
	if (ctx.cr6.eq) goto loc_82383F58;
loc_82383F18:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82383F48;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82383f18
	if (!ctx.cr6.eq) goto loc_82383F18;
loc_82383F58:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82383f74
	if (ctx.cr6.eq) goto loc_82383F74;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82383F74;
	sub_82246E18(ctx, base);
loc_82383F74:
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

__attribute__((alias("__imp__sub_82383F8C"))) PPC_WEAK_FUNC(sub_82383F8C);
PPC_FUNC_IMPL(__imp__sub_82383F8C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82383F90"))) PPC_WEAK_FUNC(sub_82383F90);
PPC_FUNC_IMPL(__imp__sub_82383F90) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,26740
	ctx.r31.s64 = ctx.r11.s64 + 26740;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384018
	if (ctx.cr6.eq) goto loc_82384018;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82383fd0
	if (!ctx.cr6.eq) goto loc_82383FD0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82383FD0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384018
	if (ctx.cr6.eq) goto loc_82384018;
loc_82383FD8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384008;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82383fd8
	if (!ctx.cr6.eq) goto loc_82383FD8;
loc_82384018:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384034
	if (ctx.cr6.eq) goto loc_82384034;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384034;
	sub_82246E18(ctx, base);
loc_82384034:
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

__attribute__((alias("__imp__sub_8238404C"))) PPC_WEAK_FUNC(sub_8238404C);
PPC_FUNC_IMPL(__imp__sub_8238404C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384050"))) PPC_WEAK_FUNC(sub_82384050);
PPC_FUNC_IMPL(__imp__sub_82384050) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// li r30,9
	ctx.r30.s64 = 9;
	// addi r11,r11,26816
	ctx.r11.s64 = ctx.r11.s64 + 26816;
	// addi r31,r11,1760
	ctx.r31.s64 = ctx.r11.s64 + 1760;
loc_82384074:
	// addi r31,r31,-176
	ctx.r31.s64 = ctx.r31.s64 + -176;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82308a40
	ctx.lr = 0x82384080;
	sub_82308A40(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82384074
	if (!ctx.cr0.lt) goto loc_82384074;
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

__attribute__((alias("__imp__sub_823840A0"))) PPC_WEAK_FUNC(sub_823840A0);
PPC_FUNC_IMPL(__imp__sub_823840A0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r11,r11,26796
	ctx.r11.s64 = ctx.r11.s64 + 26796;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823840BC"))) PPC_WEAK_FUNC(sub_823840BC);
PPC_FUNC_IMPL(__imp__sub_823840BC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823840C0"))) PPC_WEAK_FUNC(sub_823840C0);
PPC_FUNC_IMPL(__imp__sub_823840C0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r11,r11,28656
	ctx.r11.s64 = ctx.r11.s64 + 28656;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823840DC"))) PPC_WEAK_FUNC(sub_823840DC);
PPC_FUNC_IMPL(__imp__sub_823840DC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823840E0"))) PPC_WEAK_FUNC(sub_823840E0);
PPC_FUNC_IMPL(__imp__sub_823840E0) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,28676
	ctx.r31.s64 = ctx.r11.s64 + 28676;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384168
	if (ctx.cr6.eq) goto loc_82384168;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384120
	if (!ctx.cr6.eq) goto loc_82384120;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384120:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384168
	if (ctx.cr6.eq) goto loc_82384168;
loc_82384128:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384158;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384128
	if (!ctx.cr6.eq) goto loc_82384128;
loc_82384168:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384184
	if (ctx.cr6.eq) goto loc_82384184;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384184;
	sub_82246E18(ctx, base);
loc_82384184:
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

__attribute__((alias("__imp__sub_8238419C"))) PPC_WEAK_FUNC(sub_8238419C);
PPC_FUNC_IMPL(__imp__sub_8238419C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823841A0"))) PPC_WEAK_FUNC(sub_823841A0);
PPC_FUNC_IMPL(__imp__sub_823841A0) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,28732
	ctx.r31.s64 = ctx.r11.s64 + 28732;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384228
	if (ctx.cr6.eq) goto loc_82384228;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823841e0
	if (!ctx.cr6.eq) goto loc_823841E0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823841E0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384228
	if (ctx.cr6.eq) goto loc_82384228;
loc_823841E8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384218;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823841e8
	if (!ctx.cr6.eq) goto loc_823841E8;
loc_82384228:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384244
	if (ctx.cr6.eq) goto loc_82384244;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384244;
	sub_82246E18(ctx, base);
loc_82384244:
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

__attribute__((alias("__imp__sub_8238425C"))) PPC_WEAK_FUNC(sub_8238425C);
PPC_FUNC_IMPL(__imp__sub_8238425C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384260"))) PPC_WEAK_FUNC(sub_82384260);
PPC_FUNC_IMPL(__imp__sub_82384260) {
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
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r31,r11,10608
	ctx.r31.s64 = ctx.r11.s64 + 10608;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823842e8
	if (ctx.cr6.eq) goto loc_823842E8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823842a0
	if (!ctx.cr6.eq) goto loc_823842A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823842A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823842e8
	if (ctx.cr6.eq) goto loc_823842E8;
loc_823842A8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823842D8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823842a8
	if (!ctx.cr6.eq) goto loc_823842A8;
loc_823842E8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384304
	if (ctx.cr6.eq) goto loc_82384304;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384304;
	sub_82246E18(ctx, base);
loc_82384304:
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

__attribute__((alias("__imp__sub_8238431C"))) PPC_WEAK_FUNC(sub_8238431C);
PPC_FUNC_IMPL(__imp__sub_8238431C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384320"))) PPC_WEAK_FUNC(sub_82384320);
PPC_FUNC_IMPL(__imp__sub_82384320) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,28788
	ctx.r31.s64 = ctx.r11.s64 + 28788;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823843a8
	if (ctx.cr6.eq) goto loc_823843A8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384360
	if (!ctx.cr6.eq) goto loc_82384360;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384360:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823843a8
	if (ctx.cr6.eq) goto loc_823843A8;
loc_82384368:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384398;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384368
	if (!ctx.cr6.eq) goto loc_82384368;
loc_823843A8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823843c4
	if (ctx.cr6.eq) goto loc_823843C4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823843C4;
	sub_82246E18(ctx, base);
loc_823843C4:
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

__attribute__((alias("__imp__sub_823843DC"))) PPC_WEAK_FUNC(sub_823843DC);
PPC_FUNC_IMPL(__imp__sub_823843DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823843E0"))) PPC_WEAK_FUNC(sub_823843E0);
PPC_FUNC_IMPL(__imp__sub_823843E0) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,28844
	ctx.r31.s64 = ctx.r11.s64 + 28844;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384468
	if (ctx.cr6.eq) goto loc_82384468;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384420
	if (!ctx.cr6.eq) goto loc_82384420;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384420:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384468
	if (ctx.cr6.eq) goto loc_82384468;
loc_82384428:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384458;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384428
	if (!ctx.cr6.eq) goto loc_82384428;
loc_82384468:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384484
	if (ctx.cr6.eq) goto loc_82384484;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384484;
	sub_82246E18(ctx, base);
loc_82384484:
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

__attribute__((alias("__imp__sub_8238449C"))) PPC_WEAK_FUNC(sub_8238449C);
PPC_FUNC_IMPL(__imp__sub_8238449C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823844A0"))) PPC_WEAK_FUNC(sub_823844A0);
PPC_FUNC_IMPL(__imp__sub_823844A0) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,28900
	ctx.r31.s64 = ctx.r11.s64 + 28900;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384528
	if (ctx.cr6.eq) goto loc_82384528;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823844e0
	if (!ctx.cr6.eq) goto loc_823844E0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823844E0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384528
	if (ctx.cr6.eq) goto loc_82384528;
loc_823844E8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384518;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823844e8
	if (!ctx.cr6.eq) goto loc_823844E8;
loc_82384528:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384544
	if (ctx.cr6.eq) goto loc_82384544;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384544;
	sub_82246E18(ctx, base);
loc_82384544:
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

__attribute__((alias("__imp__sub_8238455C"))) PPC_WEAK_FUNC(sub_8238455C);
PPC_FUNC_IMPL(__imp__sub_8238455C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384560"))) PPC_WEAK_FUNC(sub_82384560);
PPC_FUNC_IMPL(__imp__sub_82384560) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,28956
	ctx.r31.s64 = ctx.r11.s64 + 28956;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823845e8
	if (ctx.cr6.eq) goto loc_823845E8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823845a0
	if (!ctx.cr6.eq) goto loc_823845A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823845A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823845e8
	if (ctx.cr6.eq) goto loc_823845E8;
loc_823845A8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823845D8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823845a8
	if (!ctx.cr6.eq) goto loc_823845A8;
loc_823845E8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384604
	if (ctx.cr6.eq) goto loc_82384604;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384604;
	sub_82246E18(ctx, base);
loc_82384604:
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

__attribute__((alias("__imp__sub_8238461C"))) PPC_WEAK_FUNC(sub_8238461C);
PPC_FUNC_IMPL(__imp__sub_8238461C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384620"))) PPC_WEAK_FUNC(sub_82384620);
PPC_FUNC_IMPL(__imp__sub_82384620) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,29012
	ctx.r31.s64 = ctx.r11.s64 + 29012;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823846a8
	if (ctx.cr6.eq) goto loc_823846A8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384660
	if (!ctx.cr6.eq) goto loc_82384660;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384660:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823846a8
	if (ctx.cr6.eq) goto loc_823846A8;
loc_82384668:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384698;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384668
	if (!ctx.cr6.eq) goto loc_82384668;
loc_823846A8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823846c4
	if (ctx.cr6.eq) goto loc_823846C4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823846C4;
	sub_82246E18(ctx, base);
loc_823846C4:
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

__attribute__((alias("__imp__sub_823846DC"))) PPC_WEAK_FUNC(sub_823846DC);
PPC_FUNC_IMPL(__imp__sub_823846DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823846E0"))) PPC_WEAK_FUNC(sub_823846E0);
PPC_FUNC_IMPL(__imp__sub_823846E0) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,29068
	ctx.r31.s64 = ctx.r11.s64 + 29068;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384768
	if (ctx.cr6.eq) goto loc_82384768;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384720
	if (!ctx.cr6.eq) goto loc_82384720;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384720:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384768
	if (ctx.cr6.eq) goto loc_82384768;
loc_82384728:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384758;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384728
	if (!ctx.cr6.eq) goto loc_82384728;
loc_82384768:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384784
	if (ctx.cr6.eq) goto loc_82384784;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384784;
	sub_82246E18(ctx, base);
loc_82384784:
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

__attribute__((alias("__imp__sub_8238479C"))) PPC_WEAK_FUNC(sub_8238479C);
PPC_FUNC_IMPL(__imp__sub_8238479C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823847A0"))) PPC_WEAK_FUNC(sub_823847A0);
PPC_FUNC_IMPL(__imp__sub_823847A0) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,29124
	ctx.r31.s64 = ctx.r11.s64 + 29124;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384828
	if (ctx.cr6.eq) goto loc_82384828;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823847e0
	if (!ctx.cr6.eq) goto loc_823847E0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823847E0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384828
	if (ctx.cr6.eq) goto loc_82384828;
loc_823847E8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384818;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823847e8
	if (!ctx.cr6.eq) goto loc_823847E8;
loc_82384828:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384844
	if (ctx.cr6.eq) goto loc_82384844;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384844;
	sub_82246E18(ctx, base);
loc_82384844:
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

__attribute__((alias("__imp__sub_8238485C"))) PPC_WEAK_FUNC(sub_8238485C);
PPC_FUNC_IMPL(__imp__sub_8238485C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384860"))) PPC_WEAK_FUNC(sub_82384860);
PPC_FUNC_IMPL(__imp__sub_82384860) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,29180
	ctx.r31.s64 = ctx.r11.s64 + 29180;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823848e8
	if (ctx.cr6.eq) goto loc_823848E8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823848a0
	if (!ctx.cr6.eq) goto loc_823848A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823848A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823848e8
	if (ctx.cr6.eq) goto loc_823848E8;
loc_823848A8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823848D8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823848a8
	if (!ctx.cr6.eq) goto loc_823848A8;
loc_823848E8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384904
	if (ctx.cr6.eq) goto loc_82384904;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384904;
	sub_82246E18(ctx, base);
loc_82384904:
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

__attribute__((alias("__imp__sub_8238491C"))) PPC_WEAK_FUNC(sub_8238491C);
PPC_FUNC_IMPL(__imp__sub_8238491C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384920"))) PPC_WEAK_FUNC(sub_82384920);
PPC_FUNC_IMPL(__imp__sub_82384920) {
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
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r31,r11,29236
	ctx.r31.s64 = ctx.r11.s64 + 29236;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823849a8
	if (ctx.cr6.eq) goto loc_823849A8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384960
	if (!ctx.cr6.eq) goto loc_82384960;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384960:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823849a8
	if (ctx.cr6.eq) goto loc_823849A8;
loc_82384968:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384998;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384968
	if (!ctx.cr6.eq) goto loc_82384968;
loc_823849A8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823849c4
	if (ctx.cr6.eq) goto loc_823849C4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823849C4;
	sub_82246E18(ctx, base);
loc_823849C4:
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

__attribute__((alias("__imp__sub_823849DC"))) PPC_WEAK_FUNC(sub_823849DC);
PPC_FUNC_IMPL(__imp__sub_823849DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823849E0"))) PPC_WEAK_FUNC(sub_823849E0);
PPC_FUNC_IMPL(__imp__sub_823849E0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32178
	ctx.r11.s64 = -2108817408;
	// addi r11,r11,29296
	ctx.r11.s64 = ctx.r11.s64 + 29296;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823849FC"))) PPC_WEAK_FUNC(sub_823849FC);
PPC_FUNC_IMPL(__imp__sub_823849FC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82384A00"))) PPC_WEAK_FUNC(sub_82384A00);
PPC_FUNC_IMPL(__imp__sub_82384A00) {
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
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r31,r11,10664
	ctx.r31.s64 = ctx.r11.s64 + 10664;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384a88
	if (ctx.cr6.eq) goto loc_82384A88;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384a40
	if (!ctx.cr6.eq) goto loc_82384A40;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384A40:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384a88
	if (ctx.cr6.eq) goto loc_82384A88;
loc_82384A48:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384A78;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384a48
	if (!ctx.cr6.eq) goto loc_82384A48;
loc_82384A88:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384aa4
	if (ctx.cr6.eq) goto loc_82384AA4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384AA4;
	sub_82246E18(ctx, base);
loc_82384AA4:
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

__attribute__((alias("__imp__sub_82384ABC"))) PPC_WEAK_FUNC(sub_82384ABC);
PPC_FUNC_IMPL(__imp__sub_82384ABC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384AC0"))) PPC_WEAK_FUNC(sub_82384AC0);
PPC_FUNC_IMPL(__imp__sub_82384AC0) {
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
	// lis r11,-32177
	ctx.r11.s64 = -2108751872;
	// addi r31,r11,29324
	ctx.r31.s64 = ctx.r11.s64 + 29324;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384b48
	if (ctx.cr6.eq) goto loc_82384B48;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384b00
	if (!ctx.cr6.eq) goto loc_82384B00;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384B00:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384b48
	if (ctx.cr6.eq) goto loc_82384B48;
loc_82384B08:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384B38;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384b08
	if (!ctx.cr6.eq) goto loc_82384B08;
loc_82384B48:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384b64
	if (ctx.cr6.eq) goto loc_82384B64;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384B64;
	sub_82246E18(ctx, base);
loc_82384B64:
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

__attribute__((alias("__imp__sub_82384B7C"))) PPC_WEAK_FUNC(sub_82384B7C);
PPC_FUNC_IMPL(__imp__sub_82384B7C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384B80"))) PPC_WEAK_FUNC(sub_82384B80);
PPC_FUNC_IMPL(__imp__sub_82384B80) {
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
	// lis r11,-32177
	ctx.r11.s64 = -2108751872;
	// addi r31,r11,29380
	ctx.r31.s64 = ctx.r11.s64 + 29380;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384c08
	if (ctx.cr6.eq) goto loc_82384C08;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384bc0
	if (!ctx.cr6.eq) goto loc_82384BC0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384BC0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384c08
	if (ctx.cr6.eq) goto loc_82384C08;
loc_82384BC8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384BF8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384bc8
	if (!ctx.cr6.eq) goto loc_82384BC8;
loc_82384C08:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384c24
	if (ctx.cr6.eq) goto loc_82384C24;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384C24;
	sub_82246E18(ctx, base);
loc_82384C24:
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

__attribute__((alias("__imp__sub_82384C3C"))) PPC_WEAK_FUNC(sub_82384C3C);
PPC_FUNC_IMPL(__imp__sub_82384C3C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384C40"))) PPC_WEAK_FUNC(sub_82384C40);
PPC_FUNC_IMPL(__imp__sub_82384C40) {
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
	// lis r11,-32177
	ctx.r11.s64 = -2108751872;
	// addi r31,r11,29436
	ctx.r31.s64 = ctx.r11.s64 + 29436;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384cc8
	if (ctx.cr6.eq) goto loc_82384CC8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384c80
	if (!ctx.cr6.eq) goto loc_82384C80;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384C80:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384cc8
	if (ctx.cr6.eq) goto loc_82384CC8;
loc_82384C88:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384CB8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384c88
	if (!ctx.cr6.eq) goto loc_82384C88;
loc_82384CC8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384ce4
	if (ctx.cr6.eq) goto loc_82384CE4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384CE4;
	sub_82246E18(ctx, base);
loc_82384CE4:
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

__attribute__((alias("__imp__sub_82384CFC"))) PPC_WEAK_FUNC(sub_82384CFC);
PPC_FUNC_IMPL(__imp__sub_82384CFC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384D00"))) PPC_WEAK_FUNC(sub_82384D00);
PPC_FUNC_IMPL(__imp__sub_82384D00) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32177
	ctx.r11.s64 = -2108751872;
	// addi r11,r11,29496
	ctx.r11.s64 = ctx.r11.s64 + 29496;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82384D1C"))) PPC_WEAK_FUNC(sub_82384D1C);
PPC_FUNC_IMPL(__imp__sub_82384D1C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82384D20"))) PPC_WEAK_FUNC(sub_82384D20);
PPC_FUNC_IMPL(__imp__sub_82384D20) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,-3244
	ctx.r31.s64 = ctx.r11.s64 + -3244;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384da8
	if (ctx.cr6.eq) goto loc_82384DA8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384d60
	if (!ctx.cr6.eq) goto loc_82384D60;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384D60:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384da8
	if (ctx.cr6.eq) goto loc_82384DA8;
loc_82384D68:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384D98;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384d68
	if (!ctx.cr6.eq) goto loc_82384D68;
loc_82384DA8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384dc4
	if (ctx.cr6.eq) goto loc_82384DC4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384DC4;
	sub_82246E18(ctx, base);
loc_82384DC4:
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

__attribute__((alias("__imp__sub_82384DDC"))) PPC_WEAK_FUNC(sub_82384DDC);
PPC_FUNC_IMPL(__imp__sub_82384DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384DE0"))) PPC_WEAK_FUNC(sub_82384DE0);
PPC_FUNC_IMPL(__imp__sub_82384DE0) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,-3188
	ctx.r31.s64 = ctx.r11.s64 + -3188;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384e68
	if (ctx.cr6.eq) goto loc_82384E68;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384e20
	if (!ctx.cr6.eq) goto loc_82384E20;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384E20:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384e68
	if (ctx.cr6.eq) goto loc_82384E68;
loc_82384E28:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384E58;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384e28
	if (!ctx.cr6.eq) goto loc_82384E28;
loc_82384E68:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384e84
	if (ctx.cr6.eq) goto loc_82384E84;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384E84;
	sub_82246E18(ctx, base);
loc_82384E84:
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

__attribute__((alias("__imp__sub_82384E9C"))) PPC_WEAK_FUNC(sub_82384E9C);
PPC_FUNC_IMPL(__imp__sub_82384E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384EA0"))) PPC_WEAK_FUNC(sub_82384EA0);
PPC_FUNC_IMPL(__imp__sub_82384EA0) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,-3132
	ctx.r31.s64 = ctx.r11.s64 + -3132;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384f28
	if (ctx.cr6.eq) goto loc_82384F28;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384ee0
	if (!ctx.cr6.eq) goto loc_82384EE0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384EE0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384f28
	if (ctx.cr6.eq) goto loc_82384F28;
loc_82384EE8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384F18;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384ee8
	if (!ctx.cr6.eq) goto loc_82384EE8;
loc_82384F28:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82384f44
	if (ctx.cr6.eq) goto loc_82384F44;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82384F44;
	sub_82246E18(ctx, base);
loc_82384F44:
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

__attribute__((alias("__imp__sub_82384F5C"))) PPC_WEAK_FUNC(sub_82384F5C);
PPC_FUNC_IMPL(__imp__sub_82384F5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384F60"))) PPC_WEAK_FUNC(sub_82384F60);
PPC_FUNC_IMPL(__imp__sub_82384F60) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82384F64"))) PPC_WEAK_FUNC(sub_82384F64);
PPC_FUNC_IMPL(__imp__sub_82384F64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384F68"))) PPC_WEAK_FUNC(sub_82384F68);
PPC_FUNC_IMPL(__imp__sub_82384F68) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82384F6C"))) PPC_WEAK_FUNC(sub_82384F6C);
PPC_FUNC_IMPL(__imp__sub_82384F6C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82384F70"))) PPC_WEAK_FUNC(sub_82384F70);
PPC_FUNC_IMPL(__imp__sub_82384F70) {
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
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r31,r11,10720
	ctx.r31.s64 = ctx.r11.s64 + 10720;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384ff8
	if (ctx.cr6.eq) goto loc_82384FF8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82384fb0
	if (!ctx.cr6.eq) goto loc_82384FB0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82384FB0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82384ff8
	if (ctx.cr6.eq) goto loc_82384FF8;
loc_82384FB8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82384FE8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82384fb8
	if (!ctx.cr6.eq) goto loc_82384FB8;
loc_82384FF8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385014
	if (ctx.cr6.eq) goto loc_82385014;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385014;
	sub_82246E18(ctx, base);
loc_82385014:
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

__attribute__((alias("__imp__sub_8238502C"))) PPC_WEAK_FUNC(sub_8238502C);
PPC_FUNC_IMPL(__imp__sub_8238502C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385030"))) PPC_WEAK_FUNC(sub_82385030);
PPC_FUNC_IMPL(__imp__sub_82385030) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,2732
	ctx.r31.s64 = ctx.r11.s64 + 2732;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823850b8
	if (ctx.cr6.eq) goto loc_823850B8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82385070
	if (!ctx.cr6.eq) goto loc_82385070;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82385070:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823850b8
	if (ctx.cr6.eq) goto loc_823850B8;
loc_82385078:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823850A8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82385078
	if (!ctx.cr6.eq) goto loc_82385078;
loc_823850B8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823850d4
	if (ctx.cr6.eq) goto loc_823850D4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823850D4;
	sub_82246E18(ctx, base);
loc_823850D4:
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

__attribute__((alias("__imp__sub_823850EC"))) PPC_WEAK_FUNC(sub_823850EC);
PPC_FUNC_IMPL(__imp__sub_823850EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823850F0"))) PPC_WEAK_FUNC(sub_823850F0);
PPC_FUNC_IMPL(__imp__sub_823850F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,2788
	ctx.r31.s64 = ctx.r11.s64 + 2788;
	// lwz r11,2788(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2788);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385120
	if (ctx.cr6.eq) goto loc_82385120;
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385120;
	sub_82080000(ctx, base);
loc_82385120:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385134
	if (ctx.cr6.eq) goto loc_82385134;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x82246e18
	ctx.lr = 0x82385134;
	sub_82246E18(ctx, base);
loc_82385134:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82385148"))) PPC_WEAK_FUNC(sub_82385148);
PPC_FUNC_IMPL(__imp__sub_82385148) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,2832
	ctx.r31.s64 = ctx.r11.s64 + 2832;
	// lwz r11,2832(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2832);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385178
	if (ctx.cr6.eq) goto loc_82385178;
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385178;
	sub_82080000(ctx, base);
loc_82385178:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8238518c
	if (ctx.cr6.eq) goto loc_8238518C;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x82246e18
	ctx.lr = 0x8238518C;
	sub_82246E18(ctx, base);
loc_8238518C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823851A0"))) PPC_WEAK_FUNC(sub_823851A0);
PPC_FUNC_IMPL(__imp__sub_823851A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,2876
	ctx.r31.s64 = ctx.r11.s64 + 2876;
	// lwz r11,2876(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2876);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823851d0
	if (ctx.cr6.eq) goto loc_823851D0;
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823851D0;
	sub_82080000(ctx, base);
loc_823851D0:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823851e4
	if (ctx.cr6.eq) goto loc_823851E4;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x82246e18
	ctx.lr = 0x823851E4;
	sub_82246E18(ctx, base);
loc_823851E4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823851F8"))) PPC_WEAK_FUNC(sub_823851F8);
PPC_FUNC_IMPL(__imp__sub_823851F8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,2920
	ctx.r31.s64 = ctx.r11.s64 + 2920;
	// lwz r11,2920(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2920);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385228
	if (ctx.cr6.eq) goto loc_82385228;
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385228;
	sub_82080000(ctx, base);
loc_82385228:
	// lwz r11,28(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8238523c
	if (ctx.cr6.eq) goto loc_8238523C;
	// lwz r3,28(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x82246e18
	ctx.lr = 0x8238523C;
	sub_82246E18(ctx, base);
loc_8238523C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82385250"))) PPC_WEAK_FUNC(sub_82385250);
PPC_FUNC_IMPL(__imp__sub_82385250) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,2964
	ctx.r31.s64 = ctx.r11.s64 + 2964;
	// lwz r11,2964(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 2964);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385280
	if (ctx.cr6.eq) goto loc_82385280;
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385280;
	sub_82080000(ctx, base);
loc_82385280:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385294
	if (ctx.cr6.eq) goto loc_82385294;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x82246e18
	ctx.lr = 0x82385294;
	sub_82246E18(ctx, base);
loc_82385294:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823852A8"))) PPC_WEAK_FUNC(sub_823852A8);
PPC_FUNC_IMPL(__imp__sub_823852A8) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,3004
	ctx.r31.s64 = ctx.r11.s64 + 3004;
	// lwz r11,3004(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3004);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823852d8
	if (ctx.cr6.eq) goto loc_823852D8;
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823852D8;
	sub_82080000(ctx, base);
loc_823852D8:
	// lwz r11,24(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823852ec
	if (ctx.cr6.eq) goto loc_823852EC;
	// lwz r3,24(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x82246e18
	ctx.lr = 0x823852EC;
	sub_82246E18(ctx, base);
loc_823852EC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82385300"))) PPC_WEAK_FUNC(sub_82385300);
PPC_FUNC_IMPL(__imp__sub_82385300) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r3,r11,3044
	ctx.r3.s64 = ctx.r11.s64 + 3044;
	// b 0x82118e10
	sub_82118E10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238530C"))) PPC_WEAK_FUNC(sub_8238530C);
PPC_FUNC_IMPL(__imp__sub_8238530C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385310"))) PPC_WEAK_FUNC(sub_82385310);
PPC_FUNC_IMPL(__imp__sub_82385310) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r3,r11,3088
	ctx.r3.s64 = ctx.r11.s64 + 3088;
	// b 0x82118e10
	sub_82118E10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238531C"))) PPC_WEAK_FUNC(sub_8238531C);
PPC_FUNC_IMPL(__imp__sub_8238531C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385320"))) PPC_WEAK_FUNC(sub_82385320);
PPC_FUNC_IMPL(__imp__sub_82385320) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r3,r11,3132
	ctx.r3.s64 = ctx.r11.s64 + 3132;
	// b 0x82118e10
	sub_82118E10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238532C"))) PPC_WEAK_FUNC(sub_8238532C);
PPC_FUNC_IMPL(__imp__sub_8238532C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385330"))) PPC_WEAK_FUNC(sub_82385330);
PPC_FUNC_IMPL(__imp__sub_82385330) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r3,r11,3176
	ctx.r3.s64 = ctx.r11.s64 + 3176;
	// b 0x82118e10
	sub_82118E10(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238533C"))) PPC_WEAK_FUNC(sub_8238533C);
PPC_FUNC_IMPL(__imp__sub_8238533C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385340"))) PPC_WEAK_FUNC(sub_82385340);
PPC_FUNC_IMPL(__imp__sub_82385340) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r3,r11,3220
	ctx.r3.s64 = ctx.r11.s64 + 3220;
	// b 0x82119190
	sub_82119190(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238534C"))) PPC_WEAK_FUNC(sub_8238534C);
PPC_FUNC_IMPL(__imp__sub_8238534C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385350"))) PPC_WEAK_FUNC(sub_82385350);
PPC_FUNC_IMPL(__imp__sub_82385350) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r3,r11,3260
	ctx.r3.s64 = ctx.r11.s64 + 3260;
	// b 0x82119190
	sub_82119190(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238535C"))) PPC_WEAK_FUNC(sub_8238535C);
PPC_FUNC_IMPL(__imp__sub_8238535C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385360"))) PPC_WEAK_FUNC(sub_82385360);
PPC_FUNC_IMPL(__imp__sub_82385360) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,3300
	ctx.r31.s64 = ctx.r11.s64 + 3300;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823853e8
	if (ctx.cr6.eq) goto loc_823853E8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823853a0
	if (!ctx.cr6.eq) goto loc_823853A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823853A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823853e8
	if (ctx.cr6.eq) goto loc_823853E8;
loc_823853A8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823853D8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823853a8
	if (!ctx.cr6.eq) goto loc_823853A8;
loc_823853E8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385404
	if (ctx.cr6.eq) goto loc_82385404;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385404;
	sub_82246E18(ctx, base);
loc_82385404:
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

__attribute__((alias("__imp__sub_8238541C"))) PPC_WEAK_FUNC(sub_8238541C);
PPC_FUNC_IMPL(__imp__sub_8238541C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385420"))) PPC_WEAK_FUNC(sub_82385420);
PPC_FUNC_IMPL(__imp__sub_82385420) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,3356
	ctx.r31.s64 = ctx.r11.s64 + 3356;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823854a8
	if (ctx.cr6.eq) goto loc_823854A8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82385460
	if (!ctx.cr6.eq) goto loc_82385460;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82385460:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823854a8
	if (ctx.cr6.eq) goto loc_823854A8;
loc_82385468:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385498;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82385468
	if (!ctx.cr6.eq) goto loc_82385468;
loc_823854A8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823854c4
	if (ctx.cr6.eq) goto loc_823854C4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823854C4;
	sub_82246E18(ctx, base);
loc_823854C4:
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

__attribute__((alias("__imp__sub_823854DC"))) PPC_WEAK_FUNC(sub_823854DC);
PPC_FUNC_IMPL(__imp__sub_823854DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823854E0"))) PPC_WEAK_FUNC(sub_823854E0);
PPC_FUNC_IMPL(__imp__sub_823854E0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r11,r11,3412
	ctx.r11.s64 = ctx.r11.s64 + 3412;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823854FC"))) PPC_WEAK_FUNC(sub_823854FC);
PPC_FUNC_IMPL(__imp__sub_823854FC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82385500"))) PPC_WEAK_FUNC(sub_82385500);
PPC_FUNC_IMPL(__imp__sub_82385500) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// lwz r11,3432(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3432);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// b 0x82080000
	sub_82080000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238551C"))) PPC_WEAK_FUNC(sub_8238551C);
PPC_FUNC_IMPL(__imp__sub_8238551C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82385520"))) PPC_WEAK_FUNC(sub_82385520);
PPC_FUNC_IMPL(__imp__sub_82385520) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r11,r11,3444
	ctx.r11.s64 = ctx.r11.s64 + 3444;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238553C"))) PPC_WEAK_FUNC(sub_8238553C);
PPC_FUNC_IMPL(__imp__sub_8238553C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82385540"))) PPC_WEAK_FUNC(sub_82385540);
PPC_FUNC_IMPL(__imp__sub_82385540) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// lwz r11,3464(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 3464);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// b 0x82080000
	sub_82080000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238555C"))) PPC_WEAK_FUNC(sub_8238555C);
PPC_FUNC_IMPL(__imp__sub_8238555C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82385560"))) PPC_WEAK_FUNC(sub_82385560);
PPC_FUNC_IMPL(__imp__sub_82385560) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,5528
	ctx.r31.s64 = ctx.r11.s64 + 5528;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823855e8
	if (ctx.cr6.eq) goto loc_823855E8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823855a0
	if (!ctx.cr6.eq) goto loc_823855A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823855A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823855e8
	if (ctx.cr6.eq) goto loc_823855E8;
loc_823855A8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823855D8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823855a8
	if (!ctx.cr6.eq) goto loc_823855A8;
loc_823855E8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385604
	if (ctx.cr6.eq) goto loc_82385604;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385604;
	sub_82246E18(ctx, base);
loc_82385604:
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

__attribute__((alias("__imp__sub_8238561C"))) PPC_WEAK_FUNC(sub_8238561C);
PPC_FUNC_IMPL(__imp__sub_8238561C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385620"))) PPC_WEAK_FUNC(sub_82385620);
PPC_FUNC_IMPL(__imp__sub_82385620) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,5584
	ctx.r31.s64 = ctx.r11.s64 + 5584;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823856a8
	if (ctx.cr6.eq) goto loc_823856A8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82385660
	if (!ctx.cr6.eq) goto loc_82385660;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82385660:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823856a8
	if (ctx.cr6.eq) goto loc_823856A8;
loc_82385668:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385698;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82385668
	if (!ctx.cr6.eq) goto loc_82385668;
loc_823856A8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823856c4
	if (ctx.cr6.eq) goto loc_823856C4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823856C4;
	sub_82246E18(ctx, base);
loc_823856C4:
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

__attribute__((alias("__imp__sub_823856DC"))) PPC_WEAK_FUNC(sub_823856DC);
PPC_FUNC_IMPL(__imp__sub_823856DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823856E0"))) PPC_WEAK_FUNC(sub_823856E0);
PPC_FUNC_IMPL(__imp__sub_823856E0) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,5640
	ctx.r31.s64 = ctx.r11.s64 + 5640;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385768
	if (ctx.cr6.eq) goto loc_82385768;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82385720
	if (!ctx.cr6.eq) goto loc_82385720;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82385720:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385768
	if (ctx.cr6.eq) goto loc_82385768;
loc_82385728:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385758;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82385728
	if (!ctx.cr6.eq) goto loc_82385728;
loc_82385768:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385784
	if (ctx.cr6.eq) goto loc_82385784;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385784;
	sub_82246E18(ctx, base);
loc_82385784:
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

__attribute__((alias("__imp__sub_8238579C"))) PPC_WEAK_FUNC(sub_8238579C);
PPC_FUNC_IMPL(__imp__sub_8238579C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823857A0"))) PPC_WEAK_FUNC(sub_823857A0);
PPC_FUNC_IMPL(__imp__sub_823857A0) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,5696
	ctx.r31.s64 = ctx.r11.s64 + 5696;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385828
	if (ctx.cr6.eq) goto loc_82385828;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823857e0
	if (!ctx.cr6.eq) goto loc_823857E0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823857E0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385828
	if (ctx.cr6.eq) goto loc_82385828;
loc_823857E8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385818;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823857e8
	if (!ctx.cr6.eq) goto loc_823857E8;
loc_82385828:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385844
	if (ctx.cr6.eq) goto loc_82385844;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385844;
	sub_82246E18(ctx, base);
loc_82385844:
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

__attribute__((alias("__imp__sub_8238585C"))) PPC_WEAK_FUNC(sub_8238585C);
PPC_FUNC_IMPL(__imp__sub_8238585C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385860"))) PPC_WEAK_FUNC(sub_82385860);
PPC_FUNC_IMPL(__imp__sub_82385860) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,5752
	ctx.r31.s64 = ctx.r11.s64 + 5752;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823858e8
	if (ctx.cr6.eq) goto loc_823858E8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823858a0
	if (!ctx.cr6.eq) goto loc_823858A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823858A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823858e8
	if (ctx.cr6.eq) goto loc_823858E8;
loc_823858A8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823858D8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823858a8
	if (!ctx.cr6.eq) goto loc_823858A8;
loc_823858E8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385904
	if (ctx.cr6.eq) goto loc_82385904;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385904;
	sub_82246E18(ctx, base);
loc_82385904:
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

__attribute__((alias("__imp__sub_8238591C"))) PPC_WEAK_FUNC(sub_8238591C);
PPC_FUNC_IMPL(__imp__sub_8238591C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385920"))) PPC_WEAK_FUNC(sub_82385920);
PPC_FUNC_IMPL(__imp__sub_82385920) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,5808
	ctx.r31.s64 = ctx.r11.s64 + 5808;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823859a8
	if (ctx.cr6.eq) goto loc_823859A8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82385960
	if (!ctx.cr6.eq) goto loc_82385960;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82385960:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823859a8
	if (ctx.cr6.eq) goto loc_823859A8;
loc_82385968:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385998;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82385968
	if (!ctx.cr6.eq) goto loc_82385968;
loc_823859A8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823859c4
	if (ctx.cr6.eq) goto loc_823859C4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823859C4;
	sub_82246E18(ctx, base);
loc_823859C4:
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

__attribute__((alias("__imp__sub_823859DC"))) PPC_WEAK_FUNC(sub_823859DC);
PPC_FUNC_IMPL(__imp__sub_823859DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823859E0"))) PPC_WEAK_FUNC(sub_823859E0);
PPC_FUNC_IMPL(__imp__sub_823859E0) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,5864
	ctx.r31.s64 = ctx.r11.s64 + 5864;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385a68
	if (ctx.cr6.eq) goto loc_82385A68;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82385a20
	if (!ctx.cr6.eq) goto loc_82385A20;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82385A20:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385a68
	if (ctx.cr6.eq) goto loc_82385A68;
loc_82385A28:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385A58;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82385a28
	if (!ctx.cr6.eq) goto loc_82385A28;
loc_82385A68:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385a84
	if (ctx.cr6.eq) goto loc_82385A84;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385A84;
	sub_82246E18(ctx, base);
loc_82385A84:
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

__attribute__((alias("__imp__sub_82385A9C"))) PPC_WEAK_FUNC(sub_82385A9C);
PPC_FUNC_IMPL(__imp__sub_82385A9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385AA0"))) PPC_WEAK_FUNC(sub_82385AA0);
PPC_FUNC_IMPL(__imp__sub_82385AA0) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,5920
	ctx.r31.s64 = ctx.r11.s64 + 5920;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385b28
	if (ctx.cr6.eq) goto loc_82385B28;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82385ae0
	if (!ctx.cr6.eq) goto loc_82385AE0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82385AE0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385b28
	if (ctx.cr6.eq) goto loc_82385B28;
loc_82385AE8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385B18;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82385ae8
	if (!ctx.cr6.eq) goto loc_82385AE8;
loc_82385B28:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385b44
	if (ctx.cr6.eq) goto loc_82385B44;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385B44;
	sub_82246E18(ctx, base);
loc_82385B44:
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

__attribute__((alias("__imp__sub_82385B5C"))) PPC_WEAK_FUNC(sub_82385B5C);
PPC_FUNC_IMPL(__imp__sub_82385B5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385B60"))) PPC_WEAK_FUNC(sub_82385B60);
PPC_FUNC_IMPL(__imp__sub_82385B60) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,5976
	ctx.r31.s64 = ctx.r11.s64 + 5976;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385be8
	if (ctx.cr6.eq) goto loc_82385BE8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82385ba0
	if (!ctx.cr6.eq) goto loc_82385BA0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82385BA0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385be8
	if (ctx.cr6.eq) goto loc_82385BE8;
loc_82385BA8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385BD8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82385ba8
	if (!ctx.cr6.eq) goto loc_82385BA8;
loc_82385BE8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385c04
	if (ctx.cr6.eq) goto loc_82385C04;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385C04;
	sub_82246E18(ctx, base);
loc_82385C04:
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

__attribute__((alias("__imp__sub_82385C1C"))) PPC_WEAK_FUNC(sub_82385C1C);
PPC_FUNC_IMPL(__imp__sub_82385C1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385C20"))) PPC_WEAK_FUNC(sub_82385C20);
PPC_FUNC_IMPL(__imp__sub_82385C20) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6032
	ctx.r31.s64 = ctx.r11.s64 + 6032;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385ca8
	if (ctx.cr6.eq) goto loc_82385CA8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82385c60
	if (!ctx.cr6.eq) goto loc_82385C60;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82385C60:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385ca8
	if (ctx.cr6.eq) goto loc_82385CA8;
loc_82385C68:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385C98;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82385c68
	if (!ctx.cr6.eq) goto loc_82385C68;
loc_82385CA8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385cc4
	if (ctx.cr6.eq) goto loc_82385CC4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385CC4;
	sub_82246E18(ctx, base);
loc_82385CC4:
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

__attribute__((alias("__imp__sub_82385CDC"))) PPC_WEAK_FUNC(sub_82385CDC);
PPC_FUNC_IMPL(__imp__sub_82385CDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385CE0"))) PPC_WEAK_FUNC(sub_82385CE0);
PPC_FUNC_IMPL(__imp__sub_82385CE0) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6088
	ctx.r31.s64 = ctx.r11.s64 + 6088;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385d68
	if (ctx.cr6.eq) goto loc_82385D68;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82385d20
	if (!ctx.cr6.eq) goto loc_82385D20;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82385D20:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385d68
	if (ctx.cr6.eq) goto loc_82385D68;
loc_82385D28:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385D58;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82385d28
	if (!ctx.cr6.eq) goto loc_82385D28;
loc_82385D68:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385d84
	if (ctx.cr6.eq) goto loc_82385D84;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385D84;
	sub_82246E18(ctx, base);
loc_82385D84:
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

__attribute__((alias("__imp__sub_82385D9C"))) PPC_WEAK_FUNC(sub_82385D9C);
PPC_FUNC_IMPL(__imp__sub_82385D9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385DA0"))) PPC_WEAK_FUNC(sub_82385DA0);
PPC_FUNC_IMPL(__imp__sub_82385DA0) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6144
	ctx.r31.s64 = ctx.r11.s64 + 6144;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385e28
	if (ctx.cr6.eq) goto loc_82385E28;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82385de0
	if (!ctx.cr6.eq) goto loc_82385DE0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82385DE0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385e28
	if (ctx.cr6.eq) goto loc_82385E28;
loc_82385DE8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385E18;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82385de8
	if (!ctx.cr6.eq) goto loc_82385DE8;
loc_82385E28:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385e44
	if (ctx.cr6.eq) goto loc_82385E44;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385E44;
	sub_82246E18(ctx, base);
loc_82385E44:
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

__attribute__((alias("__imp__sub_82385E5C"))) PPC_WEAK_FUNC(sub_82385E5C);
PPC_FUNC_IMPL(__imp__sub_82385E5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385E60"))) PPC_WEAK_FUNC(sub_82385E60);
PPC_FUNC_IMPL(__imp__sub_82385E60) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6200
	ctx.r31.s64 = ctx.r11.s64 + 6200;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385ee8
	if (ctx.cr6.eq) goto loc_82385EE8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82385ea0
	if (!ctx.cr6.eq) goto loc_82385EA0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82385EA0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385ee8
	if (ctx.cr6.eq) goto loc_82385EE8;
loc_82385EA8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385ED8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82385ea8
	if (!ctx.cr6.eq) goto loc_82385EA8;
loc_82385EE8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385f04
	if (ctx.cr6.eq) goto loc_82385F04;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385F04;
	sub_82246E18(ctx, base);
loc_82385F04:
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

__attribute__((alias("__imp__sub_82385F1C"))) PPC_WEAK_FUNC(sub_82385F1C);
PPC_FUNC_IMPL(__imp__sub_82385F1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385F20"))) PPC_WEAK_FUNC(sub_82385F20);
PPC_FUNC_IMPL(__imp__sub_82385F20) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6256
	ctx.r31.s64 = ctx.r11.s64 + 6256;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385fa8
	if (ctx.cr6.eq) goto loc_82385FA8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82385f60
	if (!ctx.cr6.eq) goto loc_82385F60;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82385F60:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82385fa8
	if (ctx.cr6.eq) goto loc_82385FA8;
loc_82385F68:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82385F98;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82385f68
	if (!ctx.cr6.eq) goto loc_82385F68;
loc_82385FA8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82385fc4
	if (ctx.cr6.eq) goto loc_82385FC4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82385FC4;
	sub_82246E18(ctx, base);
loc_82385FC4:
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

__attribute__((alias("__imp__sub_82385FDC"))) PPC_WEAK_FUNC(sub_82385FDC);
PPC_FUNC_IMPL(__imp__sub_82385FDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82385FE0"))) PPC_WEAK_FUNC(sub_82385FE0);
PPC_FUNC_IMPL(__imp__sub_82385FE0) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6312
	ctx.r31.s64 = ctx.r11.s64 + 6312;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386068
	if (ctx.cr6.eq) goto loc_82386068;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386020
	if (!ctx.cr6.eq) goto loc_82386020;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386020:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386068
	if (ctx.cr6.eq) goto loc_82386068;
loc_82386028:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386058;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386028
	if (!ctx.cr6.eq) goto loc_82386028;
loc_82386068:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386084
	if (ctx.cr6.eq) goto loc_82386084;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386084;
	sub_82246E18(ctx, base);
loc_82386084:
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

__attribute__((alias("__imp__sub_8238609C"))) PPC_WEAK_FUNC(sub_8238609C);
PPC_FUNC_IMPL(__imp__sub_8238609C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823860A0"))) PPC_WEAK_FUNC(sub_823860A0);
PPC_FUNC_IMPL(__imp__sub_823860A0) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6368
	ctx.r31.s64 = ctx.r11.s64 + 6368;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386128
	if (ctx.cr6.eq) goto loc_82386128;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823860e0
	if (!ctx.cr6.eq) goto loc_823860E0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823860E0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386128
	if (ctx.cr6.eq) goto loc_82386128;
loc_823860E8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386118;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823860e8
	if (!ctx.cr6.eq) goto loc_823860E8;
loc_82386128:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386144
	if (ctx.cr6.eq) goto loc_82386144;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386144;
	sub_82246E18(ctx, base);
loc_82386144:
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

__attribute__((alias("__imp__sub_8238615C"))) PPC_WEAK_FUNC(sub_8238615C);
PPC_FUNC_IMPL(__imp__sub_8238615C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386160"))) PPC_WEAK_FUNC(sub_82386160);
PPC_FUNC_IMPL(__imp__sub_82386160) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6424
	ctx.r31.s64 = ctx.r11.s64 + 6424;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823861e8
	if (ctx.cr6.eq) goto loc_823861E8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823861a0
	if (!ctx.cr6.eq) goto loc_823861A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823861A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823861e8
	if (ctx.cr6.eq) goto loc_823861E8;
loc_823861A8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823861D8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823861a8
	if (!ctx.cr6.eq) goto loc_823861A8;
loc_823861E8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386204
	if (ctx.cr6.eq) goto loc_82386204;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386204;
	sub_82246E18(ctx, base);
loc_82386204:
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

__attribute__((alias("__imp__sub_8238621C"))) PPC_WEAK_FUNC(sub_8238621C);
PPC_FUNC_IMPL(__imp__sub_8238621C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386220"))) PPC_WEAK_FUNC(sub_82386220);
PPC_FUNC_IMPL(__imp__sub_82386220) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6480
	ctx.r31.s64 = ctx.r11.s64 + 6480;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823862a8
	if (ctx.cr6.eq) goto loc_823862A8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386260
	if (!ctx.cr6.eq) goto loc_82386260;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386260:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823862a8
	if (ctx.cr6.eq) goto loc_823862A8;
loc_82386268:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386298;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386268
	if (!ctx.cr6.eq) goto loc_82386268;
loc_823862A8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823862c4
	if (ctx.cr6.eq) goto loc_823862C4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823862C4;
	sub_82246E18(ctx, base);
loc_823862C4:
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

__attribute__((alias("__imp__sub_823862DC"))) PPC_WEAK_FUNC(sub_823862DC);
PPC_FUNC_IMPL(__imp__sub_823862DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823862E0"))) PPC_WEAK_FUNC(sub_823862E0);
PPC_FUNC_IMPL(__imp__sub_823862E0) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6536
	ctx.r31.s64 = ctx.r11.s64 + 6536;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386368
	if (ctx.cr6.eq) goto loc_82386368;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386320
	if (!ctx.cr6.eq) goto loc_82386320;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386320:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386368
	if (ctx.cr6.eq) goto loc_82386368;
loc_82386328:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386358;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386328
	if (!ctx.cr6.eq) goto loc_82386328;
loc_82386368:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386384
	if (ctx.cr6.eq) goto loc_82386384;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386384;
	sub_82246E18(ctx, base);
loc_82386384:
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

__attribute__((alias("__imp__sub_8238639C"))) PPC_WEAK_FUNC(sub_8238639C);
PPC_FUNC_IMPL(__imp__sub_8238639C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823863A0"))) PPC_WEAK_FUNC(sub_823863A0);
PPC_FUNC_IMPL(__imp__sub_823863A0) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6592
	ctx.r31.s64 = ctx.r11.s64 + 6592;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386428
	if (ctx.cr6.eq) goto loc_82386428;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823863e0
	if (!ctx.cr6.eq) goto loc_823863E0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823863E0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386428
	if (ctx.cr6.eq) goto loc_82386428;
loc_823863E8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386418;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823863e8
	if (!ctx.cr6.eq) goto loc_823863E8;
loc_82386428:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386444
	if (ctx.cr6.eq) goto loc_82386444;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386444;
	sub_82246E18(ctx, base);
loc_82386444:
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

__attribute__((alias("__imp__sub_8238645C"))) PPC_WEAK_FUNC(sub_8238645C);
PPC_FUNC_IMPL(__imp__sub_8238645C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386460"))) PPC_WEAK_FUNC(sub_82386460);
PPC_FUNC_IMPL(__imp__sub_82386460) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6648
	ctx.r31.s64 = ctx.r11.s64 + 6648;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823864e8
	if (ctx.cr6.eq) goto loc_823864E8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823864a0
	if (!ctx.cr6.eq) goto loc_823864A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823864A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823864e8
	if (ctx.cr6.eq) goto loc_823864E8;
loc_823864A8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823864D8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823864a8
	if (!ctx.cr6.eq) goto loc_823864A8;
loc_823864E8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386504
	if (ctx.cr6.eq) goto loc_82386504;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386504;
	sub_82246E18(ctx, base);
loc_82386504:
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

__attribute__((alias("__imp__sub_8238651C"))) PPC_WEAK_FUNC(sub_8238651C);
PPC_FUNC_IMPL(__imp__sub_8238651C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386520"))) PPC_WEAK_FUNC(sub_82386520);
PPC_FUNC_IMPL(__imp__sub_82386520) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r11,r11,6704
	ctx.r11.s64 = ctx.r11.s64 + 6704;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238653C"))) PPC_WEAK_FUNC(sub_8238653C);
PPC_FUNC_IMPL(__imp__sub_8238653C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82386540"))) PPC_WEAK_FUNC(sub_82386540);
PPC_FUNC_IMPL(__imp__sub_82386540) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6724
	ctx.r31.s64 = ctx.r11.s64 + 6724;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823865c8
	if (ctx.cr6.eq) goto loc_823865C8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386580
	if (!ctx.cr6.eq) goto loc_82386580;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386580:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823865c8
	if (ctx.cr6.eq) goto loc_823865C8;
loc_82386588:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823865B8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386588
	if (!ctx.cr6.eq) goto loc_82386588;
loc_823865C8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823865e4
	if (ctx.cr6.eq) goto loc_823865E4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823865E4;
	sub_82246E18(ctx, base);
loc_823865E4:
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

__attribute__((alias("__imp__sub_823865FC"))) PPC_WEAK_FUNC(sub_823865FC);
PPC_FUNC_IMPL(__imp__sub_823865FC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386600"))) PPC_WEAK_FUNC(sub_82386600);
PPC_FUNC_IMPL(__imp__sub_82386600) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6780
	ctx.r31.s64 = ctx.r11.s64 + 6780;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386688
	if (ctx.cr6.eq) goto loc_82386688;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386640
	if (!ctx.cr6.eq) goto loc_82386640;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386640:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386688
	if (ctx.cr6.eq) goto loc_82386688;
loc_82386648:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386678;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386648
	if (!ctx.cr6.eq) goto loc_82386648;
loc_82386688:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823866a4
	if (ctx.cr6.eq) goto loc_823866A4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823866A4;
	sub_82246E18(ctx, base);
loc_823866A4:
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

__attribute__((alias("__imp__sub_823866BC"))) PPC_WEAK_FUNC(sub_823866BC);
PPC_FUNC_IMPL(__imp__sub_823866BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823866C0"))) PPC_WEAK_FUNC(sub_823866C0);
PPC_FUNC_IMPL(__imp__sub_823866C0) {
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
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r31,r11,6836
	ctx.r31.s64 = ctx.r11.s64 + 6836;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386748
	if (ctx.cr6.eq) goto loc_82386748;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386700
	if (!ctx.cr6.eq) goto loc_82386700;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386700:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386748
	if (ctx.cr6.eq) goto loc_82386748;
loc_82386708:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386738;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386708
	if (!ctx.cr6.eq) goto loc_82386708;
loc_82386748:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386764
	if (ctx.cr6.eq) goto loc_82386764;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386764;
	sub_82246E18(ctx, base);
loc_82386764:
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

__attribute__((alias("__imp__sub_8238677C"))) PPC_WEAK_FUNC(sub_8238677C);
PPC_FUNC_IMPL(__imp__sub_8238677C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386780"))) PPC_WEAK_FUNC(sub_82386780);
PPC_FUNC_IMPL(__imp__sub_82386780) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r11,r11,6892
	ctx.r11.s64 = ctx.r11.s64 + 6892;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238679C"))) PPC_WEAK_FUNC(sub_8238679C);
PPC_FUNC_IMPL(__imp__sub_8238679C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823867A0"))) PPC_WEAK_FUNC(sub_823867A0);
PPC_FUNC_IMPL(__imp__sub_823867A0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r11,r11,6912
	ctx.r11.s64 = ctx.r11.s64 + 6912;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823867BC"))) PPC_WEAK_FUNC(sub_823867BC);
PPC_FUNC_IMPL(__imp__sub_823867BC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823867C0"))) PPC_WEAK_FUNC(sub_823867C0);
PPC_FUNC_IMPL(__imp__sub_823867C0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32176
	ctx.r11.s64 = -2108686336;
	// addi r11,r11,6936
	ctx.r11.s64 = ctx.r11.s64 + 6936;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823867DC"))) PPC_WEAK_FUNC(sub_823867DC);
PPC_FUNC_IMPL(__imp__sub_823867DC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823867E0"))) PPC_WEAK_FUNC(sub_823867E0);
PPC_FUNC_IMPL(__imp__sub_823867E0) {
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
	// lis r11,-32173
	ctx.r11.s64 = -2108489728;
	// addi r31,r11,6964
	ctx.r31.s64 = ctx.r11.s64 + 6964;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386868
	if (ctx.cr6.eq) goto loc_82386868;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386820
	if (!ctx.cr6.eq) goto loc_82386820;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386820:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386868
	if (ctx.cr6.eq) goto loc_82386868;
loc_82386828:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386858;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386828
	if (!ctx.cr6.eq) goto loc_82386828;
loc_82386868:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386884
	if (ctx.cr6.eq) goto loc_82386884;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386884;
	sub_82246E18(ctx, base);
loc_82386884:
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

__attribute__((alias("__imp__sub_8238689C"))) PPC_WEAK_FUNC(sub_8238689C);
PPC_FUNC_IMPL(__imp__sub_8238689C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823868A0"))) PPC_WEAK_FUNC(sub_823868A0);
PPC_FUNC_IMPL(__imp__sub_823868A0) {
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
	// lis r11,-32173
	ctx.r11.s64 = -2108489728;
	// addi r31,r11,7020
	ctx.r31.s64 = ctx.r11.s64 + 7020;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386928
	if (ctx.cr6.eq) goto loc_82386928;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823868e0
	if (!ctx.cr6.eq) goto loc_823868E0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823868E0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386928
	if (ctx.cr6.eq) goto loc_82386928;
loc_823868E8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386918;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823868e8
	if (!ctx.cr6.eq) goto loc_823868E8;
loc_82386928:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386944
	if (ctx.cr6.eq) goto loc_82386944;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386944;
	sub_82246E18(ctx, base);
loc_82386944:
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

__attribute__((alias("__imp__sub_8238695C"))) PPC_WEAK_FUNC(sub_8238695C);
PPC_FUNC_IMPL(__imp__sub_8238695C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386960"))) PPC_WEAK_FUNC(sub_82386960);
PPC_FUNC_IMPL(__imp__sub_82386960) {
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
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r31,r11,10776
	ctx.r31.s64 = ctx.r11.s64 + 10776;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823869e8
	if (ctx.cr6.eq) goto loc_823869E8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823869a0
	if (!ctx.cr6.eq) goto loc_823869A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823869A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823869e8
	if (ctx.cr6.eq) goto loc_823869E8;
loc_823869A8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823869D8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823869a8
	if (!ctx.cr6.eq) goto loc_823869A8;
loc_823869E8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386a04
	if (ctx.cr6.eq) goto loc_82386A04;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386A04;
	sub_82246E18(ctx, base);
loc_82386A04:
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

__attribute__((alias("__imp__sub_82386A1C"))) PPC_WEAK_FUNC(sub_82386A1C);
PPC_FUNC_IMPL(__imp__sub_82386A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386A20"))) PPC_WEAK_FUNC(sub_82386A20);
PPC_FUNC_IMPL(__imp__sub_82386A20) {
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
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r31,r11,10832
	ctx.r31.s64 = ctx.r11.s64 + 10832;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386aa8
	if (ctx.cr6.eq) goto loc_82386AA8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386a60
	if (!ctx.cr6.eq) goto loc_82386A60;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386A60:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386aa8
	if (ctx.cr6.eq) goto loc_82386AA8;
loc_82386A68:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386A98;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386a68
	if (!ctx.cr6.eq) goto loc_82386A68;
loc_82386AA8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386ac4
	if (ctx.cr6.eq) goto loc_82386AC4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386AC4;
	sub_82246E18(ctx, base);
loc_82386AC4:
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

__attribute__((alias("__imp__sub_82386ADC"))) PPC_WEAK_FUNC(sub_82386ADC);
PPC_FUNC_IMPL(__imp__sub_82386ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386AE0"))) PPC_WEAK_FUNC(sub_82386AE0);
PPC_FUNC_IMPL(__imp__sub_82386AE0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32173
	ctx.r11.s64 = -2108489728;
	// addi r11,r11,7080
	ctx.r11.s64 = ctx.r11.s64 + 7080;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82386AFC"))) PPC_WEAK_FUNC(sub_82386AFC);
PPC_FUNC_IMPL(__imp__sub_82386AFC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82386B00"))) PPC_WEAK_FUNC(sub_82386B00);
PPC_FUNC_IMPL(__imp__sub_82386B00) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,7108
	ctx.r31.s64 = ctx.r11.s64 + 7108;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386b88
	if (ctx.cr6.eq) goto loc_82386B88;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386b40
	if (!ctx.cr6.eq) goto loc_82386B40;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386B40:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386b88
	if (ctx.cr6.eq) goto loc_82386B88;
loc_82386B48:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386B78;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386b48
	if (!ctx.cr6.eq) goto loc_82386B48;
loc_82386B88:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386ba4
	if (ctx.cr6.eq) goto loc_82386BA4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386BA4;
	sub_82246E18(ctx, base);
loc_82386BA4:
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

__attribute__((alias("__imp__sub_82386BBC"))) PPC_WEAK_FUNC(sub_82386BBC);
PPC_FUNC_IMPL(__imp__sub_82386BBC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386BC0"))) PPC_WEAK_FUNC(sub_82386BC0);
PPC_FUNC_IMPL(__imp__sub_82386BC0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r11,r11,7168
	ctx.r11.s64 = ctx.r11.s64 + 7168;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82386BDC"))) PPC_WEAK_FUNC(sub_82386BDC);
PPC_FUNC_IMPL(__imp__sub_82386BDC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82386BE0"))) PPC_WEAK_FUNC(sub_82386BE0);
PPC_FUNC_IMPL(__imp__sub_82386BE0) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,7452
	ctx.r31.s64 = ctx.r11.s64 + 7452;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386c68
	if (ctx.cr6.eq) goto loc_82386C68;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386c20
	if (!ctx.cr6.eq) goto loc_82386C20;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386C20:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386c68
	if (ctx.cr6.eq) goto loc_82386C68;
loc_82386C28:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386C58;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386c28
	if (!ctx.cr6.eq) goto loc_82386C28;
loc_82386C68:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386c84
	if (ctx.cr6.eq) goto loc_82386C84;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386C84;
	sub_82246E18(ctx, base);
loc_82386C84:
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

__attribute__((alias("__imp__sub_82386C9C"))) PPC_WEAK_FUNC(sub_82386C9C);
PPC_FUNC_IMPL(__imp__sub_82386C9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386CA0"))) PPC_WEAK_FUNC(sub_82386CA0);
PPC_FUNC_IMPL(__imp__sub_82386CA0) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,7508
	ctx.r31.s64 = ctx.r11.s64 + 7508;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386d28
	if (ctx.cr6.eq) goto loc_82386D28;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386ce0
	if (!ctx.cr6.eq) goto loc_82386CE0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386CE0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386d28
	if (ctx.cr6.eq) goto loc_82386D28;
loc_82386CE8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386D18;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386ce8
	if (!ctx.cr6.eq) goto loc_82386CE8;
loc_82386D28:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386d44
	if (ctx.cr6.eq) goto loc_82386D44;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386D44;
	sub_82246E18(ctx, base);
loc_82386D44:
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

__attribute__((alias("__imp__sub_82386D5C"))) PPC_WEAK_FUNC(sub_82386D5C);
PPC_FUNC_IMPL(__imp__sub_82386D5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386D60"))) PPC_WEAK_FUNC(sub_82386D60);
PPC_FUNC_IMPL(__imp__sub_82386D60) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,7564
	ctx.r31.s64 = ctx.r11.s64 + 7564;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386de8
	if (ctx.cr6.eq) goto loc_82386DE8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386da0
	if (!ctx.cr6.eq) goto loc_82386DA0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386DA0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386de8
	if (ctx.cr6.eq) goto loc_82386DE8;
loc_82386DA8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386DD8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386da8
	if (!ctx.cr6.eq) goto loc_82386DA8;
loc_82386DE8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386e04
	if (ctx.cr6.eq) goto loc_82386E04;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386E04;
	sub_82246E18(ctx, base);
loc_82386E04:
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

__attribute__((alias("__imp__sub_82386E1C"))) PPC_WEAK_FUNC(sub_82386E1C);
PPC_FUNC_IMPL(__imp__sub_82386E1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386E20"))) PPC_WEAK_FUNC(sub_82386E20);
PPC_FUNC_IMPL(__imp__sub_82386E20) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,7620
	ctx.r31.s64 = ctx.r11.s64 + 7620;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386ea8
	if (ctx.cr6.eq) goto loc_82386EA8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386e60
	if (!ctx.cr6.eq) goto loc_82386E60;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386E60:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386ea8
	if (ctx.cr6.eq) goto loc_82386EA8;
loc_82386E68:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386E98;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386e68
	if (!ctx.cr6.eq) goto loc_82386E68;
loc_82386EA8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386ec4
	if (ctx.cr6.eq) goto loc_82386EC4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386EC4;
	sub_82246E18(ctx, base);
loc_82386EC4:
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

__attribute__((alias("__imp__sub_82386EDC"))) PPC_WEAK_FUNC(sub_82386EDC);
PPC_FUNC_IMPL(__imp__sub_82386EDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386EE0"))) PPC_WEAK_FUNC(sub_82386EE0);
PPC_FUNC_IMPL(__imp__sub_82386EE0) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,7676
	ctx.r31.s64 = ctx.r11.s64 + 7676;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386f68
	if (ctx.cr6.eq) goto loc_82386F68;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386f20
	if (!ctx.cr6.eq) goto loc_82386F20;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386F20:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82386f68
	if (ctx.cr6.eq) goto loc_82386F68;
loc_82386F28:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82386F58;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386f28
	if (!ctx.cr6.eq) goto loc_82386F28;
loc_82386F68:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82386f84
	if (ctx.cr6.eq) goto loc_82386F84;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82386F84;
	sub_82246E18(ctx, base);
loc_82386F84:
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

__attribute__((alias("__imp__sub_82386F9C"))) PPC_WEAK_FUNC(sub_82386F9C);
PPC_FUNC_IMPL(__imp__sub_82386F9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82386FA0"))) PPC_WEAK_FUNC(sub_82386FA0);
PPC_FUNC_IMPL(__imp__sub_82386FA0) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,7732
	ctx.r31.s64 = ctx.r11.s64 + 7732;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387028
	if (ctx.cr6.eq) goto loc_82387028;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82386fe0
	if (!ctx.cr6.eq) goto loc_82386FE0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82386FE0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387028
	if (ctx.cr6.eq) goto loc_82387028;
loc_82386FE8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387018;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82386fe8
	if (!ctx.cr6.eq) goto loc_82386FE8;
loc_82387028:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387044
	if (ctx.cr6.eq) goto loc_82387044;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387044;
	sub_82246E18(ctx, base);
loc_82387044:
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

__attribute__((alias("__imp__sub_8238705C"))) PPC_WEAK_FUNC(sub_8238705C);
PPC_FUNC_IMPL(__imp__sub_8238705C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387060"))) PPC_WEAK_FUNC(sub_82387060);
PPC_FUNC_IMPL(__imp__sub_82387060) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,7788
	ctx.r31.s64 = ctx.r11.s64 + 7788;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823870e8
	if (ctx.cr6.eq) goto loc_823870E8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823870a0
	if (!ctx.cr6.eq) goto loc_823870A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823870A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823870e8
	if (ctx.cr6.eq) goto loc_823870E8;
loc_823870A8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823870D8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823870a8
	if (!ctx.cr6.eq) goto loc_823870A8;
loc_823870E8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387104
	if (ctx.cr6.eq) goto loc_82387104;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387104;
	sub_82246E18(ctx, base);
loc_82387104:
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

__attribute__((alias("__imp__sub_8238711C"))) PPC_WEAK_FUNC(sub_8238711C);
PPC_FUNC_IMPL(__imp__sub_8238711C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387120"))) PPC_WEAK_FUNC(sub_82387120);
PPC_FUNC_IMPL(__imp__sub_82387120) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,7844
	ctx.r31.s64 = ctx.r11.s64 + 7844;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823871a8
	if (ctx.cr6.eq) goto loc_823871A8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82387160
	if (!ctx.cr6.eq) goto loc_82387160;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82387160:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823871a8
	if (ctx.cr6.eq) goto loc_823871A8;
loc_82387168:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387198;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82387168
	if (!ctx.cr6.eq) goto loc_82387168;
loc_823871A8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823871c4
	if (ctx.cr6.eq) goto loc_823871C4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823871C4;
	sub_82246E18(ctx, base);
loc_823871C4:
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

__attribute__((alias("__imp__sub_823871DC"))) PPC_WEAK_FUNC(sub_823871DC);
PPC_FUNC_IMPL(__imp__sub_823871DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823871E0"))) PPC_WEAK_FUNC(sub_823871E0);
PPC_FUNC_IMPL(__imp__sub_823871E0) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,7900
	ctx.r31.s64 = ctx.r11.s64 + 7900;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387268
	if (ctx.cr6.eq) goto loc_82387268;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82387220
	if (!ctx.cr6.eq) goto loc_82387220;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82387220:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387268
	if (ctx.cr6.eq) goto loc_82387268;
loc_82387228:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387258;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82387228
	if (!ctx.cr6.eq) goto loc_82387228;
loc_82387268:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387284
	if (ctx.cr6.eq) goto loc_82387284;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387284;
	sub_82246E18(ctx, base);
loc_82387284:
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

__attribute__((alias("__imp__sub_8238729C"))) PPC_WEAK_FUNC(sub_8238729C);
PPC_FUNC_IMPL(__imp__sub_8238729C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823872A0"))) PPC_WEAK_FUNC(sub_823872A0);
PPC_FUNC_IMPL(__imp__sub_823872A0) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,7956
	ctx.r31.s64 = ctx.r11.s64 + 7956;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387328
	if (ctx.cr6.eq) goto loc_82387328;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823872e0
	if (!ctx.cr6.eq) goto loc_823872E0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823872E0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387328
	if (ctx.cr6.eq) goto loc_82387328;
loc_823872E8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387318;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823872e8
	if (!ctx.cr6.eq) goto loc_823872E8;
loc_82387328:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387344
	if (ctx.cr6.eq) goto loc_82387344;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387344;
	sub_82246E18(ctx, base);
loc_82387344:
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

__attribute__((alias("__imp__sub_8238735C"))) PPC_WEAK_FUNC(sub_8238735C);
PPC_FUNC_IMPL(__imp__sub_8238735C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387360"))) PPC_WEAK_FUNC(sub_82387360);
PPC_FUNC_IMPL(__imp__sub_82387360) {
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
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r31,r11,10888
	ctx.r31.s64 = ctx.r11.s64 + 10888;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823873e8
	if (ctx.cr6.eq) goto loc_823873E8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823873a0
	if (!ctx.cr6.eq) goto loc_823873A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823873A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823873e8
	if (ctx.cr6.eq) goto loc_823873E8;
loc_823873A8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823873D8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823873a8
	if (!ctx.cr6.eq) goto loc_823873A8;
loc_823873E8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387404
	if (ctx.cr6.eq) goto loc_82387404;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387404;
	sub_82246E18(ctx, base);
loc_82387404:
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

__attribute__((alias("__imp__sub_8238741C"))) PPC_WEAK_FUNC(sub_8238741C);
PPC_FUNC_IMPL(__imp__sub_8238741C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387420"))) PPC_WEAK_FUNC(sub_82387420);
PPC_FUNC_IMPL(__imp__sub_82387420) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r11,r11,10320
	ctx.r11.s64 = ctx.r11.s64 + 10320;
	// lbz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// b 0x82080000
	sub_82080000(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238744C"))) PPC_WEAK_FUNC(sub_8238744C);
PPC_FUNC_IMPL(__imp__sub_8238744C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82387450"))) PPC_WEAK_FUNC(sub_82387450);
PPC_FUNC_IMPL(__imp__sub_82387450) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// li r30,3
	ctx.r30.s64 = 3;
	// addi r11,r11,8032
	ctx.r11.s64 = ctx.r11.s64 + 8032;
	// addi r31,r11,716
	ctx.r31.s64 = ctx.r11.s64 + 716;
loc_82387474:
	// addi r31,r31,-172
	ctx.r31.s64 = ctx.r31.s64 + -172;
	// lbz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8238749c
	if (!ctx.cr6.eq) goto loc_8238749C;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8238749c
	if (ctx.cr6.eq) goto loc_8238749C;
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x8238749C;
	sub_82080000(ctx, base);
loc_8238749C:
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x82387474
	if (!ctx.cr0.lt) goto loc_82387474;
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

__attribute__((alias("__imp__sub_823874BC"))) PPC_WEAK_FUNC(sub_823874BC);
PPC_FUNC_IMPL(__imp__sub_823874BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823874C0"))) PPC_WEAK_FUNC(sub_823874C0);
PPC_FUNC_IMPL(__imp__sub_823874C0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r11,r11,8012
	ctx.r11.s64 = ctx.r11.s64 + 8012;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823874DC"))) PPC_WEAK_FUNC(sub_823874DC);
PPC_FUNC_IMPL(__imp__sub_823874DC) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823874E0"))) PPC_WEAK_FUNC(sub_823874E0);
PPC_FUNC_IMPL(__imp__sub_823874E0) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,8720
	ctx.r31.s64 = ctx.r11.s64 + 8720;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387568
	if (ctx.cr6.eq) goto loc_82387568;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82387520
	if (!ctx.cr6.eq) goto loc_82387520;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82387520:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387568
	if (ctx.cr6.eq) goto loc_82387568;
loc_82387528:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387558;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82387528
	if (!ctx.cr6.eq) goto loc_82387528;
loc_82387568:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387584
	if (ctx.cr6.eq) goto loc_82387584;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387584;
	sub_82246E18(ctx, base);
loc_82387584:
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

__attribute__((alias("__imp__sub_8238759C"))) PPC_WEAK_FUNC(sub_8238759C);
PPC_FUNC_IMPL(__imp__sub_8238759C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823875A0"))) PPC_WEAK_FUNC(sub_823875A0);
PPC_FUNC_IMPL(__imp__sub_823875A0) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,8776
	ctx.r31.s64 = ctx.r11.s64 + 8776;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387628
	if (ctx.cr6.eq) goto loc_82387628;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823875e0
	if (!ctx.cr6.eq) goto loc_823875E0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823875E0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387628
	if (ctx.cr6.eq) goto loc_82387628;
loc_823875E8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387618;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823875e8
	if (!ctx.cr6.eq) goto loc_823875E8;
loc_82387628:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387644
	if (ctx.cr6.eq) goto loc_82387644;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387644;
	sub_82246E18(ctx, base);
loc_82387644:
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

__attribute__((alias("__imp__sub_8238765C"))) PPC_WEAK_FUNC(sub_8238765C);
PPC_FUNC_IMPL(__imp__sub_8238765C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387660"))) PPC_WEAK_FUNC(sub_82387660);
PPC_FUNC_IMPL(__imp__sub_82387660) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,8832
	ctx.r31.s64 = ctx.r11.s64 + 8832;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823876e8
	if (ctx.cr6.eq) goto loc_823876E8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823876a0
	if (!ctx.cr6.eq) goto loc_823876A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823876A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823876e8
	if (ctx.cr6.eq) goto loc_823876E8;
loc_823876A8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823876D8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823876a8
	if (!ctx.cr6.eq) goto loc_823876A8;
loc_823876E8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387704
	if (ctx.cr6.eq) goto loc_82387704;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387704;
	sub_82246E18(ctx, base);
loc_82387704:
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

__attribute__((alias("__imp__sub_8238771C"))) PPC_WEAK_FUNC(sub_8238771C);
PPC_FUNC_IMPL(__imp__sub_8238771C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387720"))) PPC_WEAK_FUNC(sub_82387720);
PPC_FUNC_IMPL(__imp__sub_82387720) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,8888
	ctx.r31.s64 = ctx.r11.s64 + 8888;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823877a8
	if (ctx.cr6.eq) goto loc_823877A8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82387760
	if (!ctx.cr6.eq) goto loc_82387760;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82387760:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823877a8
	if (ctx.cr6.eq) goto loc_823877A8;
loc_82387768:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387798;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82387768
	if (!ctx.cr6.eq) goto loc_82387768;
loc_823877A8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823877c4
	if (ctx.cr6.eq) goto loc_823877C4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823877C4;
	sub_82246E18(ctx, base);
loc_823877C4:
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

__attribute__((alias("__imp__sub_823877DC"))) PPC_WEAK_FUNC(sub_823877DC);
PPC_FUNC_IMPL(__imp__sub_823877DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823877E0"))) PPC_WEAK_FUNC(sub_823877E0);
PPC_FUNC_IMPL(__imp__sub_823877E0) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,8944
	ctx.r31.s64 = ctx.r11.s64 + 8944;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387868
	if (ctx.cr6.eq) goto loc_82387868;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82387820
	if (!ctx.cr6.eq) goto loc_82387820;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82387820:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387868
	if (ctx.cr6.eq) goto loc_82387868;
loc_82387828:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387858;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82387828
	if (!ctx.cr6.eq) goto loc_82387828;
loc_82387868:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387884
	if (ctx.cr6.eq) goto loc_82387884;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387884;
	sub_82246E18(ctx, base);
loc_82387884:
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

__attribute__((alias("__imp__sub_8238789C"))) PPC_WEAK_FUNC(sub_8238789C);
PPC_FUNC_IMPL(__imp__sub_8238789C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823878A0"))) PPC_WEAK_FUNC(sub_823878A0);
PPC_FUNC_IMPL(__imp__sub_823878A0) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,9000
	ctx.r31.s64 = ctx.r11.s64 + 9000;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387928
	if (ctx.cr6.eq) goto loc_82387928;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823878e0
	if (!ctx.cr6.eq) goto loc_823878E0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823878E0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387928
	if (ctx.cr6.eq) goto loc_82387928;
loc_823878E8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387918;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823878e8
	if (!ctx.cr6.eq) goto loc_823878E8;
loc_82387928:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387944
	if (ctx.cr6.eq) goto loc_82387944;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387944;
	sub_82246E18(ctx, base);
loc_82387944:
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

__attribute__((alias("__imp__sub_8238795C"))) PPC_WEAK_FUNC(sub_8238795C);
PPC_FUNC_IMPL(__imp__sub_8238795C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387960"))) PPC_WEAK_FUNC(sub_82387960);
PPC_FUNC_IMPL(__imp__sub_82387960) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,9056
	ctx.r31.s64 = ctx.r11.s64 + 9056;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823879e8
	if (ctx.cr6.eq) goto loc_823879E8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823879a0
	if (!ctx.cr6.eq) goto loc_823879A0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823879A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823879e8
	if (ctx.cr6.eq) goto loc_823879E8;
loc_823879A8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823879D8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823879a8
	if (!ctx.cr6.eq) goto loc_823879A8;
loc_823879E8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387a04
	if (ctx.cr6.eq) goto loc_82387A04;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387A04;
	sub_82246E18(ctx, base);
loc_82387A04:
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

__attribute__((alias("__imp__sub_82387A1C"))) PPC_WEAK_FUNC(sub_82387A1C);
PPC_FUNC_IMPL(__imp__sub_82387A1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387A20"))) PPC_WEAK_FUNC(sub_82387A20);
PPC_FUNC_IMPL(__imp__sub_82387A20) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,9112
	ctx.r31.s64 = ctx.r11.s64 + 9112;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387aa8
	if (ctx.cr6.eq) goto loc_82387AA8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82387a60
	if (!ctx.cr6.eq) goto loc_82387A60;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82387A60:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387aa8
	if (ctx.cr6.eq) goto loc_82387AA8;
loc_82387A68:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387A98;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82387a68
	if (!ctx.cr6.eq) goto loc_82387A68;
loc_82387AA8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387ac4
	if (ctx.cr6.eq) goto loc_82387AC4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387AC4;
	sub_82246E18(ctx, base);
loc_82387AC4:
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

__attribute__((alias("__imp__sub_82387ADC"))) PPC_WEAK_FUNC(sub_82387ADC);
PPC_FUNC_IMPL(__imp__sub_82387ADC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387AE0"))) PPC_WEAK_FUNC(sub_82387AE0);
PPC_FUNC_IMPL(__imp__sub_82387AE0) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,9168
	ctx.r31.s64 = ctx.r11.s64 + 9168;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387b68
	if (ctx.cr6.eq) goto loc_82387B68;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82387b20
	if (!ctx.cr6.eq) goto loc_82387B20;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82387B20:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387b68
	if (ctx.cr6.eq) goto loc_82387B68;
loc_82387B28:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387B58;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82387b28
	if (!ctx.cr6.eq) goto loc_82387B28;
loc_82387B68:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387b84
	if (ctx.cr6.eq) goto loc_82387B84;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387B84;
	sub_82246E18(ctx, base);
loc_82387B84:
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

__attribute__((alias("__imp__sub_82387B9C"))) PPC_WEAK_FUNC(sub_82387B9C);
PPC_FUNC_IMPL(__imp__sub_82387B9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387BA0"))) PPC_WEAK_FUNC(sub_82387BA0);
PPC_FUNC_IMPL(__imp__sub_82387BA0) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,9224
	ctx.r31.s64 = ctx.r11.s64 + 9224;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387c28
	if (ctx.cr6.eq) goto loc_82387C28;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82387be0
	if (!ctx.cr6.eq) goto loc_82387BE0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82387BE0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387c28
	if (ctx.cr6.eq) goto loc_82387C28;
loc_82387BE8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387C18;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82387be8
	if (!ctx.cr6.eq) goto loc_82387BE8;
loc_82387C28:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387c44
	if (ctx.cr6.eq) goto loc_82387C44;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387C44;
	sub_82246E18(ctx, base);
loc_82387C44:
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

__attribute__((alias("__imp__sub_82387C5C"))) PPC_WEAK_FUNC(sub_82387C5C);
PPC_FUNC_IMPL(__imp__sub_82387C5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387C60"))) PPC_WEAK_FUNC(sub_82387C60);
PPC_FUNC_IMPL(__imp__sub_82387C60) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,9280
	ctx.r31.s64 = ctx.r11.s64 + 9280;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387ce8
	if (ctx.cr6.eq) goto loc_82387CE8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82387ca0
	if (!ctx.cr6.eq) goto loc_82387CA0;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82387CA0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387ce8
	if (ctx.cr6.eq) goto loc_82387CE8;
loc_82387CA8:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387CD8;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82387ca8
	if (!ctx.cr6.eq) goto loc_82387CA8;
loc_82387CE8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387d04
	if (ctx.cr6.eq) goto loc_82387D04;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387D04;
	sub_82246E18(ctx, base);
loc_82387D04:
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

__attribute__((alias("__imp__sub_82387D1C"))) PPC_WEAK_FUNC(sub_82387D1C);
PPC_FUNC_IMPL(__imp__sub_82387D1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387D20"))) PPC_WEAK_FUNC(sub_82387D20);
PPC_FUNC_IMPL(__imp__sub_82387D20) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,9336
	ctx.r31.s64 = ctx.r11.s64 + 9336;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387da8
	if (ctx.cr6.eq) goto loc_82387DA8;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82387d60
	if (!ctx.cr6.eq) goto loc_82387D60;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82387D60:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387da8
	if (ctx.cr6.eq) goto loc_82387DA8;
loc_82387D68:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387D98;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82387d68
	if (!ctx.cr6.eq) goto loc_82387D68;
loc_82387DA8:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387dc4
	if (ctx.cr6.eq) goto loc_82387DC4;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387DC4;
	sub_82246E18(ctx, base);
loc_82387DC4:
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

__attribute__((alias("__imp__sub_82387DDC"))) PPC_WEAK_FUNC(sub_82387DDC);
PPC_FUNC_IMPL(__imp__sub_82387DDC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387DE0"))) PPC_WEAK_FUNC(sub_82387DE0);
PPC_FUNC_IMPL(__imp__sub_82387DE0) {
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
	// lis r11,-32172
	ctx.r11.s64 = -2108424192;
	// addi r31,r11,9392
	ctx.r31.s64 = ctx.r11.s64 + 9392;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387e68
	if (ctx.cr6.eq) goto loc_82387E68;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82387e20
	if (!ctx.cr6.eq) goto loc_82387E20;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82387E20:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387e68
	if (ctx.cr6.eq) goto loc_82387E68;
loc_82387E28:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387E58;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82387e28
	if (!ctx.cr6.eq) goto loc_82387E28;
loc_82387E68:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387e84
	if (ctx.cr6.eq) goto loc_82387E84;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387E84;
	sub_82246E18(ctx, base);
loc_82387E84:
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

__attribute__((alias("__imp__sub_82387E9C"))) PPC_WEAK_FUNC(sub_82387E9C);
PPC_FUNC_IMPL(__imp__sub_82387E9C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387EA0"))) PPC_WEAK_FUNC(sub_82387EA0);
PPC_FUNC_IMPL(__imp__sub_82387EA0) {
	PPC_FUNC_PROLOGUE();
	// lis r10,-32172
	ctx.r10.s64 = -2108424192;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,9448
	ctx.r10.s64 = ctx.r10.s64 + 9448;
	// ori r11,r11,44308
	ctx.r11.u64 = ctx.r11.u64 | 44308;
	// lwzx r9,r10,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwzx r3,r10,r11
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82387EC4"))) PPC_WEAK_FUNC(sub_82387EC4);
PPC_FUNC_IMPL(__imp__sub_82387EC4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82387EC8"))) PPC_WEAK_FUNC(sub_82387EC8);
PPC_FUNC_IMPL(__imp__sub_82387EC8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r11,r11,-11768
	ctx.r11.s64 = ctx.r11.s64 + -11768;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82387EE4"))) PPC_WEAK_FUNC(sub_82387EE4);
PPC_FUNC_IMPL(__imp__sub_82387EE4) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82387EE8"))) PPC_WEAK_FUNC(sub_82387EE8);
PPC_FUNC_IMPL(__imp__sub_82387EE8) {
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
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r31,r11,4644
	ctx.r31.s64 = ctx.r11.s64 + 4644;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387f70
	if (ctx.cr6.eq) goto loc_82387F70;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82387f28
	if (!ctx.cr6.eq) goto loc_82387F28;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82387F28:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82387f70
	if (ctx.cr6.eq) goto loc_82387F70;
loc_82387F30:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82387F60;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82387f30
	if (!ctx.cr6.eq) goto loc_82387F30;
loc_82387F70:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82387f8c
	if (ctx.cr6.eq) goto loc_82387F8C;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x82387F8C;
	sub_82246E18(ctx, base);
loc_82387F8C:
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

__attribute__((alias("__imp__sub_82387FA4"))) PPC_WEAK_FUNC(sub_82387FA4);
PPC_FUNC_IMPL(__imp__sub_82387FA4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82387FA8"))) PPC_WEAK_FUNC(sub_82387FA8);
PPC_FUNC_IMPL(__imp__sub_82387FA8) {
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
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r31,r11,4700
	ctx.r31.s64 = ctx.r11.s64 + 4700;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82388030
	if (ctx.cr6.eq) goto loc_82388030;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82387fe8
	if (!ctx.cr6.eq) goto loc_82387FE8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82387FE8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82388030
	if (ctx.cr6.eq) goto loc_82388030;
loc_82387FF0:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82388020;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82387ff0
	if (!ctx.cr6.eq) goto loc_82387FF0;
loc_82388030:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8238804c
	if (ctx.cr6.eq) goto loc_8238804C;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x8238804C;
	sub_82246E18(ctx, base);
loc_8238804C:
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

__attribute__((alias("__imp__sub_82388064"))) PPC_WEAK_FUNC(sub_82388064);
PPC_FUNC_IMPL(__imp__sub_82388064) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82388068"))) PPC_WEAK_FUNC(sub_82388068);
PPC_FUNC_IMPL(__imp__sub_82388068) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r11,r11,4760
	ctx.r11.s64 = ctx.r11.s64 + 4760;
	// lwz r10,8(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r3,8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x82246e18
	sub_82246E18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82388084"))) PPC_WEAK_FUNC(sub_82388084);
PPC_FUNC_IMPL(__imp__sub_82388084) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82388088"))) PPC_WEAK_FUNC(sub_82388088);
PPC_FUNC_IMPL(__imp__sub_82388088) {
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
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r31,r11,5044
	ctx.r31.s64 = ctx.r11.s64 + 5044;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82388110
	if (ctx.cr6.eq) goto loc_82388110;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823880c8
	if (!ctx.cr6.eq) goto loc_823880C8;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_823880C8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82388110
	if (ctx.cr6.eq) goto loc_82388110;
loc_823880D0:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82388100;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x823880d0
	if (!ctx.cr6.eq) goto loc_823880D0;
loc_82388110:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8238812c
	if (ctx.cr6.eq) goto loc_8238812C;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x8238812C;
	sub_82246E18(ctx, base);
loc_8238812C:
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

__attribute__((alias("__imp__sub_82388144"))) PPC_WEAK_FUNC(sub_82388144);
PPC_FUNC_IMPL(__imp__sub_82388144) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82388148"))) PPC_WEAK_FUNC(sub_82388148);
PPC_FUNC_IMPL(__imp__sub_82388148) {
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
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r31,r11,5100
	ctx.r31.s64 = ctx.r11.s64 + 5100;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823881d0
	if (ctx.cr6.eq) goto loc_823881D0;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82388188
	if (!ctx.cr6.eq) goto loc_82388188;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82388188:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823881d0
	if (ctx.cr6.eq) goto loc_823881D0;
loc_82388190:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x823881C0;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82388190
	if (!ctx.cr6.eq) goto loc_82388190;
loc_823881D0:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823881ec
	if (ctx.cr6.eq) goto loc_823881EC;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823881EC;
	sub_82246E18(ctx, base);
loc_823881EC:
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

__attribute__((alias("__imp__sub_82388204"))) PPC_WEAK_FUNC(sub_82388204);
PPC_FUNC_IMPL(__imp__sub_82388204) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82388208"))) PPC_WEAK_FUNC(sub_82388208);
PPC_FUNC_IMPL(__imp__sub_82388208) {
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
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r31,r11,5156
	ctx.r31.s64 = ctx.r11.s64 + 5156;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82388290
	if (ctx.cr6.eq) goto loc_82388290;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82388248
	if (!ctx.cr6.eq) goto loc_82388248;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82388248:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82388290
	if (ctx.cr6.eq) goto loc_82388290;
loc_82388250:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82388280;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82388250
	if (!ctx.cr6.eq) goto loc_82388250;
loc_82388290:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823882ac
	if (ctx.cr6.eq) goto loc_823882AC;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823882AC;
	sub_82246E18(ctx, base);
loc_823882AC:
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

__attribute__((alias("__imp__sub_823882C4"))) PPC_WEAK_FUNC(sub_823882C4);
PPC_FUNC_IMPL(__imp__sub_823882C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823882C8"))) PPC_WEAK_FUNC(sub_823882C8);
PPC_FUNC_IMPL(__imp__sub_823882C8) {
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
	// lis r11,-32171
	ctx.r11.s64 = -2108358656;
	// addi r31,r11,5212
	ctx.r31.s64 = ctx.r11.s64 + 5212;
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82388350
	if (ctx.cr6.eq) goto loc_82388350;
	// lbz r10,44(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 44);
	// rlwinm r10,r10,0,0,24
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82388308
	if (!ctx.cr6.eq) goto loc_82388308;
	// lwz r11,0(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
loc_82388308:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82388350
	if (ctx.cr6.eq) goto loc_82388350;
loc_82388310:
	// lwz r8,12(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// addi r4,r11,-16
	ctx.r4.s64 = ctx.r11.s64 + -16;
	// lwz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,48(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 48);
	// subf r10,r8,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r8.s64;
	// stw r10,52(r31)
	PPC_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// lwz r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 8);
	// subf r10,r7,r9
	ctx.r10.s64 = ctx.r9.s64 - ctx.r7.s64;
	// stw r10,48(r31)
	PPC_STORE_U32(ctx.r31.u32 + 48, ctx.r10.u32);
	// lwz r30,0(r11)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r3,-8(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -8);
	// bl 0x82080000
	ctx.lr = 0x82388340;
	sub_82080000(ctx, base);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// stw r30,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82388310
	if (!ctx.cr6.eq) goto loc_82388310;
loc_82388350:
	// lwz r10,32(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8238836c
	if (ctx.cr6.eq) goto loc_8238836C;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x8238836C;
	sub_82246E18(ctx, base);
loc_8238836C:
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

__attribute__((alias("__imp__sub_82388384"))) PPC_WEAK_FUNC(sub_82388384);
PPC_FUNC_IMPL(__imp__sub_82388384) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82388388"))) PPC_WEAK_FUNC(sub_82388388);
PPC_FUNC_IMPL(__imp__sub_82388388) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32197
	ctx.r11.s64 = -2110062592;
	// addi r31,r11,-25920
	ctx.r31.s64 = ctx.r11.s64 + -25920;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82309dd0
	ctx.lr = 0x823883A8;
	sub_82309DD0(ctx, base);
	// lwz r11,32(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823883bc
	if (ctx.cr6.eq) goto loc_823883BC;
	// lwz r3,32(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 32);
	// bl 0x82246e18
	ctx.lr = 0x823883BC;
	sub_82246E18(ctx, base);
loc_823883BC:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823883D0"))) PPC_WEAK_FUNC(sub_823883D0);
PPC_FUNC_IMPL(__imp__sub_823883D0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32253
	ctx.r11.s64 = -2113732608;
	// lis r10,-32198
	ctx.r10.s64 = -2110128128;
	// addi r11,r11,-9272
	ctx.r11.s64 = ctx.r11.s64 + -9272;
	// stw r11,-22604(r10)
	PPC_STORE_U32(ctx.r10.u32 + -22604, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823883E4"))) PPC_WEAK_FUNC(sub_823883E4);
PPC_FUNC_IMPL(__imp__sub_823883E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823883E8"))) PPC_WEAK_FUNC(sub_823883E8);
PPC_FUNC_IMPL(__imp__sub_823883E8) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32183
	ctx.r11.s64 = -2109145088;
	// addi r3,r11,23908
	ctx.r3.s64 = ctx.r11.s64 + 23908;
	// b 0x8236f620
	sub_8236F620(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82389400"))) PPC_WEAK_FUNC(sub_82389400);
PPC_FUNC_IMPL(__imp__sub_82389400) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e454
	ctx.lr = 0x82389408;
	__restfpr_23(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// addi r27,r3,5288
	ctx.r27.s64 = ctx.r3.s64 + 5288;
	// ori r25,r10,65535
	ctx.r25.u64 = ctx.r10.u64 | 65535;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x82389440;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,5288(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5288);
	// lwz r9,5296(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5296);
	// rlwinm r11,r8,0,0,29
	ctx.r11.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFC;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// add r30,r9,r10
	ctx.r30.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// lwzu r7,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// addi r28,r11,4
	ctx.r28.s64 = ctx.r11.s64 + 4;
	// slw r11,r6,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r10.u8 & 0x3F));
	// blt cr6,0x82389484
	if (ctx.cr6.lt) goto loc_82389484;
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// slw r8,r7,r30
	ctx.r8.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// b 0x82389488
	goto loc_82389488;
loc_82389484:
	// slw r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r9.u8 & 0x3F));
loc_82389488:
	// lis r24,-32171
	ctx.r24.s64 = -2108358656;
	// lis r23,-32171
	ctx.r23.s64 = -2108358656;
loc_82389490:
	// rlwinm r11,r8,23,9,31
	ctx.r11.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 23) & 0x7FFFFF;
	// cmpwi cr6,r30,9
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 9, ctx.xer);
	// ble cr6,0x823894a8
	if (!ctx.cr6.gt) goto loc_823894A8;
	// subfic r10,r30,41
	ctx.xer.ca = ctx.r30.u32 <= 41;
	ctx.r10.s64 = 41 - ctx.r30.s64;
	// srw r9,r7,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r10.u8 & 0x3F));
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
loc_823894A8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8238976c
	if (ctx.cr6.eq) goto loc_8238976C;
	// lwz r6,5204(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5204);
loc_823894B4:
	// rlwinm r11,r8,12,20,31
	ctx.r11.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 12) & 0xFFF;
	// cmpwi cr6,r30,20
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 20, ctx.xer);
	// ble cr6,0x823894cc
	if (!ctx.cr6.gt) goto loc_823894CC;
	// subfic r10,r30,52
	ctx.xer.ca = ctx.r30.u32 <= 52;
	ctx.r10.s64 = 52 - ctx.r30.s64;
	// srw r9,r7,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r10.u8 & 0x3F));
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
loc_823894CC:
	// rlwinm r10,r11,0,0,23
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF00;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x823894e4
	if (!ctx.cr6.eq) goto loc_823894E4;
	// lwz r10,11360(r23)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r23.u32 + 11360);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// b 0x823894ec
	goto loc_823894EC;
loc_823894E4:
	// lwz r10,11328(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 11328);
	// rlwinm r9,r11,27,5,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFE;
loc_823894EC:
	// lhzx r5,r9,r10
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// extsh r10,r5
	ctx.r10.s64 = ctx.r5.s16;
	// clrlwi r11,r10,28
	ctx.r11.u64 = ctx.r10.u32 & 0xF;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// blt cr6,0x82389518
	if (ctx.cr6.lt) goto loc_82389518;
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// slw r8,r7,r30
	ctx.r8.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// b 0x8238951c
	goto loc_8238951C;
loc_82389518:
	// slw r8,r8,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r11.u8 & 0x3F));
loc_8238951C:
	// rlwinm r11,r10,28,26,31
	ctx.r11.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x3F;
	// cmpwi cr6,r11,34
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 34, ctx.xer);
	// beq cr6,0x823894b4
	if (ctx.cr6.eq) goto loc_823894B4;
	// cmpwi cr6,r11,35
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 35, ctx.xer);
	// bne cr6,0x82389540
	if (!ctx.cr6.eq) goto loc_82389540;
	// lwz r11,5204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5204);
	// addi r11,r11,33
	ctx.r11.s64 = ctx.r11.s64 + 33;
	// stw r11,5204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5204, ctx.r11.u32);
	// b 0x823894b4
	goto loc_823894B4;
loc_82389540:
	// cmpwi cr6,r11,36
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 36, ctx.xer);
	// beq cr6,0x8238976c
	if (ctx.cr6.eq) goto loc_8238976C;
	// lwz r9,5204(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5204);
	// rlwinm r10,r10,22,10,31
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x3FFFFF;
	// lwz r5,5216(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5216);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r10,5220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5220, ctx.r10.u32);
	// stw r11,5204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5204, ctx.r11.u32);
	// cmpw cr6,r11,r5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r5.s32, ctx.xer);
	// bgt cr6,0x8238976c
	if (ctx.cr6.gt) goto loc_8238976C;
	// subf r9,r6,r11
	ctx.r9.s64 = ctx.r11.s64 - ctx.r6.s64;
	// lwz r11,5212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// lwz r10,4836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4836);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r11,5212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5212, ctx.r11.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x823895ac
	if (ctx.cr6.lt) goto loc_823895AC;
loc_82389584:
	// lwz r6,5212(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// lwz r11,5208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5208);
	// subf r5,r10,r6
	ctx.r5.s64 = ctx.r6.s64 - ctx.r10.s64;
	// addi r4,r11,1
	ctx.r4.s64 = ctx.r11.s64 + 1;
	// rotlwi r3,r5,0
	ctx.r3.u64 = rotl32(ctx.r5.u32, 0);
	// stw r5,5212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5212, ctx.r5.u32);
	// stw r4,5208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5208, ctx.r4.u32);
	// lwz r11,4836(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4836);
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x82389584
	if (!ctx.cr6.lt) goto loc_82389584;
loc_823895AC:
	// cmpwi cr6,r9,-2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, -2, ctx.xer);
	// beq cr6,0x8238976c
	if (ctx.cr6.eq) goto loc_8238976C;
	// lwz r11,5220(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5220);
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82389618
	if (ctx.cr6.eq) goto loc_82389618;
	// cmpwi cr6,r30,27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 27, ctx.xer);
	// blt cr6,0x82389608
	if (ctx.cr6.lt) goto loc_82389608;
	// addic. r30,r30,-27
	ctx.xer.ca = ctx.r30.u32 > 26;
	ctx.r30.s64 = ctx.r30.s64 + -27;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x823895f4
	if (ctx.cr0.eq) goto loc_823895F4;
	// subfic r11,r30,5
	ctx.xer.ca = ctx.r30.u32 <= 5;
	ctx.r11.s64 = 5 - ctx.r30.s64;
	// srw r10,r7,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r7.u32 >> (ctx.r11.u8 & 0x3F));
	// or r9,r10,r8
	ctx.r9.u64 = ctx.r10.u64 | ctx.r8.u64;
	// slw r8,r7,r30
	ctx.r8.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// rlwinm r11,r9,5,27,31
	ctx.r11.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0x1F;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// b 0x82389614
	goto loc_82389614;
loc_823895F4:
	// rlwinm r11,r8,5,27,31
	ctx.r11.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0x1F;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// b 0x82389614
	goto loc_82389614;
loc_82389608:
	// rlwinm r11,r8,5,27,31
	ctx.r11.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0x1F;
	// addi r30,r30,5
	ctx.r30.s64 = ctx.r30.s64 + 5;
	// rlwinm r8,r8,5,0,26
	ctx.r8.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0xFFFFFFE0;
loc_82389614:
	// stw r11,5128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5128, ctx.r11.u32);
loc_82389618:
	// stw r8,4352(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4352, ctx.r8.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r7,4356(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4356, ctx.r7.u32);
	// stw r30,4360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4360, ctx.r30.u32);
	// stw r28,4364(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4364, ctx.r28.u32);
	// lwz r11,5092(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5092);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82389638;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,5100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5100);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82389648;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,5412(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5412);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x8238976c
	if (!ctx.cr6.eq) goto loc_8238976C;
	// lwz r11,5316(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5316);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,5316(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5316, ctx.r11.u32);
	// bgt 0x8238967c
	if (ctx.cr0.gt) goto loc_8238967C;
	// lwz r11,4816(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4816);
	// lwz r10,4820(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4820);
	// lwz r3,4824(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4824);
	// stw r11,5316(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5316, ctx.r11.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8238967C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8238967C:
	// lwz r30,4360(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4360);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// clrlwi r29,r30,29
	ctx.r29.u64 = ctx.r30.u32 & 0x7;
	// lwz r28,4364(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4364);
	// lwz r9,5292(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5292);
	// subf r11,r29,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r29.s64;
	// lwz r8,4352(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4352);
	// lwz r7,4356(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4356);
	// addi r6,r11,7
	ctx.r6.s64 = ctx.r11.s64 + 7;
	// srawi r5,r6,3
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 3;
	// subf r11,r10,r5
	ctx.r11.s64 = ctx.r5.s64 - ctx.r10.s64;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r4,r11,-8
	ctx.r4.s64 = ctx.r11.s64 + -8;
	// subf r3,r4,r9
	ctx.r3.s64 = ctx.r9.s64 - ctx.r4.s64;
	// cmpwi cr6,r3,2048
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2048, ctx.xer);
	// bgt cr6,0x82389490
	if (ctx.cr6.gt) goto loc_82389490;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8232b788
	ctx.lr = 0x823896CC;
	sub_8232B788(ctx, base);
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823896E8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82389704;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r26)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r11,24(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82389724;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// rlwinm r11,r10,0,0,29
	ctx.r11.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// lwzu r7,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// add r30,r29,r10
	ctx.r30.u64 = ctx.r29.u64 + ctx.r10.u64;
	// addi r28,r11,4
	ctx.r28.s64 = ctx.r11.s64 + 4;
	// slw r11,r8,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// blt cr6,0x82389764
	if (ctx.cr6.lt) goto loc_82389764;
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// slw r8,r7,r30
	ctx.r8.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r7,0(r28)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// b 0x82389490
	goto loc_82389490;
loc_82389764:
	// slw r8,r11,r29
	ctx.r8.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r29.u8 & 0x3F));
	// b 0x82389490
	goto loc_82389490;
loc_8238976C:
	// addi r11,r30,7
	ctx.r11.s64 = ctx.r30.s64 + 7;
	// lwz r10,0(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// srawi r9,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 3;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// subf r11,r10,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r10.s64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r4,r11,-8
	ctx.r4.s64 = ctx.r11.s64 + -8;
	// bl 0x8232b788
	ctx.lr = 0x82389794;
	sub_8232B788(ctx, base);
	// lwz r8,0(r26)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r7,32(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x823897B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,0(r26)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r11,28(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823897CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82325cf8
	ctx.lr = 0x823897D4;
	sub_82325CF8(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8233e4a4
	__restgprlr_23(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_823897DC"))) PPC_WEAK_FUNC(sub_823897DC);
PPC_FUNC_IMPL(__imp__sub_823897DC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823897E0"))) PPC_WEAK_FUNC(sub_823897E0);
PPC_FUNC_IMPL(__imp__sub_823897E0) {
	PPC_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,16(r3)
	PPC_STORE_U32(ctx.r3.u32 + 16, ctx.r11.u32);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r11,24(r3)
	PPC_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r11,28(r3)
	PPC_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_823897F8"))) PPC_WEAK_FUNC(sub_823897F8);
PPC_FUNC_IMPL(__imp__sub_823897F8) {
	PPC_FUNC_PROLOGUE();
	// li r11,1024
	ctx.r11.s64 = 1024;
	// stw r11,5232(r3)
	PPC_STORE_U32(ctx.r3.u32 + 5232, ctx.r11.u32);
	// stw r11,5236(r3)
	PPC_STORE_U32(ctx.r3.u32 + 5236, ctx.r11.u32);
	// stw r11,5228(r3)
	PPC_STORE_U32(ctx.r3.u32 + 5228, ctx.r11.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8238980C"))) PPC_WEAK_FUNC(sub_8238980C);
PPC_FUNC_IMPL(__imp__sub_8238980C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_82389810"))) PPC_WEAK_FUNC(sub_82389810);
PPC_FUNC_IMPL(__imp__sub_82389810) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e460
	ctx.lr = 0x82389818;
	__restfpr_26(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lwz r10,4352(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4352);
	// lwz r31,4(r4)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r27,8(r4)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// rlwinm r9,r10,11,21,31
	ctx.r9.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 11) & 0x7FF;
	// lwz r11,4360(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4360);
	// lwz r30,4356(r7)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4356);
	// lwz r28,4364(r7)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4364);
	// cmpwi cr6,r11,21
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 21, ctx.xer);
	// ble cr6,0x82389850
	if (!ctx.cr6.gt) goto loc_82389850;
	// subfic r8,r11,53
	ctx.xer.ca = ctx.r11.u32 <= 53;
	ctx.r8.s64 = 53 - ctx.r11.s64;
	// srw r8,r30,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r8.u8 & 0x3F));
	// or r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 | ctx.r9.u64;
loc_82389850:
	// rlwinm r8,r9,0,0,24
	ctx.r8.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x8238986c
	if (!ctx.cr6.eq) goto loc_8238986C;
	// lis r8,-32171
	ctx.r8.s64 = -2108358656;
	// rlwinm r29,r9,1,0,30
	ctx.r29.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,11364(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11364);
	// b 0x82389878
	goto loc_82389878;
loc_8238986C:
	// lis r8,-32171
	ctx.r8.s64 = -2108358656;
	// rlwinm r29,r9,27,5,30
	ctx.r29.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x7FFFFFE;
	// lwz r9,11308(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 11308);
loc_82389878:
	// lhzx r9,r29,r9
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r29.u32 + ctx.r9.u32);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// extsb r29,r9
	ctx.r29.s64 = ctx.r9.s8;
	// cmpwi cr6,r29,127
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 127, ctx.xer);
	// bne cr6,0x823898a4
	if (!ctx.cr6.eq) goto loc_823898A4;
	// li r3,-1
	ctx.r3.s64 = -1;
	// stw r10,4352(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4352, ctx.r10.u32);
	// stw r30,4356(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4356, ctx.r30.u32);
	// stw r11,4360(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4360, ctx.r11.u32);
	// stw r28,4364(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4364, ctx.r28.u32);
	// b 0x8233e4b0
	__restgprlr_26(ctx, base);
	return;
loc_823898A4:
	// rlwinm r9,r9,24,24,31
	ctx.r9.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFF;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// cmpwi cr6,r11,32
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 32, ctx.xer);
	// blt cr6,0x823898c8
	if (ctx.cr6.lt) goto loc_823898C8;
	// addi r11,r11,-32
	ctx.r11.s64 = ctx.r11.s64 + -32;
	// slw r10,r30,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r11.u8 & 0x3F));
	// lwz r30,0(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// b 0x823898cc
	goto loc_823898CC;
loc_823898C8:
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
loc_823898CC:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x823898e0
	if (!ctx.cr6.eq) goto loc_823898E0;
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// b 0x82389970
	goto loc_82389970;
loc_823898E0:
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq cr6,0x82389958
	if (ctx.cr6.eq) goto loc_82389958;
	// subfic r9,r31,32
	ctx.xer.ca = ctx.r31.u32 <= 32;
	ctx.r9.s64 = 32 - ctx.r31.s64;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// blt cr6,0x82389934
	if (ctx.cr6.lt) goto loc_82389934;
	// addic. r11,r11,-32
	ctx.xer.ca = ctx.r11.u32 > 31;
	ctx.r11.s64 = ctx.r11.s64 + -32;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82389920
	if (ctx.cr0.eq) goto loc_82389920;
	// subf r8,r11,r31
	ctx.r8.s64 = ctx.r31.s64 - ctx.r11.s64;
	// srw r8,r30,r8
	ctx.r8.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r30.u32 >> (ctx.r8.u8 & 0x3F));
	// or r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 | ctx.r10.u64;
	// slw r10,r30,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r30.u32 << (ctx.r11.u8 & 0x3F));
	// lwz r30,0(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// srw r8,r8,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r9.u8 & 0x3F));
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// b 0x8238993c
	goto loc_8238993C;
loc_82389920:
	// srw r8,r10,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// lwz r30,0(r28)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// b 0x8238993c
	goto loc_8238993C;
loc_82389934:
	// srw r8,r10,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 >> (ctx.r9.u8 & 0x3F));
	// slw r10,r10,r31
	ctx.r10.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r31.u8 & 0x3F));
loc_8238993C:
	// lwz r26,12(r4)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// slw. r9,r29,r31
	ctx.r9.u64 = ctx.r31.u8 & 0x20 ? 0 : (ctx.r29.u32 << (ctx.r31.u8 & 0x3F));
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// subf r8,r8,r26
	ctx.r8.s64 = ctx.r26.s64 - ctx.r8.s64;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// subf r29,r8,r9
	ctx.r29.s64 = ctx.r9.s64 - ctx.r8.s64;
	// bgt 0x82389958
	if (ctx.cr0.gt) goto loc_82389958;
	// add r29,r8,r9
	ctx.r29.u64 = ctx.r8.u64 + ctx.r9.u64;
loc_82389958:
	// lwz r9,0(r6)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + ctx.r29.u64;
	// slw r8,r9,r27
	ctx.r8.u64 = ctx.r27.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r27.u8 & 0x3F));
	// sraw r9,r8,r27
	temp.u32 = ctx.r27.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r8.s32 < 0) & (((ctx.r8.s32 >> temp.u32) << temp.u32) != ctx.r8.s32);
	ctx.r9.s64 = ctx.r8.s32 >> temp.u32;
	// stw r9,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// stw r9,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r9.u32);
loc_82389970:
	// lwz r9,0(r4)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82389988
	if (ctx.cr6.eq) goto loc_82389988;
	// lwz r9,0(r5)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r8.u32);
loc_82389988:
	// stw r10,4352(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4352, ctx.r10.u32);
	// stw r30,4356(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4356, ctx.r30.u32);
	// stw r11,4360(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4360, ctx.r11.u32);
	// stw r28,4364(r7)
	PPC_STORE_U32(ctx.r7.u32 + 4364, ctx.r28.u32);
	// b 0x8233e4b0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238999C"))) PPC_WEAK_FUNC(sub_8238999C);
PPC_FUNC_IMPL(__imp__sub_8238999C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_823899A0"))) PPC_WEAK_FUNC(sub_823899A0);
PPC_FUNC_IMPL(__imp__sub_823899A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e440
	ctx.lr = 0x823899A8;
	__restfpr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// addi r25,r3,5288
	ctx.r25.s64 = ctx.r3.s64 + 5288;
	// ori r23,r10,65535
	ctx.r23.u64 = ctx.r10.u64 | 65535;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x823899E4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,5288(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5288);
	// lwz r9,5296(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5296);
	// rlwinm r11,r8,0,0,29
	ctx.r11.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFC;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// add r30,r9,r10
	ctx.r30.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// lwzu r27,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r27.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// addi r26,r11,4
	ctx.r26.s64 = ctx.r11.s64 + 4;
	// slw r11,r6,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r10.u8 & 0x3F));
	// blt cr6,0x82389a28
	if (ctx.cr6.lt) goto loc_82389A28;
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// slw r28,r27,r30
	ctx.r28.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x82389a2c
	goto loc_82389A2C;
loc_82389A28:
	// slw r28,r11,r9
	ctx.r28.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r9.u8 & 0x3F));
loc_82389A2C:
	// lis r22,-32171
	ctx.r22.s64 = -2108358656;
	// li r18,0
	ctx.r18.s64 = 0;
	// lis r21,-32171
	ctx.r21.s64 = -2108358656;
	// lis r20,-32171
	ctx.r20.s64 = -2108358656;
	// lis r19,-32171
	ctx.r19.s64 = -2108358656;
loc_82389A40:
	// rlwinm r11,r28,23,9,31
	ctx.r11.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 23) & 0x7FFFFF;
	// cmpwi cr6,r30,9
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 9, ctx.xer);
	// ble cr6,0x82389a58
	if (!ctx.cr6.gt) goto loc_82389A58;
	// subfic r10,r30,41
	ctx.xer.ca = ctx.r30.u32 <= 41;
	ctx.r10.s64 = 41 - ctx.r30.s64;
	// srw r9,r27,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r27.u32 >> (ctx.r10.u8 & 0x3F));
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
loc_82389A58:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82389f50
	if (ctx.cr6.eq) goto loc_82389F50;
	// lwz r8,5204(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5204);
loc_82389A64:
	// rlwinm r11,r28,11,21,31
	ctx.r11.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 11) & 0x7FF;
	// cmpwi cr6,r30,21
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 21, ctx.xer);
	// ble cr6,0x82389a7c
	if (!ctx.cr6.gt) goto loc_82389A7C;
	// subfic r10,r30,53
	ctx.xer.ca = ctx.r30.u32 <= 53;
	ctx.r10.s64 = 53 - ctx.r30.s64;
	// srw r9,r27,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r27.u32 >> (ctx.r10.u8 & 0x3F));
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
loc_82389A7C:
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82389a94
	if (!ctx.cr6.eq) goto loc_82389A94;
	// lwz r10,11320(r19)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r19.u32 + 11320);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// b 0x82389a9c
	goto loc_82389A9C;
loc_82389A94:
	// lwz r10,11316(r20)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r20.u32 + 11316);
	// rlwinm r9,r11,27,5,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFE;
loc_82389A9C:
	// lhzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// clrlwi r11,r10,28
	ctx.r11.u64 = ctx.r10.u32 & 0xF;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// blt cr6,0x82389ac8
	if (ctx.cr6.lt) goto loc_82389AC8;
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// slw r28,r27,r30
	ctx.r28.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x82389acc
	goto loc_82389ACC;
loc_82389AC8:
	// slw r28,r28,r11
	ctx.r28.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r11.u8 & 0x3F));
loc_82389ACC:
	// rlwinm r11,r10,28,26,31
	ctx.r11.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x3F;
	// cmpwi cr6,r11,34
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 34, ctx.xer);
	// beq cr6,0x82389a64
	if (ctx.cr6.eq) goto loc_82389A64;
	// cmpwi cr6,r11,35
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 35, ctx.xer);
	// bne cr6,0x82389af0
	if (!ctx.cr6.eq) goto loc_82389AF0;
	// lwz r11,5204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5204);
	// addi r11,r11,33
	ctx.r11.s64 = ctx.r11.s64 + 33;
	// stw r11,5204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5204, ctx.r11.u32);
	// b 0x82389a64
	goto loc_82389A64;
loc_82389AF0:
	// cmpwi cr6,r11,36
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 36, ctx.xer);
	// beq cr6,0x82389f50
	if (ctx.cr6.eq) goto loc_82389F50;
	// lwz r9,5204(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5204);
	// rlwinm r10,r10,22,10,31
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x3FFFFF;
	// lwz r7,5216(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5216);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r10,5220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5220, ctx.r10.u32);
	// stw r11,5204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5204, ctx.r11.u32);
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x82389f50
	if (ctx.cr6.gt) goto loc_82389F50;
	// subf r4,r8,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r8.s64;
	// lwz r11,5212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// lwz r10,4836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4836);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// stw r11,5212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5212, ctx.r11.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x82389b5c
	if (ctx.cr6.lt) goto loc_82389B5C;
loc_82389B34:
	// lwz r9,5212(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// lwz r11,5208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5208);
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// rotlwi r6,r8,0
	ctx.r6.u64 = rotl32(ctx.r8.u32, 0);
	// stw r8,5212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5212, ctx.r8.u32);
	// stw r7,5208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5208, ctx.r7.u32);
	// lwz r5,4836(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4836);
	// cmpw cr6,r6,r5
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x82389b34
	if (!ctx.cr6.lt) goto loc_82389B34;
loc_82389B5C:
	// cmpwi cr6,r4,-2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -2, ctx.xer);
	// beq cr6,0x82389f50
	if (ctx.cr6.eq) goto loc_82389F50;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x82389b8c
	if (!ctx.cr6.eq) goto loc_82389B8C;
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// ble cr6,0x82389b8c
	if (!ctx.cr6.gt) goto loc_82389B8C;
	// lwz r11,5088(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5088);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82389B84;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823897f8
	ctx.lr = 0x82389B8C;
	sub_823897F8(ctx, base);
loc_82389B8C:
	// lwz r11,5220(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5220);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82389bf4
	if (!ctx.cr6.eq) goto loc_82389BF4;
	// rlwinm r11,r28,6,26,31
	ctx.r11.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 6) & 0x3F;
	// cmpwi cr6,r30,26
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 26, ctx.xer);
	// ble cr6,0x82389bb4
	if (!ctx.cr6.gt) goto loc_82389BB4;
	// subfic r10,r30,58
	ctx.xer.ca = ctx.r30.u32 <= 58;
	ctx.r10.s64 = 58 - ctx.r30.s64;
	// srw r9,r27,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r27.u32 >> (ctx.r10.u8 & 0x3F));
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
loc_82389BB4:
	// lwz r10,11340(r21)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r21.u32 + 11340);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r8,r9,24,8,31
	ctx.r8.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFFFFFF;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r8,5220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5220, ctx.r8.u32);
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// blt cr6,0x82389bf0
	if (ctx.cr6.lt) goto loc_82389BF0;
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// slw r28,r27,r30
	ctx.r28.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x82389bf4
	goto loc_82389BF4;
loc_82389BF0:
	// slw r28,r28,r11
	ctx.r28.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r11.u8 & 0x3F));
loc_82389BF4:
	// lwz r10,5220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5220);
	// rlwinm r11,r10,0,27,27
	ctx.r11.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82389c58
	if (ctx.cr6.eq) goto loc_82389C58;
	// cmpwi cr6,r30,27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 27, ctx.xer);
	// blt cr6,0x82389c48
	if (ctx.cr6.lt) goto loc_82389C48;
	// addic. r30,r30,-27
	ctx.xer.ca = ctx.r30.u32 > 26;
	ctx.r30.s64 = ctx.r30.s64 + -27;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82389c34
	if (ctx.cr0.eq) goto loc_82389C34;
	// subfic r11,r30,5
	ctx.xer.ca = ctx.r30.u32 <= 5;
	ctx.r11.s64 = 5 - ctx.r30.s64;
	// srw r9,r27,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r27.u32 >> (ctx.r11.u8 & 0x3F));
	// or r8,r9,r28
	ctx.r8.u64 = ctx.r9.u64 | ctx.r28.u64;
	// slw r28,r27,r30
	ctx.r28.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r11,r8,5,27,31
	ctx.r11.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0x1F;
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x82389c54
	goto loc_82389C54;
loc_82389C34:
	// rlwinm r11,r28,5,27,31
	ctx.r11.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0x1F;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x82389c54
	goto loc_82389C54;
loc_82389C48:
	// rlwinm r11,r28,5,27,31
	ctx.r11.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0x1F;
	// addi r30,r30,5
	ctx.r30.s64 = ctx.r30.s64 + 5;
	// rlwinm r28,r28,5,0,26
	ctx.r28.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0xFFFFFFE0;
loc_82389C54:
	// stw r11,5128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5128, ctx.r11.u32);
loc_82389C58:
	// rlwinm r11,r10,0,28,28
	ctx.r11.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82389cb8
	if (ctx.cr6.eq) goto loc_82389CB8;
	// stw r28,4352(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4352, ctx.r28.u32);
	// addi r4,r31,5132
	ctx.r4.s64 = ctx.r31.s64 + 5132;
	// stw r27,4356(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4356, ctx.r27.u32);
	// addi r6,r31,5148
	ctx.r6.s64 = ctx.r31.s64 + 5148;
	// stw r30,4360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4360, ctx.r30.u32);
	// addi r5,r31,5156
	ctx.r5.s64 = ctx.r31.s64 + 5156;
	// stw r26,4364(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4364, ctx.r26.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82389810
	ctx.lr = 0x82389C88;
	sub_82389810(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r6,r31,5152
	ctx.r6.s64 = ctx.r31.s64 + 5152;
	// addi r5,r31,5160
	ctx.r5.s64 = ctx.r31.s64 + 5160;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82389810
	ctx.lr = 0x82389C9C;
	sub_82389810(ctx, base);
	// or r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 | ctx.r30.u64;
	// lwz r28,4352(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4352);
	// lwz r27,4356(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4356);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r30,4360(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4360);
	// lwz r26,4364(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4364);
	// bne cr6,0x82389f50
	if (!ctx.cr6.eq) goto loc_82389F50;
loc_82389CB8:
	// lwz r11,5220(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5220);
	// rlwinm r10,r11,0,29,29
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82389d1c
	if (ctx.cr6.eq) goto loc_82389D1C;
	// stw r28,4352(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4352, ctx.r28.u32);
	// addi r4,r31,5168
	ctx.r4.s64 = ctx.r31.s64 + 5168;
	// stw r27,4356(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4356, ctx.r27.u32);
	// addi r6,r31,5184
	ctx.r6.s64 = ctx.r31.s64 + 5184;
	// stw r30,4360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4360, ctx.r30.u32);
	// addi r5,r31,5192
	ctx.r5.s64 = ctx.r31.s64 + 5192;
	// stw r26,4364(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4364, ctx.r26.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82389810
	ctx.lr = 0x82389CEC;
	sub_82389810(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r6,r31,5188
	ctx.r6.s64 = ctx.r31.s64 + 5188;
	// addi r5,r31,5196
	ctx.r5.s64 = ctx.r31.s64 + 5196;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82389810
	ctx.lr = 0x82389D00;
	sub_82389810(ctx, base);
	// or r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 | ctx.r30.u64;
	// lwz r28,4352(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4352);
	// lwz r27,4356(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4356);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r30,4360(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4360);
	// lwz r26,4364(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4364);
	// bne cr6,0x82389f50
	if (!ctx.cr6.eq) goto loc_82389F50;
loc_82389D1C:
	// lwz r9,5220(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5220);
	// rlwinm r11,r9,0,30,30
	ctx.r11.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82389d88
	if (ctx.cr6.eq) goto loc_82389D88;
	// rlwinm r11,r28,9,23,31
	ctx.r11.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 9) & 0x1FF;
	// cmpwi cr6,r30,23
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 23, ctx.xer);
	// ble cr6,0x82389d44
	if (!ctx.cr6.gt) goto loc_82389D44;
	// subfic r10,r30,55
	ctx.xer.ca = ctx.r30.u32 <= 55;
	ctx.r10.s64 = 55 - ctx.r30.s64;
	// srw r8,r27,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r27.u32 >> (ctx.r10.u8 & 0x3F));
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
loc_82389D44:
	// lwz r10,11352(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 11352);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// rlwinm r7,r8,16,0,11
	ctx.r7.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFF00000;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r7,5224(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5224, ctx.r7.u32);
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// blt cr6,0x82389d80
	if (ctx.cr6.lt) goto loc_82389D80;
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// slw r28,r27,r30
	ctx.r28.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x82389d8c
	goto loc_82389D8C;
loc_82389D80:
	// slw r28,r28,r11
	ctx.r28.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r11.u8 & 0x3F));
	// b 0x82389d8c
	goto loc_82389D8C;
loc_82389D88:
	// stw r18,5224(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5224, ctx.r18.u32);
loc_82389D8C:
	// clrlwi r11,r9,31
	ctx.r11.u64 = ctx.r9.u32 & 0x1;
	// stw r28,4352(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4352, ctx.r28.u32);
	// stw r27,4356(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4356, ctx.r27.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r30,4360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4360, ctx.r30.u32);
	// stw r26,4364(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4364, ctx.r26.u32);
	// beq cr6,0x82389ddc
	if (ctx.cr6.eq) goto loc_82389DDC;
	// lwz r11,5092(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5092);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82389DB8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,5100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5100);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82389DC8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,5132
	ctx.r3.s64 = ctx.r31.s64 + 5132;
	// bl 0x823897e0
	ctx.lr = 0x82389DD0;
	sub_823897E0(ctx, base);
	// addi r3,r31,5168
	ctx.r3.s64 = ctx.r31.s64 + 5168;
	// bl 0x823897e0
	ctx.lr = 0x82389DD8;
	sub_823897E0(ctx, base);
	// b 0x82389e24
	goto loc_82389E24;
loc_82389DDC:
	// srawi r11,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 2;
	// lwz r10,5224(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5224);
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r9,r11,1276
	ctx.r9.s64 = ctx.r11.s64 + 1276;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r29,r8,r31
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	// stw r29,5104(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5104, ctx.r29.u32);
	// beq cr6,0x82389e10
	if (ctx.cr6.eq) goto loc_82389E10;
	// lwz r11,5096(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5096);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82389E10;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82389E10:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
	// bctrl 
	ctx.lr = 0x82389E1C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823897f8
	ctx.lr = 0x82389E24;
	sub_823897F8(ctx, base);
loc_82389E24:
	// lwz r11,5412(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5412);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82389f50
	if (!ctx.cr6.eq) goto loc_82389F50;
	// lwz r11,5316(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5316);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,5316(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5316, ctx.r11.u32);
	// bgt 0x82389e58
	if (ctx.cr0.gt) goto loc_82389E58;
	// lwz r11,4816(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4816);
	// lwz r10,4820(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4820);
	// lwz r3,4824(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4824);
	// stw r11,5316(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5316, ctx.r11.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82389E58;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82389E58:
	// lwz r30,4360(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4360);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// clrlwi r29,r30,29
	ctx.r29.u64 = ctx.r30.u32 & 0x7;
	// lwz r26,4364(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4364);
	// lwz r9,5292(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5292);
	// subf r11,r29,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r29.s64;
	// lwz r28,4352(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4352);
	// lwz r27,4356(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4356);
	// addi r8,r11,7
	ctx.r8.s64 = ctx.r11.s64 + 7;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// subf r11,r10,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r10.s64;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r4,r11,-8
	ctx.r4.s64 = ctx.r11.s64 + -8;
	// subf r6,r4,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r4.s64;
	// cmpwi cr6,r6,2048
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2048, ctx.xer);
	// bgt cr6,0x82389f48
	if (ctx.cr6.gt) goto loc_82389F48;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8232b788
	ctx.lr = 0x82389EA8;
	sub_8232B788(ctx, base);
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82389EC4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82389EE0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r24)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r11,24(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82389F00;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// rlwinm r11,r10,0,0,29
	ctx.r11.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// add r30,r29,r10
	ctx.r30.u64 = ctx.r29.u64 + ctx.r10.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// lwzu r27,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r27.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// addi r26,r11,4
	ctx.r26.s64 = ctx.r11.s64 + 4;
	// slw r11,r8,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// blt cr6,0x82389f44
	if (ctx.cr6.lt) goto loc_82389F44;
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// mr r29,r18
	ctx.r29.u64 = ctx.r18.u64;
	// slw r28,r27,r30
	ctx.r28.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x82389a40
	goto loc_82389A40;
loc_82389F44:
	// slw r28,r11,r29
	ctx.r28.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r29.u8 & 0x3F));
loc_82389F48:
	// mr r29,r18
	ctx.r29.u64 = ctx.r18.u64;
	// b 0x82389a40
	goto loc_82389A40;
loc_82389F50:
	// addi r11,r30,7
	ctx.r11.s64 = ctx.r30.s64 + 7;
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// srawi r9,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 3;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// subf r11,r10,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r10.s64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r4,r11,-8
	ctx.r4.s64 = ctx.r11.s64 + -8;
	// bl 0x8232b788
	ctx.lr = 0x82389F78;
	sub_8232B788(ctx, base);
	// lwz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r7,32(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x82389F94;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,0(r24)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r11,28(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82389FB0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82325cf8
	ctx.lr = 0x82389FB8;
	sub_82325CF8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8233e490
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82389FC0"))) PPC_WEAK_FUNC(sub_82389FC0);
PPC_FUNC_IMPL(__imp__sub_82389FC0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e440
	ctx.lr = 0x82389FC8;
	__restfpr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// addi r25,r3,5288
	ctx.r25.s64 = ctx.r3.s64 + 5288;
	// ori r23,r10,65535
	ctx.r23.u64 = ctx.r10.u64 | 65535;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,24(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 24);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8238A004;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,5288(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5288);
	// lwz r9,5296(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5296);
	// rlwinm r11,r8,0,0,29
	ctx.r11.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFC;
	// subf r7,r11,r8
	ctx.r7.s64 = ctx.r8.s64 - ctx.r11.s64;
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// add r30,r9,r10
	ctx.r30.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// lwzu r27,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r27.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// addi r26,r11,4
	ctx.r26.s64 = ctx.r11.s64 + 4;
	// slw r11,r6,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r10.u8 & 0x3F));
	// blt cr6,0x8238a048
	if (ctx.cr6.lt) goto loc_8238A048;
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// slw r28,r27,r30
	ctx.r28.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x8238a04c
	goto loc_8238A04C;
loc_8238A048:
	// slw r28,r11,r9
	ctx.r28.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r9.u8 & 0x3F));
loc_8238A04C:
	// lis r22,-32171
	ctx.r22.s64 = -2108358656;
	// li r18,0
	ctx.r18.s64 = 0;
	// lis r21,-32171
	ctx.r21.s64 = -2108358656;
	// lis r20,-32171
	ctx.r20.s64 = -2108358656;
	// lis r19,-32171
	ctx.r19.s64 = -2108358656;
loc_8238A060:
	// rlwinm r11,r28,23,9,31
	ctx.r11.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 23) & 0x7FFFFF;
	// cmpwi cr6,r30,9
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 9, ctx.xer);
	// ble cr6,0x8238a078
	if (!ctx.cr6.gt) goto loc_8238A078;
	// subfic r10,r30,41
	ctx.xer.ca = ctx.r30.u32 <= 41;
	ctx.r10.s64 = 41 - ctx.r30.s64;
	// srw r9,r27,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r27.u32 >> (ctx.r10.u8 & 0x3F));
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
loc_8238A078:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8238a2e0
	if (ctx.cr6.eq) goto loc_8238A2E0;
	// lwz r8,5204(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5204);
loc_8238A084:
	// rlwinm r11,r28,11,21,31
	ctx.r11.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 11) & 0x7FF;
	// cmpwi cr6,r30,21
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 21, ctx.xer);
	// ble cr6,0x8238a09c
	if (!ctx.cr6.gt) goto loc_8238A09C;
	// subfic r10,r30,53
	ctx.xer.ca = ctx.r30.u32 <= 53;
	ctx.r10.s64 = 53 - ctx.r30.s64;
	// srw r9,r27,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r27.u32 >> (ctx.r10.u8 & 0x3F));
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
loc_8238A09C:
	// rlwinm r10,r11,0,0,24
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8238a0b4
	if (!ctx.cr6.eq) goto loc_8238A0B4;
	// lwz r10,11336(r19)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r19.u32 + 11336);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// b 0x8238a0bc
	goto loc_8238A0BC;
loc_8238A0B4:
	// lwz r10,11332(r20)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r20.u32 + 11332);
	// rlwinm r9,r11,27,5,30
	ctx.r9.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFE;
loc_8238A0BC:
	// lhzx r7,r9,r10
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// extsh r10,r7
	ctx.r10.s64 = ctx.r7.s16;
	// clrlwi r11,r10,28
	ctx.r11.u64 = ctx.r10.u32 & 0xF;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// blt cr6,0x8238a0e8
	if (ctx.cr6.lt) goto loc_8238A0E8;
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// slw r28,r27,r30
	ctx.r28.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x8238a0ec
	goto loc_8238A0EC;
loc_8238A0E8:
	// slw r28,r28,r11
	ctx.r28.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r11.u8 & 0x3F));
loc_8238A0EC:
	// rlwinm r11,r10,28,26,31
	ctx.r11.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x3F;
	// cmpwi cr6,r11,34
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 34, ctx.xer);
	// beq cr6,0x8238a084
	if (ctx.cr6.eq) goto loc_8238A084;
	// cmpwi cr6,r11,35
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 35, ctx.xer);
	// bne cr6,0x8238a110
	if (!ctx.cr6.eq) goto loc_8238A110;
	// lwz r11,5204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5204);
	// addi r11,r11,33
	ctx.r11.s64 = ctx.r11.s64 + 33;
	// stw r11,5204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5204, ctx.r11.u32);
	// b 0x8238a084
	goto loc_8238A084;
loc_8238A110:
	// cmpwi cr6,r11,36
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 36, ctx.xer);
	// beq cr6,0x8238a2e0
	if (ctx.cr6.eq) goto loc_8238A2E0;
	// lwz r9,5204(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5204);
	// rlwinm r10,r10,22,10,31
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x3FFFFF;
	// lwz r7,5216(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5216);
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r10,5220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5220, ctx.r10.u32);
	// stw r11,5204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5204, ctx.r11.u32);
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bgt cr6,0x8238a2e0
	if (ctx.cr6.gt) goto loc_8238A2E0;
	// subf r4,r8,r11
	ctx.r4.s64 = ctx.r11.s64 - ctx.r8.s64;
	// lwz r11,5212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// lwz r10,4836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4836);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// stw r11,5212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5212, ctx.r11.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8238a17c
	if (ctx.cr6.lt) goto loc_8238A17C;
loc_8238A154:
	// lwz r9,5212(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// lwz r11,5208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5208);
	// subf r8,r10,r9
	ctx.r8.s64 = ctx.r9.s64 - ctx.r10.s64;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// rotlwi r6,r8,0
	ctx.r6.u64 = rotl32(ctx.r8.u32, 0);
	// stw r8,5212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5212, ctx.r8.u32);
	// stw r7,5208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5208, ctx.r7.u32);
	// lwz r5,4836(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4836);
	// cmpw cr6,r6,r5
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r5.s32, ctx.xer);
	// bge cr6,0x8238a154
	if (!ctx.cr6.lt) goto loc_8238A154;
loc_8238A17C:
	// cmpwi cr6,r4,-2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -2, ctx.xer);
	// beq cr6,0x8238a2e0
	if (ctx.cr6.eq) goto loc_8238A2E0;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x8238a1b4
	if (!ctx.cr6.eq) goto loc_8238A1B4;
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// ble cr6,0x8238a1b4
	if (!ctx.cr6.gt) goto loc_8238A1B4;
	// lwz r11,5088(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5088);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238A1A4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r31,5132
	ctx.r3.s64 = ctx.r31.s64 + 5132;
	// bl 0x823897e0
	ctx.lr = 0x8238A1AC;
	sub_823897E0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823897f8
	ctx.lr = 0x8238A1B4;
	sub_823897F8(ctx, base);
loc_8238A1B4:
	// lwz r11,5220(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5220);
	// rlwinm r10,r11,0,26,26
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8238a21c
	if (!ctx.cr6.eq) goto loc_8238A21C;
	// rlwinm r11,r28,5,27,31
	ctx.r11.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0x1F;
	// cmpwi cr6,r30,27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 27, ctx.xer);
	// ble cr6,0x8238a1dc
	if (!ctx.cr6.gt) goto loc_8238A1DC;
	// subfic r10,r30,59
	ctx.xer.ca = ctx.r30.u32 <= 59;
	ctx.r10.s64 = 59 - ctx.r30.s64;
	// srw r9,r27,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r27.u32 >> (ctx.r10.u8 & 0x3F));
	// or r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 | ctx.r11.u64;
loc_8238A1DC:
	// lwz r10,11312(r21)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r21.u32 + 11312);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// clrlwi r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	// rlwinm r8,r9,24,8,31
	ctx.r8.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 24) & 0xFFFFFF;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r8,5220(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5220, ctx.r8.u32);
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// blt cr6,0x8238a218
	if (ctx.cr6.lt) goto loc_8238A218;
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// slw r28,r27,r30
	ctx.r28.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x8238a21c
	goto loc_8238A21C;
loc_8238A218:
	// slw r28,r28,r11
	ctx.r28.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r11.u8 & 0x3F));
loc_8238A21C:
	// lwz r10,5220(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5220);
	// rlwinm r11,r10,0,27,27
	ctx.r11.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x10;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8238a280
	if (ctx.cr6.eq) goto loc_8238A280;
	// cmpwi cr6,r30,27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 27, ctx.xer);
	// blt cr6,0x8238a270
	if (ctx.cr6.lt) goto loc_8238A270;
	// addic. r30,r30,-27
	ctx.xer.ca = ctx.r30.u32 > 26;
	ctx.r30.s64 = ctx.r30.s64 + -27;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8238a25c
	if (ctx.cr0.eq) goto loc_8238A25C;
	// subfic r11,r30,5
	ctx.xer.ca = ctx.r30.u32 <= 5;
	ctx.r11.s64 = 5 - ctx.r30.s64;
	// srw r9,r27,r11
	ctx.r9.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r27.u32 >> (ctx.r11.u8 & 0x3F));
	// or r8,r9,r28
	ctx.r8.u64 = ctx.r9.u64 | ctx.r28.u64;
	// slw r28,r27,r30
	ctx.r28.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r11,r8,5,27,31
	ctx.r11.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 5) & 0x1F;
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x8238a27c
	goto loc_8238A27C;
loc_8238A25C:
	// rlwinm r11,r28,5,27,31
	ctx.r11.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0x1F;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x8238a27c
	goto loc_8238A27C;
loc_8238A270:
	// rlwinm r11,r28,5,27,31
	ctx.r11.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0x1F;
	// addi r30,r30,5
	ctx.r30.s64 = ctx.r30.s64 + 5;
	// rlwinm r28,r28,5,0,26
	ctx.r28.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0xFFFFFFE0;
loc_8238A27C:
	// stw r11,5128(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5128, ctx.r11.u32);
loc_8238A280:
	// rlwinm r11,r10,0,28,28
	ctx.r11.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8238a350
	if (ctx.cr6.eq) goto loc_8238A350;
	// stw r28,4352(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4352, ctx.r28.u32);
	// addi r4,r31,5132
	ctx.r4.s64 = ctx.r31.s64 + 5132;
	// stw r27,4356(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4356, ctx.r27.u32);
	// addi r6,r31,5148
	ctx.r6.s64 = ctx.r31.s64 + 5148;
	// stw r30,4360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4360, ctx.r30.u32);
	// addi r5,r31,5156
	ctx.r5.s64 = ctx.r31.s64 + 5156;
	// stw r26,4364(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4364, ctx.r26.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82389810
	ctx.lr = 0x8238A2B0;
	sub_82389810(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r6,r31,5152
	ctx.r6.s64 = ctx.r31.s64 + 5152;
	// addi r5,r31,5160
	ctx.r5.s64 = ctx.r31.s64 + 5160;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82389810
	ctx.lr = 0x8238A2C4;
	sub_82389810(ctx, base);
	// or r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 | ctx.r30.u64;
	// lwz r28,4352(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4352);
	// lwz r27,4356(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4356);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r30,4360(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4360);
	// lwz r26,4364(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4364);
	// beq cr6,0x8238a358
	if (ctx.cr6.eq) goto loc_8238A358;
loc_8238A2E0:
	// addi r11,r30,7
	ctx.r11.s64 = ctx.r30.s64 + 7;
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// srawi r9,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 3;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// subf r11,r10,r9
	ctx.r11.s64 = ctx.r9.s64 - ctx.r10.s64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r4,r11,-8
	ctx.r4.s64 = ctx.r11.s64 + -8;
	// bl 0x8232b788
	ctx.lr = 0x8238A308;
	sub_8232B788(ctx, base);
	// lwz r8,0(r24)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r7,32(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8238A324;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r6,0(r24)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r11,28(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238A340;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82325cf8
	ctx.lr = 0x8238A348;
	sub_82325CF8(ctx, base);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8233e490
	__restgprlr_18(ctx, base);
	return;
loc_8238A350:
	// addi r3,r31,5132
	ctx.r3.s64 = ctx.r31.s64 + 5132;
	// bl 0x823897e0
	ctx.lr = 0x8238A358;
	sub_823897E0(ctx, base);
loc_8238A358:
	// lwz r9,5220(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5220);
	// rlwinm r11,r9,0,30,30
	ctx.r11.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x2;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8238a3c4
	if (ctx.cr6.eq) goto loc_8238A3C4;
	// rlwinm r11,r28,9,23,31
	ctx.r11.u64 = rotl64(ctx.r28.u32 | (ctx.r28.u64 << 32), 9) & 0x1FF;
	// cmpwi cr6,r30,23
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 23, ctx.xer);
	// ble cr6,0x8238a380
	if (!ctx.cr6.gt) goto loc_8238A380;
	// subfic r10,r30,55
	ctx.xer.ca = ctx.r30.u32 <= 55;
	ctx.r10.s64 = 55 - ctx.r30.s64;
	// srw r8,r27,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r27.u32 >> (ctx.r10.u8 & 0x3F));
	// or r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 | ctx.r11.u64;
loc_8238A380:
	// lwz r10,11352(r22)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r22.u32 + 11352);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// rlwinm r7,r8,16,0,11
	ctx.r7.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0xFFF00000;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r7,5224(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5224, ctx.r7.u32);
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// blt cr6,0x8238a3bc
	if (ctx.cr6.lt) goto loc_8238A3BC;
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// slw r28,r27,r30
	ctx.r28.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x8238a3c8
	goto loc_8238A3C8;
loc_8238A3BC:
	// slw r28,r28,r11
	ctx.r28.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r28.u32 << (ctx.r11.u8 & 0x3F));
	// b 0x8238a3c8
	goto loc_8238A3C8;
loc_8238A3C4:
	// stw r18,5224(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5224, ctx.r18.u32);
loc_8238A3C8:
	// clrlwi r11,r9,31
	ctx.r11.u64 = ctx.r9.u32 & 0x1;
	// stw r28,4352(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4352, ctx.r28.u32);
	// stw r27,4356(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4356, ctx.r27.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r30,4360(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4360, ctx.r30.u32);
	// stw r26,4364(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4364, ctx.r26.u32);
	// beq cr6,0x8238a408
	if (ctx.cr6.eq) goto loc_8238A408;
	// lwz r11,5092(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5092);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238A3F4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,5100(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5100);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8238A404;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8238a43c
	goto loc_8238A43C;
loc_8238A408:
	// lwz r11,5224(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5224);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8238a424
	if (ctx.cr6.eq) goto loc_8238A424;
	// lwz r11,5096(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5096);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238A424;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8238A424:
	// lwz r11,5112(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5112);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238A434;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823897f8
	ctx.lr = 0x8238A43C;
	sub_823897F8(ctx, base);
loc_8238A43C:
	// lwz r11,5412(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5412);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8238a2e0
	if (!ctx.cr6.eq) goto loc_8238A2E0;
	// lwz r11,5316(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5316);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,5316(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5316, ctx.r11.u32);
	// bgt 0x8238a470
	if (ctx.cr0.gt) goto loc_8238A470;
	// lwz r11,4816(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4816);
	// lwz r10,4820(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4820);
	// lwz r3,4824(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4824);
	// stw r11,5316(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5316, ctx.r11.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8238A470;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8238A470:
	// lwz r30,4360(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4360);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// clrlwi r29,r30,29
	ctx.r29.u64 = ctx.r30.u32 & 0x7;
	// lwz r26,4364(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4364);
	// lwz r9,5292(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5292);
	// subf r11,r29,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r29.s64;
	// lwz r28,4352(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4352);
	// lwz r27,4356(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4356);
	// addi r8,r11,7
	ctx.r8.s64 = ctx.r11.s64 + 7;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// subf r11,r10,r7
	ctx.r11.s64 = ctx.r7.s64 - ctx.r10.s64;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r4,r11,-8
	ctx.r4.s64 = ctx.r11.s64 + -8;
	// subf r6,r4,r9
	ctx.r6.s64 = ctx.r9.s64 - ctx.r4.s64;
	// cmpwi cr6,r6,2048
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2048, ctx.xer);
	// bgt cr6,0x8238a560
	if (ctx.cr6.gt) goto loc_8238A560;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8232b788
	ctx.lr = 0x8238A4C0;
	sub_8232B788(ctx, base);
	// lwz r11,0(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r10,32(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8238A4DC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r8,28(r9)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x8238A4F8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,0(r24)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwz r11,24(r7)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8238A518;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,0(r25)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r25.u32 + 0);
	// rlwinm r11,r10,0,0,29
	ctx.r11.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// subf r9,r11,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r11.s64;
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// add r30,r29,r10
	ctx.r30.u64 = ctx.r29.u64 + ctx.r10.u64;
	// cmpwi cr6,r30,32
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 32, ctx.xer);
	// lwzu r27,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r27.u64 = PPC_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// addi r26,r11,4
	ctx.r26.s64 = ctx.r11.s64 + 4;
	// slw r11,r8,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// blt cr6,0x8238a55c
	if (ctx.cr6.lt) goto loc_8238A55C;
	// addi r30,r30,-32
	ctx.r30.s64 = ctx.r30.s64 + -32;
	// mr r29,r18
	ctx.r29.u64 = ctx.r18.u64;
	// slw r28,r27,r30
	ctx.r28.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r27.u32 << (ctx.r30.u8 & 0x3F));
	// lwz r27,0(r26)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// b 0x8238a060
	goto loc_8238A060;
loc_8238A55C:
	// slw r28,r11,r29
	ctx.r28.u64 = ctx.r29.u8 & 0x20 ? 0 : (ctx.r11.u32 << (ctx.r29.u8 & 0x3F));
loc_8238A560:
	// mr r29,r18
	ctx.r29.u64 = ctx.r18.u64;
	// b 0x8238a060
	goto loc_8238A060;
}

__attribute__((alias("__imp__sub_8238A568"))) PPC_WEAK_FUNC(sub_8238A568);
PPC_FUNC_IMPL(__imp__sub_8238A568) {
	PPC_FUNC_PROLOGUE();
	// lwz r11,5208(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5208);
	// addi r4,r3,4640
	ctx.r4.s64 = ctx.r3.s64 + 4640;
	// lhz r10,5052(r3)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5052);
	// lis r5,-32198
	ctx.r5.s64 = -2110128128;
	// lwz r9,5212(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5212);
	// rlwinm r8,r11,3,0,28
	ctx.r8.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// extsh r7,r10
	ctx.r7.s64 = ctx.r10.s16;
	// lwz r6,5040(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5040);
	// rlwinm r10,r9,3,0,28
	ctx.r10.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// lhz r9,5054(r3)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r3.u32 + 5054);
	// mullw r11,r7,r8
	ctx.r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r8.s32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// extsh r7,r9
	ctx.r7.s64 = ctx.r9.s16;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// rlwinm r9,r8,1,0,30
	ctx.r9.u64 = rotl64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r6,4644(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4644, ctx.r6.u32);
	// addi r8,r4,4
	ctx.r8.s64 = ctx.r4.s64 + 4;
	// lwz r8,5044(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5044);
	// mullw r9,r9,r7
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r8,4652(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4652, ctx.r8.u32);
	// lwz r11,5048(r3)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5048);
	// rlwinm r7,r7,3,0,28
	ctx.r7.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r6,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r10.s32 >> 4;
	// stw r11,4660(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4660, ctx.r11.u32);
	// addi r10,r11,8
	ctx.r10.s64 = ctx.r11.s64 + 8;
	// rotlwi r11,r11,0
	ctx.r11.u64 = rotl32(ctx.r11.u32, 0);
	// addi r9,r5,-22256
	ctx.r9.s64 = ctx.r5.s64 + -22256;
	// stw r10,4668(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4668, ctx.r10.u32);
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// addi r7,r9,4
	ctx.r7.s64 = ctx.r9.s64 + 4;
	// rlwinm r10,r6,3,25,28
	ctx.r10.u64 = rotl64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0x78;
	// stw r11,4676(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4676, ctx.r11.u32);
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// stw r8,4684(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4684, ctx.r8.u32);
	// lwz r5,4416(r3)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4416);
	// lwzx r6,r10,r7
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r7.u32);
	// lwzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8238A614"))) PPC_WEAK_FUNC(sub_8238A614);
PPC_FUNC_IMPL(__imp__sub_8238A614) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8238A618"))) PPC_WEAK_FUNC(sub_8238A618);
PPC_FUNC_IMPL(__imp__sub_8238A618) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e440
	ctx.lr = 0x8238A620;
	__restfpr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,28(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 28);
	// mr r22,r6
	ctx.r22.u64 = ctx.r6.u64;
	// lwz r28,24(r7)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r7.u32 + 24);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// srawi r23,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r23.s64 = ctx.r10.s32 >> 1;
	// lwz r21,4764(r3)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4764);
	// srawi r6,r28,1
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r28.s32 >> 1;
	// lwz r7,4(r5)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r5.u32 + 4);
	// srawi r8,r28,1
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r28.s32 >> 1;
	// addi r30,r3,4556
	ctx.r30.s64 = ctx.r3.s64 + 4556;
	// lwz r3,0(r5)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// addze r11,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r11.s64 = temp.s64;
	// lhz r26,12(r22)
	ctx.r26.u64 = PPC_LOAD_U16(ctx.r22.u32 + 12);
	// srawi r5,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 1;
	// lhz r20,14(r22)
	ctx.r20.u64 = PPC_LOAD_U16(ctx.r22.u32 + 14);
	// clrlwi r8,r10,31
	ctx.r8.u64 = ctx.r10.u32 & 0x1;
	// addze r10,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r9,r21,1,0,30
	ctx.r9.u64 = rotl64(ctx.r21.u32 | (ctx.r21.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r5,r10,31
	ctx.r5.u64 = ctx.r10.u32 & 0x1;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// add r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r9,r5,r9
	ctx.r9.u64 = ctx.r5.u64 + ctx.r9.u64;
	// rlwinm r5,r4,1,0,30
	ctx.r5.u64 = rotl64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	// rlwinm r4,r9,1,0,30
	ctx.r4.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r25,r28,31
	ctx.r25.u64 = ctx.r28.u32 & 0x1;
	// lis r29,-32183
	ctx.r29.s64 = -2109145088;
	// add r5,r5,r25
	ctx.r5.u64 = ctx.r5.u64 + ctx.r25.u64;
	// addi r9,r29,20760
	ctx.r9.s64 = ctx.r29.s64 + 20760;
	// add r4,r4,r8
	ctx.r4.u64 = ctx.r4.u64 + ctx.r8.u64;
	// addi r28,r9,32
	ctx.r28.s64 = ctx.r9.s64 + 32;
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r4,r4,2,0,29
	ctx.r4.u64 = rotl64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// extsh r29,r26
	ctx.r29.s64 = ctx.r26.s16;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// lwzx r19,r5,r28
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r28.u32);
	// mullw r10,r10,r29
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r29.s32);
	// lwzx r18,r4,r9
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r4.u32 + ctx.r9.u32);
	// stw r29,4588(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4588, ctx.r29.u32);
	// stw r27,4580(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4580, ctx.r27.u32);
	// mtctr r18
	ctx.ctr.u64 = ctx.r18.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// and r24,r8,r21
	ctx.r24.u64 = ctx.r8.u64 & ctx.r21.u64;
	// add r26,r11,r3
	ctx.r26.u64 = ctx.r11.u64 + ctx.r3.u64;
	// extsh r28,r20
	ctx.r28.s64 = ctx.r20.s16;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mullw r10,r23,r28
	ctx.r10.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r28.s32);
	// lwz r11,0(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// add r9,r11,r24
	ctx.r9.u64 = ctx.r11.u64 + ctx.r24.u64;
	// stw r11,4592(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4592, ctx.r11.u32);
	// add r23,r10,r7
	ctx.r23.u64 = ctx.r10.u64 + ctx.r7.u64;
	// add r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 + ctx.r29.u64;
	// stw r9,4596(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4596, ctx.r9.u32);
	// bctrl 
	ctx.lr = 0x8238A708;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r8,r27,64
	ctx.r8.s64 = ctx.r27.s64 + 64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r18
	ctx.ctr.u64 = ctx.r18.u64;
	// stw r8,4580(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4580, ctx.r8.u32);
	// lwz r11,4(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 4);
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// add r10,r11,r24
	ctx.r10.u64 = ctx.r11.u64 + ctx.r24.u64;
	// stw r11,4592(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4592, ctx.r11.u32);
	// add r7,r10,r29
	ctx.r7.u64 = ctx.r10.u64 + ctx.r29.u64;
	// stw r7,4596(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4596, ctx.r7.u32);
	// bctrl 
	ctx.lr = 0x8238A734;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r6,r27,128
	ctx.r6.s64 = ctx.r27.s64 + 128;
	// stw r28,4588(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4588, ctx.r28.u32);
	// and r10,r25,r21
	ctx.r10.u64 = ctx.r25.u64 & ctx.r21.u64;
	// stw r6,4580(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4580, ctx.r6.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,8(r22)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + 8);
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,4592(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4592, ctx.r11.u32);
	// mtctr r19
	ctx.ctr.u64 = ctx.r19.u64;
	// add r5,r10,r28
	ctx.r5.u64 = ctx.r10.u64 + ctx.r28.u64;
	// stw r5,4596(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4596, ctx.r5.u32);
	// bctrl 
	ctx.lr = 0x8238A768;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x8233e490
	__restgprlr_18(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238A770"))) PPC_WEAK_FUNC(sub_8238A770);
PPC_FUNC_IMPL(__imp__sub_8238A770) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e460
	ctx.lr = 0x8238A778;
	__restfpr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r26,5204(r3)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5204);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,5212(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5212);
	// subf r11,r4,r26
	ctx.r11.s64 = ctx.r26.s64 - ctx.r4.s64;
	// subf r9,r4,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r4.s64;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// addic. r11,r9,1
	ctx.xer.ca = ctx.r9.u32 > 4294967294;
	ctx.r11.s64 = ctx.r9.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,5204(r3)
	PPC_STORE_U32(ctx.r3.u32 + 5204, ctx.r8.u32);
	// stw r11,5212(r3)
	PPC_STORE_U32(ctx.r3.u32 + 5212, ctx.r11.u32);
	// bge 0x8238a7cc
	if (!ctx.cr0.lt) goto loc_8238A7CC;
	// lwz r9,4836(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4836);
loc_8238A7A8:
	// lwz r11,5212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// lwz r10,5208(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5208);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rotlwi r7,r11,0
	ctx.r7.u64 = rotl32(ctx.r11.u32, 0);
	// stw r11,5212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5212, ctx.r11.u32);
	// stw r10,5208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5208, ctx.r10.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// blt cr6,0x8238a7a8
	if (ctx.cr6.lt) goto loc_8238A7A8;
loc_8238A7CC:
	// cmpw cr6,r8,r26
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r26.s32, ctx.xer);
	// bge cr6,0x8238a890
	if (!ctx.cr6.lt) goto loc_8238A890;
	// lis r11,-32198
	ctx.r11.s64 = -2110128128;
	// addi r29,r31,4992
	ctx.r29.s64 = ctx.r31.s64 + 4992;
	// addi r28,r31,4976
	ctx.r28.s64 = ctx.r31.s64 + 4976;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r30,r11,-21872
	ctx.r30.s64 = ctx.r11.s64 + -21872;
loc_8238A7E8:
	// lwz r11,5208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5208);
	// addi r8,r30,4
	ctx.r8.s64 = ctx.r30.s64 + 4;
	// lwz r7,5212(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lhz r6,4990(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4990);
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r11,r7,3,0,28
	ctx.r11.u64 = rotl64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lhz r3,4988(r31)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r31.u32 + 4988);
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = rotl64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r7,r6
	ctx.r7.s64 = ctx.r6.s16;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// mullw r9,r9,r7
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// extsh r6,r3
	ctx.r6.s64 = ctx.r3.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mullw r9,r6,r4
	ctx.r9.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r4.s32);
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// srawi r11,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 4;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// rlwinm r10,r11,3,25,28
	ctx.r10.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x78;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r9,r10,r30
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	// lwzx r6,r10,r8
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8238A850;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,5212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// lwz r8,4836(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4836);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,5212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5212, ctx.r11.u32);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x8238a878
	if (ctx.cr6.lt) goto loc_8238A878;
	// lwz r11,5208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5208);
	// stw r27,5212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5212, ctx.r27.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,5208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5208, ctx.r11.u32);
loc_8238A878:
	// lwz r11,5204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5204);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = rotl32(ctx.r11.u32, 0);
	// stw r11,5204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5204, ctx.r11.u32);
	// cmpw cr6,r10,r26
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r26.s32, ctx.xer);
	// blt cr6,0x8238a7e8
	if (ctx.cr6.lt) goto loc_8238A7E8;
loc_8238A890:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8233e4b0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238A898"))) PPC_WEAK_FUNC(sub_8238A898);
PPC_FUNC_IMPL(__imp__sub_8238A898) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e468
	ctx.lr = 0x8238A8A0;
	__restfpr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,5204(r3)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5204);
	// li r28,0
	ctx.r28.s64 = 0;
	// lwz r10,5212(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5212);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// subf r11,r4,r30
	ctx.r11.s64 = ctx.r30.s64 - ctx.r4.s64;
	// lwz r29,5104(r3)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r3.u32 + 5104);
	// subf r9,r4,r10
	ctx.r9.s64 = ctx.r10.s64 - ctx.r4.s64;
	// stw r28,5224(r3)
	PPC_STORE_U32(ctx.r3.u32 + 5224, ctx.r28.u32);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// addic. r11,r9,1
	ctx.xer.ca = ctx.r9.u32 > 4294967294;
	ctx.r11.s64 = ctx.r9.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r8,5204(r3)
	PPC_STORE_U32(ctx.r3.u32 + 5204, ctx.r8.u32);
	// stw r11,5212(r3)
	PPC_STORE_U32(ctx.r3.u32 + 5212, ctx.r11.u32);
	// bge 0x8238a900
	if (!ctx.cr0.lt) goto loc_8238A900;
	// lwz r9,4836(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 4836);
loc_8238A8DC:
	// lwz r11,5212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// lwz r10,5208(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5208);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rotlwi r7,r11,0
	ctx.r7.u64 = rotl32(ctx.r11.u32, 0);
	// stw r11,5212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5212, ctx.r11.u32);
	// stw r10,5208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5208, ctx.r10.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// blt cr6,0x8238a8dc
	if (ctx.cr6.lt) goto loc_8238A8DC;
loc_8238A900:
	// cmpw cr6,r8,r30
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r30.s32, ctx.xer);
	// bge cr6,0x8238a954
	if (!ctx.cr6.lt) goto loc_8238A954;
loc_8238A908:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
	// bctrl 
	ctx.lr = 0x8238A914;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,5212(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5212);
	// lwz r10,4836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4836);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,5212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5212, ctx.r11.u32);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8238a93c
	if (ctx.cr6.lt) goto loc_8238A93C;
	// lwz r11,5208(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5208);
	// stw r28,5212(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5212, ctx.r28.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,5208(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5208, ctx.r11.u32);
loc_8238A93C:
	// lwz r11,5204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 5204);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rotlwi r10,r11,0
	ctx.r10.u64 = rotl32(ctx.r11.u32, 0);
	// stw r11,5204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 5204, ctx.r11.u32);
	// cmpw cr6,r10,r30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r30.s32, ctx.xer);
	// blt cr6,0x8238a908
	if (ctx.cr6.lt) goto loc_8238A908;
loc_8238A954:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x8233e4b8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8238A95C"))) PPC_WEAK_FUNC(sub_8238A95C);
PPC_FUNC_IMPL(__imp__sub_8238A95C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

