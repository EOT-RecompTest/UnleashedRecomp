#include "ppc_recomp_shared.h"

__attribute__((alias("__imp__sub_8233D4F4"))) PPC_WEAK_FUNC(sub_8233D4F4);
PPC_FUNC_IMPL(__imp__sub_8233D4F4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233D4F8"))) PPC_WEAK_FUNC(sub_8233D4F8);
PPC_FUNC_IMPL(__imp__sub_8233D4F8) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32198
	ctx.r11.s64 = -2110128128;
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// stfd f2,24(r1)
	PPC_STORE_U64(ctx.r1.u32 + 24, ctx.f2.u64);
	// addi r11,r11,-20736
	ctx.r11.s64 = ctx.r11.s64 + -20736;
	// lfs f0,168(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f2,f0
	ctx.cr6.compare(ctx.f2.f64, ctx.f0.f64);
	// bne cr6,0x8233d550
	if (!ctx.cr6.eq) goto loc_8233D550;
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bne cr6,0x8233d548
	if (!ctx.cr6.eq) goto loc_8233D548;
	// lwz r10,24(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 24);
	// rlwinm. r10,r10,0,0,0
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// lwz r10,16(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 16);
	// rlwinm. r10,r10,0,0,0
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8233d540
	if (ctx.cr0.eq) goto loc_8233D540;
	// lfd f0,16(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 16);
	// fneg f1,f0
	ctx.f1.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// blr 
	return;
loc_8233D540:
	// lfd f1,16(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r11.u32 + 16);
	// blr 
	return;
loc_8233D548:
	// lfd f0,8(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 8);
	// b 0x8233d608
	goto loc_8233D608;
loc_8233D550:
	// fabs f13,f2
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = ctx.f2.u64 & 0x7FFFFFFFFFFFFFFF;
	// li r10,0
	ctx.r10.s64 = 0;
	// fabs f0,f1
	ctx.f0.u64 = ctx.f1.u64 & 0x7FFFFFFFFFFFFFFF;
	// fmr f12,f13
	ctx.f12.f64 = ctx.f13.f64;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8233d574
	if (!ctx.cr6.gt) goto loc_8233D574;
	// fmr f12,f0
	ctx.f12.f64 = ctx.f0.f64;
	// li r10,2
	ctx.r10.s64 = 2;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_8233D574:
	// fdiv f0,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f0.f64 / ctx.f12.f64;
	// lfd f13,24(r11)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r11.u32 + 24);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8233d59c
	if (!ctx.cr6.gt) goto loc_8233D59C;
	// lfd f13,40(r11)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r11.u32 + 40);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lfs f12,176(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 176);
	ctx.f12.f64 = double(temp.f32);
	// fadd f11,f13,f0
	ctx.f11.f64 = ctx.f13.f64 + ctx.f0.f64;
	// fmsub f0,f13,f0,f12
	ctx.f0.f64 = ctx.f13.f64 * ctx.f0.f64 - ctx.f12.f64;
	// fdiv f0,f0,f11
	ctx.f0.f64 = ctx.f0.f64 / ctx.f11.f64;
loc_8233D59C:
	// fmul f5,f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = ctx.f0.f64 * ctx.f0.f64;
	// lfd f12,72(r11)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r11.u32 + 72);
	// lfd f13,80(r11)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r11.u32 + 80);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// lfd f11,112(r11)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r11.u32 + 112);
	// lfd f10,64(r11)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r11.u32 + 64);
	// lfd f9,104(r11)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r11.u32 + 104);
	// lfd f8,56(r11)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r11.u32 + 56);
	// lfd f7,96(r11)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r11.u32 + 96);
	// lfd f6,88(r11)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r11.u32 + 88);
	// fmadd f13,f13,f5,f12
	ctx.f13.f64 = ctx.f13.f64 * ctx.f5.f64 + ctx.f12.f64;
	// fadd f12,f11,f5
	ctx.f12.f64 = ctx.f11.f64 + ctx.f5.f64;
	// fmadd f13,f13,f5,f10
	ctx.f13.f64 = ctx.f13.f64 * ctx.f5.f64 + ctx.f10.f64;
	// fmadd f12,f12,f5,f9
	ctx.f12.f64 = ctx.f12.f64 * ctx.f5.f64 + ctx.f9.f64;
	// fmadd f13,f13,f5,f8
	ctx.f13.f64 = ctx.f13.f64 * ctx.f5.f64 + ctx.f8.f64;
	// fmadd f12,f12,f5,f7
	ctx.f12.f64 = ctx.f12.f64 * ctx.f5.f64 + ctx.f7.f64;
	// fmul f13,f13,f5
	ctx.f13.f64 = ctx.f13.f64 * ctx.f5.f64;
	// fmadd f12,f12,f5,f6
	ctx.f12.f64 = ctx.f12.f64 * ctx.f5.f64 + ctx.f6.f64;
	// fmul f13,f13,f0
	ctx.f13.f64 = ctx.f13.f64 * ctx.f0.f64;
	// fdiv f13,f13,f12
	ctx.f13.f64 = ctx.f13.f64 / ctx.f12.f64;
	// fadd f0,f13,f0
	ctx.f0.f64 = ctx.f13.f64 + ctx.f0.f64;
	// ble cr6,0x8233d5f8
	if (!ctx.cr6.gt) goto loc_8233D5F8;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_8233D5F8:
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// lfdx f13,r10,r9
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r10.u32 + ctx.r9.u32);
	// fadd f0,f13,f0
	ctx.f0.f64 = ctx.f13.f64 + ctx.f0.f64;
loc_8233D608:
	// lfd f13,16(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r11.u32 + 16);
	// lwz r11,16(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 16);
	// fsub f13,f13,f0
	ctx.f13.f64 = ctx.f13.f64 - ctx.f0.f64;
	// rlwinm. r11,r11,0,0,0
	ctx.r11.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// fsel f1,f2,f0,f13
	ctx.f1.f64 = ctx.f2.f64 >= 0.0 ? ctx.f0.f64 : ctx.f13.f64;
	// beqlr 
	if (ctx.cr0.eq) return;
	// fneg f1,f1
	ctx.f1.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233D628"))) PPC_WEAK_FUNC(sub_8233D628);
PPC_FUNC_IMPL(__imp__sub_8233D628) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32198
	ctx.r11.s64 = -2110128128;
	// addi r11,r11,-20552
	ctx.r11.s64 = ctx.r11.s64 + -20552;
	// lfd f0,32(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 32);
	// fmul f5,f0,f1
	ctx.f5.f64 = ctx.f0.f64 * ctx.f1.f64;
	// lfd f13,40(r11)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r11.u32 + 40);
	// lfd f12,48(r11)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r11.u32 + 48);
	// lfd f10,64(r11)
	ctx.f10.u64 = PPC_LOAD_U64(ctx.r11.u32 + 64);
	// lfd f11,72(r11)
	ctx.f11.u64 = PPC_LOAD_U64(ctx.r11.u32 + 72);
	// lfd f9,96(r11)
	ctx.f9.u64 = PPC_LOAD_U64(ctx.r11.u32 + 96);
	// lfd f8,88(r11)
	ctx.f8.u64 = PPC_LOAD_U64(ctx.r11.u32 + 88);
	// lfd f7,56(r11)
	ctx.f7.u64 = PPC_LOAD_U64(ctx.r11.u32 + 56);
	// lfd f6,80(r11)
	ctx.f6.u64 = PPC_LOAD_U64(ctx.r11.u32 + 80);
	// lfs f0,108(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// fctid f5,f5
	ctx.f5.s64 = (ctx.f5.f64 > double(LLONG_MAX)) ? LLONG_MAX : simd::convert_f64_to_i64(ctx.f5.f64);
	// fcfid f5,f5
	ctx.f5.f64 = double(ctx.f5.s64);
	// fnmsub f13,f13,f5,f1
	ctx.f13.f64 = -(ctx.f13.f64 * ctx.f5.f64 - ctx.f1.f64);
	// fctiwz f4,f5
	ctx.f4.u64 = uint64_t(int32_t(std::trunc(ctx.f5.f64)));
	// stfd f4,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f4.u64);
	// lwz r10,-12(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + -12);
	// addic. r10,r10,1
	ctx.xer.ca = ctx.r10.u32 > 4294967294;
	ctx.r10.s64 = ctx.r10.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// fnmsub f13,f12,f5,f13
	ctx.f13.f64 = -(ctx.f12.f64 * ctx.f5.f64 - ctx.f13.f64);
	// fmul f12,f13,f13
	ctx.f12.f64 = ctx.f13.f64 * ctx.f13.f64;
	// fmadd f11,f11,f12,f10
	ctx.f11.f64 = ctx.f11.f64 * ctx.f12.f64 + ctx.f10.f64;
	// fmadd f10,f9,f12,f8
	ctx.f10.f64 = ctx.f9.f64 * ctx.f12.f64 + ctx.f8.f64;
	// fmadd f11,f11,f12,f7
	ctx.f11.f64 = ctx.f11.f64 * ctx.f12.f64 + ctx.f7.f64;
	// fmadd f12,f10,f12,f6
	ctx.f12.f64 = ctx.f10.f64 * ctx.f12.f64 + ctx.f6.f64;
	// fmul f13,f11,f13
	ctx.f13.f64 = ctx.f11.f64 * ctx.f13.f64;
	// fsub f12,f12,f13
	ctx.f12.f64 = ctx.f12.f64 - ctx.f13.f64;
	// fdiv f13,f13,f12
	ctx.f13.f64 = ctx.f13.f64 / ctx.f12.f64;
	// fadd f0,f13,f0
	ctx.f0.f64 = ctx.f13.f64 + ctx.f0.f64;
	// beq 0x8233d6e0
	if (ctx.cr0.eq) goto loc_8233D6E0;
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lhz r8,-16(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + -16);
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// lhz r9,-16(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + -16);
	// andi. r8,r8,32783
	ctx.r8.u64 = ctx.r8.u64 & 32783;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stfd f0,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.f0.u64);
	// rlwinm r9,r9,28,21,31
	ctx.r9.u64 = rotl64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0x7FF;
	// addi r9,r9,-1022
	ctx.r9.s64 = ctx.r9.s64 + -1022;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,1022
	ctx.r10.s64 = ctx.r10.s64 + 1022;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// or r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 | ctx.r8.u64;
	// sth r10,-16(r1)
	PPC_STORE_U16(ctx.r1.u32 + -16, ctx.r10.u16);
	// lfd f0,-16(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
loc_8233D6E0:
	// lfd f13,0(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r11.u32 + 0);
	// fsub f11,f1,f13
	ctx.f11.f64 = ctx.f1.f64 - ctx.f13.f64;
	// lfd f13,8(r11)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r11.u32 + 8);
	// lfd f12,16(r11)
	ctx.f12.u64 = PPC_LOAD_U64(ctx.r11.u32 + 16);
	// fsub f10,f13,f1
	ctx.f10.f64 = ctx.f13.f64 - ctx.f1.f64;
	// lfs f13,104(r11)
	temp.u32 = PPC_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f13.f64 = double(temp.f32);
	// fsel f0,f11,f12,f0
	ctx.f0.f64 = ctx.f11.f64 >= 0.0 ? ctx.f12.f64 : ctx.f0.f64;
	// fsel f1,f10,f13,f0
	ctx.f1.f64 = ctx.f10.f64 >= 0.0 ? ctx.f13.f64 : ctx.f0.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233D704"))) PPC_WEAK_FUNC(sub_8233D704);
PPC_FUNC_IMPL(__imp__sub_8233D704) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233D708"))) PPC_WEAK_FUNC(sub_8233D708);
PPC_FUNC_IMPL(__imp__sub_8233D708) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8233d728
	if (ctx.cr6.eq) goto loc_8233D728;
	// lbz r11,0(r3)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8233d728
	if (ctx.cr0.eq) goto loc_8233D728;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bnelr cr6
	if (!ctx.cr6.eq) return;
loc_8233D728:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233D730"))) PPC_WEAK_FUNC(sub_8233D730);
PPC_FUNC_IMPL(__imp__sub_8233D730) {
	PPC_FUNC_PROLOGUE();
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x8233d74c
	if (ctx.cr6.eq) goto loc_8233D74C;
	// li r10,45
	ctx.r10.s64 = 45;
	// addi r11,r4,1
	ctx.r11.s64 = ctx.r4.s64 + 1;
	// stb r10,0(r4)
	PPC_STORE_U8(ctx.r4.u32 + 0, ctx.r10.u8);
	// neg r3,r3
	ctx.r3.s64 = -ctx.r3.s64;
loc_8233D74C:
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_8233D750:
	// divwu r10,r3,r5
	ctx.r10.u32 = ctx.r3.u32 / ctx.r5.u32;
	// twllei r5,0
	if (ctx.r5.u32 <= 0) __builtin_debugtrap();
	// mullw r10,r10,r5
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r5.s32);
	// subf r10,r10,r3
	ctx.r10.s64 = ctx.r3.s64 - ctx.r10.s64;
	// divwu r3,r3,r5
	ctx.r3.u32 = ctx.r3.u32 / ctx.r5.u32;
	// twllei r5,0
	if (ctx.r5.u32 <= 0) __builtin_debugtrap();
	// cmplwi cr6,r10,9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 9, ctx.xer);
	// ble cr6,0x8233d77c
	if (!ctx.cr6.gt) goto loc_8233D77C;
	// addi r10,r10,87
	ctx.r10.s64 = ctx.r10.s64 + 87;
	// extsb r10,r10
	ctx.r10.s64 = ctx.r10.s8;
	// b 0x8233d780
	goto loc_8233D780;
loc_8233D77C:
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
loc_8233D780:
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8233d750
	if (!ctx.cr6.eq) goto loc_8233D750;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_8233D79C:
	// lbz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// stb r10,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r8,0(r9)
	PPC_STORE_U8(ctx.r9.u32 + 0, ctx.r8.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8233d79c
	if (ctx.cr6.lt) goto loc_8233D79C;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233D7C0"))) PPC_WEAK_FUNC(sub_8233D7C0);
PPC_FUNC_IMPL(__imp__sub_8233D7C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r5,10
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 10, ctx.xer);
	// bne cr6,0x8233d7e4
	if (!ctx.cr6.eq) goto loc_8233D7E4;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x8233d7e4
	if (!ctx.cr6.lt) goto loc_8233D7E4;
	// li r6,1
	ctx.r6.s64 = 1;
	// b 0x8233d7e8
	goto loc_8233D7E8;
loc_8233D7E4:
	// li r6,0
	ctx.r6.s64 = 0;
loc_8233D7E8:
	// bl 0x8233d730
	ctx.lr = 0x8233D7EC;
	sub_8233D730(ctx, base);
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233D800"))) PPC_WEAK_FUNC(sub_8233D800);
PPC_FUNC_IMPL(__imp__sub_8233D800) {
	PPC_FUNC_PROLOGUE();
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8233d82c
	if (ctx.cr6.eq) goto loc_8233D82C;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8233d82c
	if (ctx.cr6.eq) goto loc_8233D82C;
	// lbz r11,0(r4)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8233d834
	if (!ctx.cr0.eq) goto loc_8233D834;
	// beq cr6,0x8233d82c
	if (ctx.cr6.eq) goto loc_8233D82C;
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
loc_8233D82C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8233D834:
	// beq cr6,0x8233d840
	if (ctx.cr6.eq) goto loc_8233D840;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// sth r11,0(r3)
	PPC_STORE_U16(ctx.r3.u32 + 0, ctx.r11.u16);
loc_8233D840:
	// li r3,1
	ctx.r3.s64 = 1;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233D848"))) PPC_WEAK_FUNC(sub_8233D848);
PPC_FUNC_IMPL(__imp__sub_8233D848) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233D84C"))) PPC_WEAK_FUNC(sub_8233D84C);
PPC_FUNC_IMPL(__imp__sub_8233D84C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233D850"))) PPC_WEAK_FUNC(sub_8233D850);
PPC_FUNC_IMPL(__imp__sub_8233D850) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e464
	ctx.lr = 0x8233D858;
	__restfpr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8233d884
	if (ctx.cr6.eq) goto loc_8233D884;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8233db14
	if (ctx.cr6.eq) goto loc_8233DB14;
loc_8233D884:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8233d8a0
	if (!ctx.cr6.eq) goto loc_8233D8A0;
	// bl 0x82342a98
	ctx.lr = 0x8233D890;
	sub_82342A98(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82342bf0
	ctx.lr = 0x8233D89C;
	sub_82342BF0(ctx, base);
	// b 0x8233db10
	goto loc_8233DB10;
loc_8233D8A0:
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x8233da84
	if (ctx.cr6.eq) goto loc_8233DA84;
	// lis r27,-32198
	ctx.r27.s64 = -2110128128;
	// lwz r9,-18752(r27)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r27.u32 + -18752);
	// lwz r11,20(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8233d8f4
	if (!ctx.cr6.eq) goto loc_8233D8F4;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8233db14
	if (ctx.cr6.eq) goto loc_8233DB14;
	// addi r11,r31,-2
	ctx.r11.s64 = ctx.r31.s64 + -2;
loc_8233D8C8:
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// bgt cr6,0x8233db00
	if (ctx.cr6.gt) goto loc_8233DB00;
	// stbx r10,r3,r28
	PPC_STORE_U8(ctx.r3.u32 + ctx.r28.u32, ctx.r10.u8);
	// lhzu r10,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r10.u64 = PPC_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8233db14
	if (ctx.cr0.eq) goto loc_8233DB14;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// cmplw cr6,r3,r29
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x8233d8c8
	if (ctx.cr6.lt) goto loc_8233D8C8;
	// b 0x8233db14
	goto loc_8233DB14;
loc_8233D8F4:
	// lwz r11,172(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 172);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8233d994
	if (!ctx.cr6.eq) goto loc_8233D994;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8233d948
	if (ctx.cr6.eq) goto loc_8233D948;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
loc_8233D910:
	// lhz r8,0(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x8233d928
	if (ctx.cr0.eq) goto loc_8233D928;
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bne 0x8233d910
	if (!ctx.cr0.eq) goto loc_8233D910;
loc_8233D928:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8233d948
	if (ctx.cr6.eq) goto loc_8233D948;
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8233d948
	if (!ctx.cr0.eq) goto loc_8233D948;
	// subf r11,r31,r11
	ctx.r11.s64 = ctx.r11.s64 - ctx.r31.s64;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// addi r29,r11,1
	ctx.r29.s64 = ctx.r11.s64 + 1;
loc_8233D948:
	// lwz r3,4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8237b248
	ctx.lr = 0x8233D96C;
	sub_8237B248(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8233db00
	if (ctx.cr0.eq) goto loc_8233DB00;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8233db00
	if (!ctx.cr6.eq) goto loc_8233DB00;
	// add r11,r3,r28
	ctx.r11.u64 = ctx.r3.u64 + ctx.r28.u64;
	// lbz r11,-1(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + -1);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8233db14
	if (!ctx.cr0.eq) goto loc_8233DB14;
	// b 0x8233daf8
	goto loc_8233DAF8;
loc_8233D994:
	// lwz r3,4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,0
	ctx.r9.s64 = 0;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// li r6,-1
	ctx.r6.s64 = -1;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8237b248
	ctx.lr = 0x8233D9B8;
	sub_8237B248(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8233db00
	if (!ctx.cr6.eq) goto loc_8233DB00;
	// beq 0x8233d9d4
	if (ctx.cr0.eq) goto loc_8233D9D4;
	// addi r3,r30,-1
	ctx.r3.s64 = ctx.r30.s64 + -1;
	// b 0x8233db14
	goto loc_8233DB14;
loc_8233D9D4:
	// bl 0x822471d0
	ctx.lr = 0x8233D9D8;
	sub_822471D0(ctx, base);
	// cmplwi cr6,r3,122
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 122, ctx.xer);
	// bne cr6,0x8233db00
	if (!ctx.cr6.eq) goto loc_8233DB00;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8233da7c
	if (ctx.cr6.eq) goto loc_8233DA7C;
loc_8233D9E8:
	// lwz r11,-18752(r27)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + -18752);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r7,r1,84
	ctx.r7.s64 = ctx.r1.s64 + 84;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r8,172(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 172);
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8237b248
	ctx.lr = 0x8233DA10;
	sub_8237B248(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8233db00
	if (ctx.cr0.eq) goto loc_8233DB00;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8233db00
	if (!ctx.cr6.eq) goto loc_8233DB00;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8233db00
	if (ctx.cr6.lt) goto loc_8233DB00;
	// cmplwi cr6,r3,5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 5, ctx.xer);
	// bgt cr6,0x8233db00
	if (ctx.cr6.gt) goto loc_8233DB00;
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bgt cr6,0x8233da7c
	if (ctx.cr6.gt) goto loc_8233DA7C;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x8233da70
	if (!ctx.cr6.gt) goto loc_8233DA70;
loc_8233DA4C:
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// lbzx r10,r11,r10
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stbx r10,r30,r28
	PPC_STORE_U8(ctx.r30.u32 + ctx.r28.u32, ctx.r10.u8);
	// beq 0x8233da7c
	if (ctx.cr0.eq) goto loc_8233DA7C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpw cr6,r11,r3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r3.s32, ctx.xer);
	// blt cr6,0x8233da4c
	if (ctx.cr6.lt) goto loc_8233DA4C;
loc_8233DA70:
	// addi r31,r31,2
	ctx.r31.s64 = ctx.r31.s64 + 2;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x8233d9e8
	if (ctx.cr6.lt) goto loc_8233D9E8;
loc_8233DA7C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// b 0x8233db14
	goto loc_8233DB14;
loc_8233DA84:
	// lis r11,-32198
	ctx.r11.s64 = -2110128128;
	// lwz r11,-18752(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + -18752);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8233dac0
	if (!ctx.cr6.eq) goto loc_8233DAC0;
	// lhz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8233dab4
	goto loc_8233DAB4;
loc_8233DAA4:
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bgt cr6,0x8233db00
	if (ctx.cr6.gt) goto loc_8233DB00;
	// lhzu r11,2(r31)
	ea = 2 + ctx.r31.u32;
	ctx.r11.u64 = PPC_LOAD_U16(ea);
	ctx.r31.u32 = ea;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
loc_8233DAB4:
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8233daa4
	if (!ctx.cr0.eq) goto loc_8233DAA4;
	// b 0x8233db14
	goto loc_8233DB14;
loc_8233DAC0:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r3,4(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,-1
	ctx.r6.s64 = -1;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8237b248
	ctx.lr = 0x8233DAE4;
	sub_8237B248(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8233db00
	if (ctx.cr0.eq) goto loc_8233DB00;
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8233db00
	if (!ctx.cr6.eq) goto loc_8233DB00;
loc_8233DAF8:
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// b 0x8233db14
	goto loc_8233DB14;
loc_8233DB00:
	// bl 0x82342a98
	ctx.lr = 0x8233DB04;
	sub_82342A98(ctx, base);
	// li r10,42
	ctx.r10.s64 = 42;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stw r10,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
loc_8233DB10:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8233DB14:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8233e4b4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233DB1C"))) PPC_WEAK_FUNC(sub_8233DB1C);
PPC_FUNC_IMPL(__imp__sub_8233DB1C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233DB20"))) PPC_WEAK_FUNC(sub_8233DB20);
PPC_FUNC_IMPL(__imp__sub_8233DB20) {
	PPC_FUNC_PROLOGUE();
	// li r6,0
	ctx.r6.s64 = 0;
	// b 0x8233d850
	sub_8233D850(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233DB28"))) PPC_WEAK_FUNC(sub_8233DB28);
PPC_FUNC_IMPL(__imp__sub_8233DB28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e460
	ctx.lr = 0x8233DB30;
	__restfpr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// mr r27,r28
	ctx.r27.u64 = ctx.r28.u64;
	// beq cr6,0x8233dbc4
	if (ctx.cr6.eq) goto loc_8233DBC4;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x8233dbcc
	if (ctx.cr6.eq) goto loc_8233DBCC;
loc_8233DB60:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8233db6c
	if (ctx.cr6.eq) goto loc_8233DB6C;
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
loc_8233DB6C:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x8233db78
	if (ctx.cr6.eq) goto loc_8233DB78;
	// stw r28,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r28.u32);
loc_8233DB78:
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bgt cr6,0x8233db88
	if (ctx.cr6.gt) goto loc_8233DB88;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
loc_8233DB88:
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8233dbcc
	if (ctx.cr6.gt) goto loc_8233DBCC;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8233d850
	ctx.lr = 0x8233DBA4;
	sub_8233D850(ctx, base);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8233dbe4
	if (!ctx.cr6.eq) goto loc_8233DBE4;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8233dbb8
	if (ctx.cr6.eq) goto loc_8233DBB8;
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
loc_8233DBB8:
	// bl 0x82342a98
	ctx.lr = 0x8233DBBC;
	sub_82342A98(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 0);
	// b 0x8233dc44
	goto loc_8233DC44;
loc_8233DBC4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8233db60
	if (ctx.cr6.eq) goto loc_8233DB60;
loc_8233DBCC:
	// bl 0x82342a98
	ctx.lr = 0x8233DBD0;
	sub_82342A98(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82342bf0
	ctx.lr = 0x8233DBDC;
	sub_82342BF0(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x8233dc44
	goto loc_8233DC44;
loc_8233DBE4:
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8233dc34
	if (ctx.cr6.eq) goto loc_8233DC34;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// ble cr6,0x8233dc2c
	if (!ctx.cr6.gt) goto loc_8233DC2C;
	// cmpwi cr6,r29,-1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, -1, ctx.xer);
	// beq cr6,0x8233dc24
	if (ctx.cr6.eq) goto loc_8233DC24;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// stb r28,0(r31)
	PPC_STORE_U8(ctx.r31.u32 + 0, ctx.r28.u8);
	// bgt cr6,0x8233dc24
	if (ctx.cr6.gt) goto loc_8233DC24;
	// bl 0x82342a98
	ctx.lr = 0x8233DC10;
	sub_82342A98(ctx, base);
	// li r11,34
	ctx.r11.s64 = 34;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82342bf0
	ctx.lr = 0x8233DC1C;
	sub_82342BF0(ctx, base);
	// li r3,34
	ctx.r3.s64 = 34;
	// b 0x8233dc44
	goto loc_8233DC44;
loc_8233DC24:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// li r27,80
	ctx.r27.s64 = 80;
loc_8233DC2C:
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stb r28,-1(r10)
	PPC_STORE_U8(ctx.r10.u32 + -1, ctx.r28.u8);
loc_8233DC34:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x8233dc40
	if (ctx.cr6.eq) goto loc_8233DC40;
	// stw r11,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
loc_8233DC40:
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
loc_8233DC44:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x8233e4b0
	__restgprlr_26(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233DC4C"))) PPC_WEAK_FUNC(sub_8233DC4C);
PPC_FUNC_IMPL(__imp__sub_8233DC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233DC50"))) PPC_WEAK_FUNC(sub_8233DC50);
PPC_FUNC_IMPL(__imp__sub_8233DC50) {
	PPC_FUNC_PROLOGUE();
	// li r8,0
	ctx.r8.s64 = 0;
	// b 0x8233db28
	sub_8233DB28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233DC58"))) PPC_WEAK_FUNC(sub_8233DC58);
PPC_FUNC_IMPL(__imp__sub_8233DC58) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233DC5C"))) PPC_WEAK_FUNC(sub_8233DC5C);
PPC_FUNC_IMPL(__imp__sub_8233DC5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233DC60"))) PPC_WEAK_FUNC(sub_8233DC60);
PPC_FUNC_IMPL(__imp__sub_8233DC60) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mr. r0,r5
	ctx.r0.u64 = ctx.r5.u64;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
	// ble 0x8233dca4
	if (!ctx.cr0.gt) goto loc_8233DCA4;
	// lbz r8,0(r3)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// lbz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmpwi cr1,r8,0
	ctx.cr1.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// subfc. r3,r7,r8
	ctx.xer.ca = ctx.r8.u32 >= ctx.r7.u32;
	ctx.r3.s64 = ctx.r8.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bdnzf 4*cr1+eq,0x8233dc88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0 && !ctx.cr1.eq) goto loc_8233DC88;
	// blr 
	return;
loc_8233DC88:
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lbzu r8,1(r10)
	ea = 1 + ctx.r10.u32;
	ctx.r8.u64 = PPC_LOAD_U8(ea);
	ctx.r10.u32 = ea;
	// lbzu r7,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// cmpwi cr1,r8,0
	ctx.cr1.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// subfc. r3,r7,r8
	ctx.xer.ca = ctx.r8.u32 >= ctx.r7.u32;
	ctx.r3.s64 = ctx.r8.s64 - ctx.r7.s64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bdnzf 4*cr1+eq,0x8233dc88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0 && !ctx.cr1.eq) goto loc_8233DC88;
	// blr 
	return;
loc_8233DCA4:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233DCAC"))) PPC_WEAK_FUNC(sub_8233DCAC);
PPC_FUNC_IMPL(__imp__sub_8233DCAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233DCB0"))) PPC_WEAK_FUNC(sub_8233DCB0);
PPC_FUNC_IMPL(__imp__sub_8233DCB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e468
	ctx.lr = 0x8233DCB8;
	__restfpr_28(ctx, base);
	// std r6,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// std r7,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// std r8,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// std r9,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// std r10,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r5,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r5.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r28,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// bl 0x8233eaf0
	ctx.lr = 0x8233DCF8;
	sub_8233EAF0(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x8233dd18
	if (!ctx.cr6.eq) goto loc_8233DD18;
loc_8233DD00:
	// bl 0x82342a98
	ctx.lr = 0x8233DD04;
	sub_82342A98(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82342bf0
	ctx.lr = 0x8233DD10;
	sub_82342BF0(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8233dda8
	goto loc_8233DDA8;
loc_8233DD18:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8233dd28
	if (ctx.cr6.eq) goto loc_8233DD28;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8233dd00
	if (ctx.cr6.eq) goto loc_8233DD00;
loc_8233DD28:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// addi r9,r1,216
	ctx.r9.s64 = ctx.r1.s64 + 216;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// bgt cr6,0x8233dd4c
	if (ctx.cr6.gt) goto loc_8233DD4C;
	// stw r30,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
loc_8233DD4C:
	// li r11,66
	ctx.r11.s64 = 66;
	// stw r31,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// stw r31,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r31.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r6,80(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82343398
	ctx.lr = 0x8233DD70;
	sub_82343398(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8233dda4
	if (ctx.cr6.eq) goto loc_8233DDA4;
	// lwz r11,100(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// blt 0x8233dd98
	if (ctx.cr0.lt) goto loc_8233DD98;
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// stb r28,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// b 0x8233dda4
	goto loc_8233DDA4;
loc_8233DD98:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823440c0
	ctx.lr = 0x8233DDA4;
	sub_823440C0(ctx, base);
loc_8233DDA4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8233DDA8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x8233e4b8
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233DDB0"))) PPC_WEAK_FUNC(sub_8233DDB0);
PPC_FUNC_IMPL(__imp__sub_8233DDB0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e450
	ctx.lr = 0x8233DDB8;
	__restfpr_22(ctx, base);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8233ddec
	if (!ctx.cr6.eq) goto loc_8233DDEC;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8233ddec
	if (ctx.cr6.eq) goto loc_8233DDEC;
loc_8233DDD4:
	// bl 0x82342a98
	ctx.lr = 0x8233DDD8;
	sub_82342A98(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82342bf0
	ctx.lr = 0x8233DDE4;
	sub_82342BF0(ctx, base);
loc_8233DDE4:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x8233e4a0
	__restgprlr_22(ctx, base);
	return;
loc_8233DDEC:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8233ddd4
	if (ctx.cr6.eq) goto loc_8233DDD4;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x8233ddd4
	if (ctx.cr6.eq) goto loc_8233DDD4;
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// blt cr6,0x8233dde4
	if (ctx.cr6.lt) goto loc_8233DDE4;
	// addi r11,r4,-1
	ctx.r11.s64 = ctx.r4.s64 + -1;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mullw r11,r11,r27
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// li r22,0
	ctx.r22.s64 = 0;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// add r28,r11,r3
	ctx.r28.u64 = ctx.r11.u64 + ctx.r3.u64;
	// addi r23,r10,-4
	ctx.r23.s64 = ctx.r10.s64 + -4;
	// addi r24,r9,-4
	ctx.r24.s64 = ctx.r9.s64 + -4;
loc_8233DE28:
	// subf r11,r26,r28
	ctx.r11.s64 = ctx.r28.s64 - ctx.r26.s64;
	// twllei r27,0
	if (ctx.r27.u32 <= 0) __builtin_debugtrap();
	// divwu r11,r11,r27
	ctx.r11.u32 = ctx.r11.u32 / ctx.r27.u32;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bgt cr6,0x8233dedc
	if (ctx.cr6.gt) goto loc_8233DEDC;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// cmplw cr6,r28,r26
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r26.u32, ctx.xer);
	// ble cr6,0x8233dec0
	if (!ctx.cr6.gt) goto loc_8233DEC0;
	// add r28,r26,r27
	ctx.r28.u64 = ctx.r26.u64 + ctx.r27.u64;
loc_8233DE50:
	// mr r29,r26
	ctx.r29.u64 = ctx.r26.u64;
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// cmplw cr6,r28,r30
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r30.u32, ctx.xer);
	// bgt cr6,0x8233de88
	if (ctx.cr6.gt) goto loc_8233DE88;
loc_8233DE60:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x8233DE70;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x8233de7c
	if (!ctx.cr6.gt) goto loc_8233DE7C;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
loc_8233DE7C:
	// add r31,r31,r27
	ctx.r31.u64 = ctx.r31.u64 + ctx.r27.u64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// ble cr6,0x8233de60
	if (!ctx.cr6.gt) goto loc_8233DE60;
loc_8233DE88:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x8233deb4
	if (ctx.cr6.eq) goto loc_8233DEB4;
	// subf r10,r30,r29
	ctx.r10.s64 = ctx.r29.s64 - ctx.r30.s64;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
loc_8233DE9C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u8);
	// stb r8,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x8233de9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233DE9C;
loc_8233DEB4:
	// subf r30,r27,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r27.s64;
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// bgt cr6,0x8233de50
	if (ctx.cr6.gt) goto loc_8233DE50;
loc_8233DEC0:
	// addic. r22,r22,-1
	ctx.xer.ca = ctx.r22.u32 > 0;
	ctx.r22.s64 = ctx.r22.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// addi r24,r24,-4
	ctx.r24.s64 = ctx.r24.s64 + -4;
	// addi r23,r23,-4
	ctx.r23.s64 = ctx.r23.s64 + -4;
	// blt 0x8233dde4
	if (ctx.cr0.lt) goto loc_8233DDE4;
	// lwz r26,4(r24)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r24.u32 + 4);
	// lwz r28,4(r23)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r23.u32 + 4);
	// b 0x8233de28
	goto loc_8233DE28;
loc_8233DEDC:
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mullw r11,r11,r27
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r27.s32);
	// add r29,r11,r26
	ctx.r29.u64 = ctx.r11.u64 + ctx.r26.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bctrl 
	ctx.lr = 0x8233DEF8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x8233df2c
	if (!ctx.cr6.gt) goto loc_8233DF2C;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// cmplw cr6,r26,r29
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r29.u32, ctx.xer);
	// beq cr6,0x8233df2c
	if (ctx.cr6.eq) goto loc_8233DF2C;
	// subf r10,r29,r26
	ctx.r10.s64 = ctx.r26.s64 - ctx.r29.s64;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
loc_8233DF14:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u8);
	// stb r8,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x8233df14
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233DF14;
loc_8233DF2C:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bctrl 
	ctx.lr = 0x8233DF3C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x8233df70
	if (!ctx.cr6.gt) goto loc_8233DF70;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// cmplw cr6,r26,r28
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8233df70
	if (ctx.cr6.eq) goto loc_8233DF70;
	// subf r10,r28,r26
	ctx.r10.s64 = ctx.r26.s64 - ctx.r28.s64;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
loc_8233DF58:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u8);
	// stb r8,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x8233df58
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233DF58;
loc_8233DF70:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bctrl 
	ctx.lr = 0x8233DF80;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x8233dfb4
	if (!ctx.cr6.gt) goto loc_8233DFB4;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// cmplw cr6,r29,r28
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x8233dfb4
	if (ctx.cr6.eq) goto loc_8233DFB4;
	// subf r10,r28,r29
	ctx.r10.s64 = ctx.r29.s64 - ctx.r28.s64;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
loc_8233DF9C:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u8);
	// stb r8,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x8233df9c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233DF9C;
loc_8233DFB4:
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_8233DFBC:
	// cmplw cr6,r29,r31
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r31.u32, ctx.xer);
	// ble cr6,0x8233dff0
	if (!ctx.cr6.gt) goto loc_8233DFF0;
loc_8233DFC4:
	// add r31,r31,r27
	ctx.r31.u64 = ctx.r31.u64 + ctx.r27.u64;
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x8233dff0
	if (!ctx.cr6.lt) goto loc_8233DFF0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x8233DFE0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x8233dfc4
	if (!ctx.cr6.gt) goto loc_8233DFC4;
	// cmplw cr6,r29,r31
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r31.u32, ctx.xer);
	// bgt cr6,0x8233e014
	if (ctx.cr6.gt) goto loc_8233E014;
loc_8233DFF0:
	// add r31,r31,r27
	ctx.r31.u64 = ctx.r31.u64 + ctx.r27.u64;
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// bgt cr6,0x8233e014
	if (ctx.cr6.gt) goto loc_8233E014;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bctrl 
	ctx.lr = 0x8233E00C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble cr6,0x8233dff0
	if (!ctx.cr6.gt) goto loc_8233DFF0;
loc_8233E014:
	// subf r30,r27,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r27.s64;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// ble cr6,0x8233e038
	if (!ctx.cr6.gt) goto loc_8233E038;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bctrl 
	ctx.lr = 0x8233E030;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bgt cr6,0x8233e014
	if (ctx.cr6.gt) goto loc_8233E014;
loc_8233E038:
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bgt cr6,0x8233e078
	if (ctx.cr6.gt) goto loc_8233E078;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// beq cr6,0x8233e068
	if (ctx.cr6.eq) goto loc_8233E068;
	// subf r10,r30,r31
	ctx.r10.s64 = ctx.r31.s64 - ctx.r30.s64;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
loc_8233E050:
	// lbz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lbzx r8,r10,r11
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r10.u32 + ctx.r11.u32);
	// stbx r9,r10,r11
	PPC_STORE_U8(ctx.r10.u32 + ctx.r11.u32, ctx.r9.u8);
	// stb r8,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r8.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x8233e050
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E050;
loc_8233E068:
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x8233dfbc
	if (!ctx.cr6.eq) goto loc_8233DFBC;
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// b 0x8233dfbc
	goto loc_8233DFBC;
loc_8233E078:
	// add r30,r30,r27
	ctx.r30.u64 = ctx.r30.u64 + ctx.r27.u64;
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8233e0b0
	if (!ctx.cr6.lt) goto loc_8233E0B0;
loc_8233E084:
	// subf r30,r27,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r27.s64;
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// ble cr6,0x8233e0b0
	if (!ctx.cr6.gt) goto loc_8233E0B0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bctrl 
	ctx.lr = 0x8233E0A0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8233e084
	if (ctx.cr6.eq) goto loc_8233E084;
	// cmplw cr6,r29,r30
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x8233e0d4
	if (ctx.cr6.lt) goto loc_8233E0D4;
loc_8233E0B0:
	// subf r30,r27,r30
	ctx.r30.s64 = ctx.r30.s64 - ctx.r27.s64;
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// ble cr6,0x8233e0d4
	if (!ctx.cr6.gt) goto loc_8233E0D4;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bctrl 
	ctx.lr = 0x8233E0CC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x8233e0b0
	if (ctx.cr6.eq) goto loc_8233E0B0;
loc_8233E0D4:
	// subf r11,r31,r28
	ctx.r11.s64 = ctx.r28.s64 - ctx.r31.s64;
	// subf r10,r26,r30
	ctx.r10.s64 = ctx.r30.s64 - ctx.r26.s64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8233e110
	if (ctx.cr6.lt) goto loc_8233E110;
	// cmplw cr6,r26,r30
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8233e100
	if (!ctx.cr6.lt) goto loc_8233E100;
	// stw r26,4(r24)
	PPC_STORE_U32(ctx.r24.u32 + 4, ctx.r26.u32);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// stw r30,4(r23)
	PPC_STORE_U32(ctx.r23.u32 + 4, ctx.r30.u32);
	// addi r24,r24,4
	ctx.r24.s64 = ctx.r24.s64 + 4;
	// addi r23,r23,4
	ctx.r23.s64 = ctx.r23.s64 + 4;
loc_8233E100:
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// bge cr6,0x8233dec0
	if (!ctx.cr6.lt) goto loc_8233DEC0;
	// mr r26,r31
	ctx.r26.u64 = ctx.r31.u64;
	// b 0x8233de28
	goto loc_8233DE28;
loc_8233E110:
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// bge cr6,0x8233e124
	if (!ctx.cr6.lt) goto loc_8233E124;
	// stwu r31,4(r24)
	ea = 4 + ctx.r24.u32;
	PPC_STORE_U32(ea, ctx.r31.u32);
	ctx.r24.u32 = ea;
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// stwu r28,4(r23)
	ea = 4 + ctx.r23.u32;
	PPC_STORE_U32(ea, ctx.r28.u32);
	ctx.r23.u32 = ea;
loc_8233E124:
	// cmplw cr6,r26,r30
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x8233dec0
	if (!ctx.cr6.lt) goto loc_8233DEC0;
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// b 0x8233de28
	goto loc_8233DE28;
}

__attribute__((alias("__imp__sub_8233E134"))) PPC_WEAK_FUNC(sub_8233E134);
PPC_FUNC_IMPL(__imp__sub_8233E134) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233E138"))) PPC_WEAK_FUNC(sub_8233E138);
PPC_FUNC_IMPL(__imp__sub_8233E138) {
	PPC_FUNC_PROLOGUE();
	// cmpwi cr6,r3,97
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 97, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// cmpwi cr6,r3,122
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 122, ctx.xer);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// addi r3,r3,-32
	ctx.r3.s64 = ctx.r3.s64 + -32;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233E150"))) PPC_WEAK_FUNC(sub_8233E150);
PPC_FUNC_IMPL(__imp__sub_8233E150) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e464
	ctx.lr = 0x8233E158;
	__restfpr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,28
	ctx.r5.s64 = 28;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// bl 0x8233eaf0
	ctx.lr = 0x8233E188;
	sub_8233EAF0(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8233e1a8
	if (!ctx.cr6.eq) goto loc_8233E1A8;
loc_8233E190:
	// bl 0x82342a98
	ctx.lr = 0x8233E194;
	sub_82342A98(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82342bf0
	ctx.lr = 0x8233E1A0;
	sub_82342BF0(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x8233e210
	goto loc_8233E210;
loc_8233E1A8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8233e190
	if (ctx.cr6.eq) goto loc_8233E190;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_8233E1B4:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x8233e1b4
	if (!ctx.cr6.eq) goto loc_8233E1B4;
	// subf r10,r31,r11
	ctx.r10.s64 = ctx.r11.s64 - ctx.r31.s64;
	// stw r31,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r31.u32);
	// lis r11,32767
	ctx.r11.s64 = 2147418112;
	// stw r31,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// li r9,73
	ctx.r9.s64 = 73;
	// rotlwi r10,r10,0
	ctx.r10.u64 = rotl32(ctx.r10.u32, 0);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r9,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8233e1f8
	if (ctx.cr6.gt) goto loc_8233E1F8;
	// stw r10,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
loc_8233E1F8:
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bctrl 
	ctx.lr = 0x8233E210;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8233E210:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x8233e4b4
	__restgprlr_27(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233E218"))) PPC_WEAK_FUNC(sub_8233E218);
PPC_FUNC_IMPL(__imp__sub_8233E218) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r5,32(r1)
	PPC_STORE_U64(ctx.r1.u32 + 32, ctx.r5.u64);
	// std r6,40(r1)
	PPC_STORE_U64(ctx.r1.u32 + 40, ctx.r6.u64);
	// std r7,48(r1)
	PPC_STORE_U64(ctx.r1.u32 + 48, ctx.r7.u64);
	// std r8,56(r1)
	PPC_STORE_U64(ctx.r1.u32 + 56, ctx.r8.u64);
	// std r9,64(r1)
	PPC_STORE_U64(ctx.r1.u32 + 64, ctx.r9.u64);
	// std r10,72(r1)
	PPC_STORE_U64(ctx.r1.u32 + 72, ctx.r10.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r4.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lis r10,-32204
	ctx.r10.s64 = -2110521344;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// addi r3,r10,19928
	ctx.r3.s64 = ctx.r10.s64 + 19928;
	// lwz r7,80(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x8233e150
	ctx.lr = 0x8233E268;
	sub_8233E150(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233E278"))) PPC_WEAK_FUNC(sub_8233E278);
PPC_FUNC_IMPL(__imp__sub_8233E278) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233E27C"))) PPC_WEAK_FUNC(sub_8233E27C);
PPC_FUNC_IMPL(__imp__sub_8233E27C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233E280"))) PPC_WEAK_FUNC(sub_8233E280);
PPC_FUNC_IMPL(__imp__sub_8233E280) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// cmpwi cr7,r5,0
	ctx.cr7.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// cmpwi cr1,r5,1
	ctx.cr1.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// beq cr7,0x8233e2b4
	if (ctx.cr7.eq) goto loc_8233E2B4;
	// lbz r6,0(r3)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// cmpw cr6,r6,r4
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r4.s32, ctx.xer);
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// beq cr6,0x8233e2b8
	if (ctx.cr6.eq) goto loc_8233E2B8;
	// beq cr1,0x8233e2b4
	if (ctx.cr1.eq) goto loc_8233E2B4;
	// mtctr r5
	ctx.ctr.u64 = ctx.r5.u64;
loc_8233E2A4:
	// lbzu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// cmpw r6,r4
	ctx.cr0.compare<int32_t>(ctx.r6.s32, ctx.r4.s32, ctx.xer);
	// bdnzf eq,0x8233e2a4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0 && !ctx.cr0.eq) goto loc_8233E2A4;
	// beq 0x8233e2b8
	if (ctx.cr0.eq) goto loc_8233E2B8;
loc_8233E2B4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8233E2B8:
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233E2BC"))) PPC_WEAK_FUNC(sub_8233E2BC);
PPC_FUNC_IMPL(__imp__sub_8233E2BC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233E2C0"))) PPC_WEAK_FUNC(sub_8233E2C0);
PPC_FUNC_IMPL(__imp__sub_8233E2C0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lbz r5,0(r3)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r3.u32 + 0);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// cmpw r5,r4
	ctx.cr0.compare<int32_t>(ctx.r5.s32, ctx.r4.s32, ctx.xer);
	// beq cr6,0x8233e304
	if (ctx.cr6.eq) goto loc_8233E304;
	// li r3,0
	ctx.r3.s64 = 0;
	// beq 0x8233e2f0
	if (ctx.cr0.eq) goto loc_8233E2F0;
loc_8233E2DC:
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x8233e314
	if (ctx.cr6.eq) goto loc_8233E314;
	// lbzu r5,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r5.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// cmpw r4,r5
	ctx.cr0.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, ctx.xer);
	// bne 0x8233e2dc
	if (!ctx.cr0.eq) goto loc_8233E2DC;
loc_8233E2F0:
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lbzu r5,1(r9)
	ea = 1 + ctx.r9.u32;
	ctx.r5.u64 = PPC_LOAD_U8(ea);
	ctx.r9.u32 = ea;
	// cmpw r4,r5
	ctx.cr0.compare<int32_t>(ctx.r4.s32, ctx.r5.s32, ctx.xer);
	// beq 0x8233e2f0
	if (ctx.cr0.eq) goto loc_8233E2F0;
	// b 0x8233e2dc
	goto loc_8233E2DC;
loc_8233E304:
	// beq 0x8233e314
	if (ctx.cr0.eq) goto loc_8233E314;
	// lbzu r5,1(r3)
	ea = 1 + ctx.r3.u32;
	ctx.r5.u64 = PPC_LOAD_U8(ea);
	ctx.r3.u32 = ea;
	// cmpwi r5,0
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// b 0x8233e304
	goto loc_8233E304;
loc_8233E314:
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233E318"))) PPC_WEAK_FUNC(sub_8233E318);
PPC_FUNC_IMPL(__imp__sub_8233E318) {
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
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8233e338
	if (ctx.cr6.eq) goto loc_8233E338;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8233e350
	if (!ctx.cr6.eq) goto loc_8233E350;
loc_8233E338:
	// bl 0x82342a98
	ctx.lr = 0x8233E33C;
	sub_82342A98(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// stw r11,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82342bf0
	ctx.lr = 0x8233E348;
	sub_82342BF0(ctx, base);
	// li r3,22
	ctx.r3.s64 = 22;
	// b 0x8233e3b8
	goto loc_8233E3B8;
loc_8233E350:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x8233e378
	if (!ctx.cr6.eq) goto loc_8233E378;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// bl 0x82342a98
	ctx.lr = 0x8233E364;
	sub_82342A98(ctx, base);
	// li r31,22
	ctx.r31.s64 = 22;
loc_8233E368:
	// stw r31,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// bl 0x82342bf0
	ctx.lr = 0x8233E370;
	sub_82342BF0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x8233e3b8
	goto loc_8233E3B8;
loc_8233E378:
	// subf r11,r5,r3
	ctx.r11.s64 = ctx.r3.s64 - ctx.r5.s64;
loc_8233E37C:
	// lbz r10,0(r5)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stbx r10,r11,r5
	PPC_STORE_U8(ctx.r11.u32 + ctx.r5.u32, ctx.r10.u8);
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// beq 0x8233e398
	if (ctx.cr0.eq) goto loc_8233E398;
	// addic. r4,r4,-1
	ctx.xer.ca = ctx.r4.u32 > 0;
	ctx.r4.s64 = ctx.r4.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne 0x8233e37c
	if (!ctx.cr0.eq) goto loc_8233E37C;
loc_8233E398:
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8233e3b4
	if (!ctx.cr6.eq) goto loc_8233E3B4;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r3)
	PPC_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// bl 0x82342a98
	ctx.lr = 0x8233E3AC;
	sub_82342A98(ctx, base);
	// li r31,34
	ctx.r31.s64 = 34;
	// b 0x8233e368
	goto loc_8233E368;
loc_8233E3B4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8233E3B8:
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

__attribute__((alias("__imp__sub_8233E3CC"))) PPC_WEAK_FUNC(sub_8233E3CC);
PPC_FUNC_IMPL(__imp__sub_8233E3CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233E3D0"))) PPC_WEAK_FUNC(sub_8233E3D0);
PPC_FUNC_IMPL(__imp__sub_8233E3D0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32198
	ctx.r11.s64 = -2110128128;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-18968
	ctx.r11.s64 = ctx.r11.s64 + -18968;
	// lwz r11,200(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 200);
	// lhzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r11.u32);
	// rlwinm r3,r11,0,29,29
	ctx.r3.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233E3EC"))) PPC_WEAK_FUNC(sub_8233E3EC);
PPC_FUNC_IMPL(__imp__sub_8233E3EC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233E3F0"))) PPC_WEAK_FUNC(sub_8233E3F0);
PPC_FUNC_IMPL(__imp__sub_8233E3F0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32198
	ctx.r11.s64 = -2110128128;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-18968
	ctx.r11.s64 = ctx.r11.s64 + -18968;
	// lwz r11,200(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 200);
	// lhzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r11.u32);
	// rlwinm r3,r11,0,24,24
	ctx.r3.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233E40C"))) PPC_WEAK_FUNC(sub_8233E40C);
PPC_FUNC_IMPL(__imp__sub_8233E40C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233E410"))) PPC_WEAK_FUNC(sub_8233E410);
PPC_FUNC_IMPL(__imp__sub_8233E410) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32198
	ctx.r11.s64 = -2110128128;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = rotl64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-18968
	ctx.r11.s64 = ctx.r11.s64 + -18968;
	// lwz r11,200(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 200);
	// lhzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r11.u32);
	// rlwinm r3,r11,0,28,28
	ctx.r3.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233E42C"))) PPC_WEAK_FUNC(sub_8233E42C);
PPC_FUNC_IMPL(__imp__sub_8233E42C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp____restfpr_14"))) PPC_WEAK_FUNC(__restfpr_14);
PPC_FUNC_IMPL(__imp____restfpr_14) {
	PPC_FUNC_PROLOGUE();
	// std r14,-152(r1)
	PPC_STORE_U64(ctx.r1.u32 + -152, ctx.r14.u64);
	// std r15,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, ctx.r15.u64);
	// std r16,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, ctx.r16.u64);
	// std r17,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, ctx.r17.u64);
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, ctx.r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, ctx.r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_14"))) PPC_WEAK_FUNC(__restfpr_14);
PPC_FUNC_IMPL(__imp____restfpr_14) {
	PPC_FUNC_PROLOGUE();
	// std r14,-152(r1)
	PPC_STORE_U64(ctx.r1.u32 + -152, ctx.r14.u64);
	// std r15,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, ctx.r15.u64);
	// std r16,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, ctx.r16.u64);
	// std r17,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, ctx.r17.u64);
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, ctx.r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, ctx.r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_15"))) PPC_WEAK_FUNC(__restfpr_15);
PPC_FUNC_IMPL(__imp____restfpr_15) {
	PPC_FUNC_PROLOGUE();
	// std r15,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, ctx.r15.u64);
	// std r16,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, ctx.r16.u64);
	// std r17,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, ctx.r17.u64);
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, ctx.r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, ctx.r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_15"))) PPC_WEAK_FUNC(__restfpr_15);
PPC_FUNC_IMPL(__imp____restfpr_15) {
	PPC_FUNC_PROLOGUE();
	// std r15,-144(r1)
	PPC_STORE_U64(ctx.r1.u32 + -144, ctx.r15.u64);
	// std r16,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, ctx.r16.u64);
	// std r17,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, ctx.r17.u64);
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, ctx.r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, ctx.r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_16"))) PPC_WEAK_FUNC(__restfpr_16);
PPC_FUNC_IMPL(__imp____restfpr_16) {
	PPC_FUNC_PROLOGUE();
	// std r16,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, ctx.r16.u64);
	// std r17,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, ctx.r17.u64);
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, ctx.r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, ctx.r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_16"))) PPC_WEAK_FUNC(__restfpr_16);
PPC_FUNC_IMPL(__imp____restfpr_16) {
	PPC_FUNC_PROLOGUE();
	// std r16,-136(r1)
	PPC_STORE_U64(ctx.r1.u32 + -136, ctx.r16.u64);
	// std r17,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, ctx.r17.u64);
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, ctx.r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, ctx.r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_17"))) PPC_WEAK_FUNC(__restfpr_17);
PPC_FUNC_IMPL(__imp____restfpr_17) {
	PPC_FUNC_PROLOGUE();
	// std r17,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, ctx.r17.u64);
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, ctx.r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, ctx.r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_17"))) PPC_WEAK_FUNC(__restfpr_17);
PPC_FUNC_IMPL(__imp____restfpr_17) {
	PPC_FUNC_PROLOGUE();
	// std r17,-128(r1)
	PPC_STORE_U64(ctx.r1.u32 + -128, ctx.r17.u64);
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, ctx.r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, ctx.r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_18"))) PPC_WEAK_FUNC(__restfpr_18);
PPC_FUNC_IMPL(__imp____restfpr_18) {
	PPC_FUNC_PROLOGUE();
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, ctx.r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, ctx.r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_18"))) PPC_WEAK_FUNC(__restfpr_18);
PPC_FUNC_IMPL(__imp____restfpr_18) {
	PPC_FUNC_PROLOGUE();
	// std r18,-120(r1)
	PPC_STORE_U64(ctx.r1.u32 + -120, ctx.r18.u64);
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, ctx.r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_19"))) PPC_WEAK_FUNC(__restfpr_19);
PPC_FUNC_IMPL(__imp____restfpr_19) {
	PPC_FUNC_PROLOGUE();
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, ctx.r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_19"))) PPC_WEAK_FUNC(__restfpr_19);
PPC_FUNC_IMPL(__imp____restfpr_19) {
	PPC_FUNC_PROLOGUE();
	// std r19,-112(r1)
	PPC_STORE_U64(ctx.r1.u32 + -112, ctx.r19.u64);
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_20"))) PPC_WEAK_FUNC(__restfpr_20);
PPC_FUNC_IMPL(__imp____restfpr_20) {
	PPC_FUNC_PROLOGUE();
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_20"))) PPC_WEAK_FUNC(__restfpr_20);
PPC_FUNC_IMPL(__imp____restfpr_20) {
	PPC_FUNC_PROLOGUE();
	// std r20,-104(r1)
	PPC_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_21"))) PPC_WEAK_FUNC(__restfpr_21);
PPC_FUNC_IMPL(__imp____restfpr_21) {
	PPC_FUNC_PROLOGUE();
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_21"))) PPC_WEAK_FUNC(__restfpr_21);
PPC_FUNC_IMPL(__imp____restfpr_21) {
	PPC_FUNC_PROLOGUE();
	// std r21,-96(r1)
	PPC_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_22"))) PPC_WEAK_FUNC(__restfpr_22);
PPC_FUNC_IMPL(__imp____restfpr_22) {
	PPC_FUNC_PROLOGUE();
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_22"))) PPC_WEAK_FUNC(__restfpr_22);
PPC_FUNC_IMPL(__imp____restfpr_22) {
	PPC_FUNC_PROLOGUE();
	// std r22,-88(r1)
	PPC_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_23"))) PPC_WEAK_FUNC(__restfpr_23);
PPC_FUNC_IMPL(__imp____restfpr_23) {
	PPC_FUNC_PROLOGUE();
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_23"))) PPC_WEAK_FUNC(__restfpr_23);
PPC_FUNC_IMPL(__imp____restfpr_23) {
	PPC_FUNC_PROLOGUE();
	// std r23,-80(r1)
	PPC_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_24"))) PPC_WEAK_FUNC(__restfpr_24);
PPC_FUNC_IMPL(__imp____restfpr_24) {
	PPC_FUNC_PROLOGUE();
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_24"))) PPC_WEAK_FUNC(__restfpr_24);
PPC_FUNC_IMPL(__imp____restfpr_24) {
	PPC_FUNC_PROLOGUE();
	// std r24,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_25"))) PPC_WEAK_FUNC(__restfpr_25);
PPC_FUNC_IMPL(__imp____restfpr_25) {
	PPC_FUNC_PROLOGUE();
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_25"))) PPC_WEAK_FUNC(__restfpr_25);
PPC_FUNC_IMPL(__imp____restfpr_25) {
	PPC_FUNC_PROLOGUE();
	// std r25,-64(r1)
	PPC_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_26"))) PPC_WEAK_FUNC(__restfpr_26);
PPC_FUNC_IMPL(__imp____restfpr_26) {
	PPC_FUNC_PROLOGUE();
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_26"))) PPC_WEAK_FUNC(__restfpr_26);
PPC_FUNC_IMPL(__imp____restfpr_26) {
	PPC_FUNC_PROLOGUE();
	// std r26,-56(r1)
	PPC_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_27"))) PPC_WEAK_FUNC(__restfpr_27);
PPC_FUNC_IMPL(__imp____restfpr_27) {
	PPC_FUNC_PROLOGUE();
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_27"))) PPC_WEAK_FUNC(__restfpr_27);
PPC_FUNC_IMPL(__imp____restfpr_27) {
	PPC_FUNC_PROLOGUE();
	// std r27,-48(r1)
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_28"))) PPC_WEAK_FUNC(__restfpr_28);
PPC_FUNC_IMPL(__imp____restfpr_28) {
	PPC_FUNC_PROLOGUE();
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_28"))) PPC_WEAK_FUNC(__restfpr_28);
PPC_FUNC_IMPL(__imp____restfpr_28) {
	PPC_FUNC_PROLOGUE();
	// std r28,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_29"))) PPC_WEAK_FUNC(__restfpr_29);
PPC_FUNC_IMPL(__imp____restfpr_29) {
	PPC_FUNC_PROLOGUE();
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_29"))) PPC_WEAK_FUNC(__restfpr_29);
PPC_FUNC_IMPL(__imp____restfpr_29) {
	PPC_FUNC_PROLOGUE();
	// std r29,-32(r1)
	PPC_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_30"))) PPC_WEAK_FUNC(__restfpr_30);
PPC_FUNC_IMPL(__imp____restfpr_30) {
	PPC_FUNC_PROLOGUE();
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp____restfpr_30"))) PPC_WEAK_FUNC(__restfpr_30);
PPC_FUNC_IMPL(__imp____restfpr_30) {
	PPC_FUNC_PROLOGUE();
	// std r30,-24(r1)
	PPC_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_31"))) PPC_WEAK_FUNC(__restfpr_31);
PPC_FUNC_IMPL(__imp____restfpr_31) {
	PPC_FUNC_PROLOGUE();
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

__attribute__((alias("__imp____restfpr_31"))) PPC_WEAK_FUNC(__restfpr_31);
PPC_FUNC_IMPL(__imp____restfpr_31) {
	PPC_FUNC_PROLOGUE();
	// std r31,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
}

__attribute__((alias("__imp__sub_8233E47C"))) PPC_WEAK_FUNC(sub_8233E47C);
PPC_FUNC_IMPL(__imp__sub_8233E47C) {
	PPC_FUNC_PROLOGUE();
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_14"))) PPC_WEAK_FUNC(__restgprlr_14);
PPC_FUNC_IMPL(__imp____restgprlr_14) {
	PPC_FUNC_PROLOGUE();
	// ld r14,-152(r1)
	ctx.r14.u64 = PPC_LOAD_U64(ctx.r1.u32 + -152);
	// ld r15,-144(r1)
	ctx.r15.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// ld r16,-136(r1)
	ctx.r16.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// ld r17,-128(r1)
	ctx.r17.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// ld r18,-120(r1)
	ctx.r18.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// ld r19,-112(r1)
	ctx.r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// ld r20,-104(r1)
	ctx.r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	ctx.r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	ctx.r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	ctx.r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	ctx.r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_15"))) PPC_WEAK_FUNC(__restgprlr_15);
PPC_FUNC_IMPL(__imp____restgprlr_15) {
	PPC_FUNC_PROLOGUE();
	// ld r15,-144(r1)
	ctx.r15.u64 = PPC_LOAD_U64(ctx.r1.u32 + -144);
	// ld r16,-136(r1)
	ctx.r16.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// ld r17,-128(r1)
	ctx.r17.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// ld r18,-120(r1)
	ctx.r18.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// ld r19,-112(r1)
	ctx.r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// ld r20,-104(r1)
	ctx.r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	ctx.r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	ctx.r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	ctx.r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	ctx.r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_16"))) PPC_WEAK_FUNC(__restgprlr_16);
PPC_FUNC_IMPL(__imp____restgprlr_16) {
	PPC_FUNC_PROLOGUE();
	// ld r16,-136(r1)
	ctx.r16.u64 = PPC_LOAD_U64(ctx.r1.u32 + -136);
	// ld r17,-128(r1)
	ctx.r17.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// ld r18,-120(r1)
	ctx.r18.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// ld r19,-112(r1)
	ctx.r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// ld r20,-104(r1)
	ctx.r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	ctx.r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	ctx.r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	ctx.r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	ctx.r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_17"))) PPC_WEAK_FUNC(__restgprlr_17);
PPC_FUNC_IMPL(__imp____restgprlr_17) {
	PPC_FUNC_PROLOGUE();
	// ld r17,-128(r1)
	ctx.r17.u64 = PPC_LOAD_U64(ctx.r1.u32 + -128);
	// ld r18,-120(r1)
	ctx.r18.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// ld r19,-112(r1)
	ctx.r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// ld r20,-104(r1)
	ctx.r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	ctx.r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	ctx.r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	ctx.r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	ctx.r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_18"))) PPC_WEAK_FUNC(__restgprlr_18);
PPC_FUNC_IMPL(__imp____restgprlr_18) {
	PPC_FUNC_PROLOGUE();
	// ld r18,-120(r1)
	ctx.r18.u64 = PPC_LOAD_U64(ctx.r1.u32 + -120);
	// ld r19,-112(r1)
	ctx.r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// ld r20,-104(r1)
	ctx.r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	ctx.r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	ctx.r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	ctx.r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	ctx.r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_19"))) PPC_WEAK_FUNC(__restgprlr_19);
PPC_FUNC_IMPL(__imp____restgprlr_19) {
	PPC_FUNC_PROLOGUE();
	// ld r19,-112(r1)
	ctx.r19.u64 = PPC_LOAD_U64(ctx.r1.u32 + -112);
	// ld r20,-104(r1)
	ctx.r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	ctx.r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	ctx.r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	ctx.r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	ctx.r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_20"))) PPC_WEAK_FUNC(__restgprlr_20);
PPC_FUNC_IMPL(__imp____restgprlr_20) {
	PPC_FUNC_PROLOGUE();
	// ld r20,-104(r1)
	ctx.r20.u64 = PPC_LOAD_U64(ctx.r1.u32 + -104);
	// ld r21,-96(r1)
	ctx.r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	ctx.r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	ctx.r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	ctx.r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_21"))) PPC_WEAK_FUNC(__restgprlr_21);
PPC_FUNC_IMPL(__imp____restgprlr_21) {
	PPC_FUNC_PROLOGUE();
	// ld r21,-96(r1)
	ctx.r21.u64 = PPC_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	ctx.r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	ctx.r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	ctx.r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_22"))) PPC_WEAK_FUNC(__restgprlr_22);
PPC_FUNC_IMPL(__imp____restgprlr_22) {
	PPC_FUNC_PROLOGUE();
	// ld r22,-88(r1)
	ctx.r22.u64 = PPC_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	ctx.r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	ctx.r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_23"))) PPC_WEAK_FUNC(__restgprlr_23);
PPC_FUNC_IMPL(__imp____restgprlr_23) {
	PPC_FUNC_PROLOGUE();
	// ld r23,-80(r1)
	ctx.r23.u64 = PPC_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	ctx.r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_24"))) PPC_WEAK_FUNC(__restgprlr_24);
PPC_FUNC_IMPL(__imp____restgprlr_24) {
	PPC_FUNC_PROLOGUE();
	// ld r24,-72(r1)
	ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	ctx.r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_25"))) PPC_WEAK_FUNC(__restgprlr_25);
PPC_FUNC_IMPL(__imp____restgprlr_25) {
	PPC_FUNC_PROLOGUE();
	// ld r25,-64(r1)
	ctx.r25.u64 = PPC_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_26"))) PPC_WEAK_FUNC(__restgprlr_26);
PPC_FUNC_IMPL(__imp____restgprlr_26) {
	PPC_FUNC_PROLOGUE();
	// ld r26,-56(r1)
	ctx.r26.u64 = PPC_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_27"))) PPC_WEAK_FUNC(__restgprlr_27);
PPC_FUNC_IMPL(__imp____restgprlr_27) {
	PPC_FUNC_PROLOGUE();
	// ld r27,-48(r1)
	ctx.r27.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_28"))) PPC_WEAK_FUNC(__restgprlr_28);
PPC_FUNC_IMPL(__imp____restgprlr_28) {
	PPC_FUNC_PROLOGUE();
	// ld r28,-40(r1)
	ctx.r28.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_29"))) PPC_WEAK_FUNC(__restgprlr_29);
PPC_FUNC_IMPL(__imp____restgprlr_29) {
	PPC_FUNC_PROLOGUE();
	// ld r29,-32(r1)
	ctx.r29.u64 = PPC_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_30"))) PPC_WEAK_FUNC(__restgprlr_30);
PPC_FUNC_IMPL(__imp____restgprlr_30) {
	PPC_FUNC_PROLOGUE();
	// ld r30,-24(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp____restgprlr_31"))) PPC_WEAK_FUNC(__restgprlr_31);
PPC_FUNC_IMPL(__imp____restgprlr_31) {
	PPC_FUNC_PROLOGUE();
	// ld r31,-16(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233E4D4"))) PPC_WEAK_FUNC(sub_8233E4D4);
PPC_FUNC_IMPL(__imp__sub_8233E4D4) {
	PPC_FUNC_PROLOGUE();
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
	// mr r12,r5
	ctx.r12.u64 = ctx.r5.u64;
	// bctr 
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

__attribute__((alias("__imp__sub_8233E4E0"))) PPC_WEAK_FUNC(sub_8233E4E0);
PPC_FUNC_IMPL(__imp__sub_8233E4E0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r3,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r3.u64);
	// clrlwi r6,r3,29
	ctx.r6.u64 = ctx.r3.u32 & 0x7;
	// dcbt r0,r4
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// subfic r6,r6,8
	ctx.xer.ca = ctx.r6.u32 <= 8;
	ctx.r6.s64 = 8 - ctx.r6.s64;
	// beq 0x8233e544
	if (ctx.cr0.eq) goto loc_8233E544;
	// cmplw r5,r6
	ctx.cr0.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// ble 0x8233e560
	if (!ctx.cr0.gt) goto loc_8233E560;
	// cmplwi r6,4
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 4, ctx.xer);
	// beq 0x8233e530
	if (ctx.cr0.eq) goto loc_8233E530;
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8233E518:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8233e518
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E518;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x8233e544
	goto loc_8233E544;
loc_8233E530:
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// lwz r6,0(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
loc_8233E544:
	// clrlwi r6,r4,29
	ctx.r6.u64 = ctx.r4.u32 & 0x7;
	// cmplwi cr6,r6,4
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 4, ctx.xer);
	// cmplwi cr1,r6,0
	ctx.cr1.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// cmplwi cr7,r5,128
	ctx.cr7.compare<uint32_t>(ctx.r5.u32, 128, ctx.xer);
	// beq cr6,0x8233e728
	if (ctx.cr6.eq) goto loc_8233E728;
	// bne cr1,0x8233e858
	if (!ctx.cr1.eq) goto loc_8233E858;
	// bge cr7,0x8233e5fc
	if (!ctx.cr7.lt) goto loc_8233E5FC;
loc_8233E560:
	// dcbtst r0,r3
	// addi r4,r4,-8
	ctx.r4.s64 = ctx.r4.s64 + -8;
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
loc_8233E56C:
	// rlwinm r7,r5,29,28,31
	ctx.r7.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0xF;
	// clrlwi r6,r5,29
	ctx.r6.u64 = ctx.r5.u32 & 0x7;
	// cmplwi cr1,r7,0
	ctx.cr1.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr1,0x8233e590
	if (ctx.cr1.eq) goto loc_8233E590;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8233E584:
	// ldu r7,8(r4)
	ea = 8 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U64(ea);
	ctx.r4.u32 = ea;
	// stdu r7,8(r3)
	ea = 8 + ctx.r3.u32;
	PPC_STORE_U64(ea, ctx.r7.u64);
	ctx.r3.u32 = ea;
	// bdnz 0x8233e584
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E584;
loc_8233E590:
	// cmplwi cr1,r6,4
	ctx.cr1.compare<uint32_t>(ctx.r6.u32, 4, ctx.xer);
	// beq cr6,0x8233e5b4
	if (ctx.cr6.eq) goto loc_8233E5B4;
	// beq cr1,0x8233e5bc
	if (ctx.cr1.eq) goto loc_8233E5BC;
	// addi r3,r3,7
	ctx.r3.s64 = ctx.r3.s64 + 7;
	// addi r4,r4,7
	ctx.r4.s64 = ctx.r4.s64 + 7;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8233E5A8:
	// lbzu r7,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r7,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8233e5a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E5A8;
loc_8233E5B4:
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8233E5BC:
	// clrlwi r6,r3,30
	ctx.r6.u64 = ctx.r3.u32 & 0x3;
	// lwz r5,8(r4)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne 0x8233e5d8
	if (!ctx.cr0.eq) goto loc_8233E5D8;
	// stw r5,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8233E5D8:
	// lbz r8,8(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 8);
	// lbz r7,9(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 9);
	// lbz r6,10(r4)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r4.u32 + 10);
	// stb r8,8(r3)
	PPC_STORE_U8(ctx.r3.u32 + 8, ctx.r8.u8);
	// stb r7,9(r3)
	PPC_STORE_U8(ctx.r3.u32 + 9, ctx.r7.u8);
	// stb r6,10(r3)
	PPC_STORE_U8(ctx.r3.u32 + 10, ctx.r6.u8);
	// stb r5,11(r3)
	PPC_STORE_U8(ctx.r3.u32 + 11, ctx.r5.u8);
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8233E5FC:
	// clrlwi r6,r3,25
	ctx.r6.u64 = ctx.r3.u32 & 0x7F;
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// addi r4,r4,-8
	ctx.r4.s64 = ctx.r4.s64 + -8;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// subfic r6,r6,128
	ctx.xer.ca = ctx.r6.u32 <= 128;
	ctx.r6.s64 = 128 - ctx.r6.s64;
	// beq 0x8233e62c
	if (ctx.cr0.eq) goto loc_8233E62C;
	// rlwinm r7,r6,29,3,31
	ctx.r7.u64 = rotl64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8233E620:
	// ldu r7,8(r4)
	ea = 8 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U64(ea);
	ctx.r4.u32 = ea;
	// stdu r7,8(r3)
	ea = 8 + ctx.r3.u32;
	PPC_STORE_U64(ea, ctx.r7.u64);
	ctx.r3.u32 = ea;
	// bdnz 0x8233e620
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E620;
loc_8233E62C:
	// rlwinm r6,r5,25,7,31
	ctx.r6.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq 0x8233e56c
	if (ctx.cr0.eq) goto loc_8233E56C;
	// addi r10,r5,127
	ctx.r10.s64 = ctx.r5.s64 + 127;
	// clrlwi r8,r5,25
	ctx.r8.u64 = ctx.r5.u32 & 0x7F;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8233E65C:
	// dcbt r9,r4
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// bdnz 0x8233e65c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E65C;
	// add r12,r4,r5
	ctx.r12.u64 = ctx.r4.u64 + ctx.r5.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// subf r11,r9,r12
	ctx.r11.s64 = ctx.r12.s64 - ctx.r9.s64;
	// add r12,r3,r5
	ctx.r12.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8233E67C:
	// ld r6,8(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 8);
	// ld r7,16(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 16);
	// ld r8,24(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 24);
	// std r6,8(r3)
	PPC_STORE_U64(ctx.r3.u32 + 8, ctx.r6.u64);
	// ld r6,32(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 32);
	// std r7,16(r3)
	PPC_STORE_U64(ctx.r3.u32 + 16, ctx.r7.u64);
	// ld r7,40(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 40);
	// std r8,24(r3)
	PPC_STORE_U64(ctx.r3.u32 + 24, ctx.r8.u64);
	// ld r8,48(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 48);
	// std r6,32(r3)
	PPC_STORE_U64(ctx.r3.u32 + 32, ctx.r6.u64);
	// ld r6,56(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 56);
	// std r7,40(r3)
	PPC_STORE_U64(ctx.r3.u32 + 40, ctx.r7.u64);
	// ld r7,64(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 64);
	// std r8,48(r3)
	PPC_STORE_U64(ctx.r3.u32 + 48, ctx.r8.u64);
	// ld r8,72(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 72);
	// std r6,56(r3)
	PPC_STORE_U64(ctx.r3.u32 + 56, ctx.r6.u64);
	// ld r6,80(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 80);
	// std r7,64(r3)
	PPC_STORE_U64(ctx.r3.u32 + 64, ctx.r7.u64);
	// ld r7,88(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 88);
	// std r8,72(r3)
	PPC_STORE_U64(ctx.r3.u32 + 72, ctx.r8.u64);
	// ld r8,96(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 96);
	// std r6,80(r3)
	PPC_STORE_U64(ctx.r3.u32 + 80, ctx.r6.u64);
	// ld r6,104(r4)
	ctx.r6.u64 = PPC_LOAD_U64(ctx.r4.u32 + 104);
	// std r7,88(r3)
	PPC_STORE_U64(ctx.r3.u32 + 88, ctx.r7.u64);
	// ld r7,112(r4)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r4.u32 + 112);
	// std r8,96(r3)
	PPC_STORE_U64(ctx.r3.u32 + 96, ctx.r8.u64);
	// ld r8,120(r4)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r4.u32 + 120);
	// std r6,104(r3)
	PPC_STORE_U64(ctx.r3.u32 + 104, ctx.r6.u64);
	// ldu r6,128(r4)
	ea = 128 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U64(ea);
	ctx.r4.u32 = ea;
	// std r7,112(r3)
	PPC_STORE_U64(ctx.r3.u32 + 112, ctx.r7.u64);
	// std r8,120(r3)
	PPC_STORE_U64(ctx.r3.u32 + 120, ctx.r8.u64);
	// stdu r6,128(r3)
	ea = 128 + ctx.r3.u32;
	PPC_STORE_U64(ea, ctx.r6.u64);
	ctx.r3.u32 = ea;
	// cmplw r4,r11
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge 0x8233e710
	if (!ctx.cr0.lt) goto loc_8233E710;
	// dcbt r9,r4
	// bdnz 0x8233e67c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E67C;
	// b 0x8233e56c
	goto loc_8233E56C;
loc_8233E710:
	// beq cr1,0x8233e720
	if (ctx.cr1.eq) goto loc_8233E720;
	// li r8,-1
	ctx.r8.s64 = -1;
	// dcbtst r8,r12
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
loc_8233E720:
	// bdnz 0x8233e67c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E67C;
	// b 0x8233e56c
	goto loc_8233E56C;
loc_8233E728:
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// bge cr7,0x8233e780
	if (!ctx.cr7.lt) goto loc_8233E780;
	// dcbtst r0,r3
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
loc_8233E738:
	// rlwinm r7,r5,30,27,31
	ctx.r7.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x1F;
	// clrlwi r6,r5,30
	ctx.r6.u64 = ctx.r5.u32 & 0x3;
	// cmplwi cr1,r7,0
	ctx.cr1.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr1,0x8233e75c
	if (ctx.cr1.eq) goto loc_8233E75C;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8233E750:
	// lwzu r7,4(r4)
	ea = 4 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r4.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// bdnz 0x8233e750
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E750;
loc_8233E75C:
	// beq cr6,0x8233e778
	if (ctx.cr6.eq) goto loc_8233E778;
	// addi r3,r3,3
	ctx.r3.s64 = ctx.r3.s64 + 3;
	// addi r4,r4,3
	ctx.r4.s64 = ctx.r4.s64 + 3;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8233E76C:
	// lbzu r7,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r7,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r7.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8233e76c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E76C;
loc_8233E778:
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8233E780:
	// clrlwi r6,r3,25
	ctx.r6.u64 = ctx.r3.u32 & 0x7F;
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// subfic r6,r6,128
	ctx.xer.ca = ctx.r6.u32 <= 128;
	ctx.r6.s64 = 128 - ctx.r6.s64;
	// beq 0x8233e7ac
	if (ctx.cr0.eq) goto loc_8233E7AC;
	// rlwinm r7,r6,30,2,31
	ctx.r7.u64 = rotl64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8233E7A0:
	// lwzu r7,4(r4)
	ea = 4 + ctx.r4.u32;
	ctx.r7.u64 = PPC_LOAD_U32(ea);
	ctx.r4.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// bdnz 0x8233e7a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E7A0;
loc_8233E7AC:
	// rlwinm r6,r5,25,7,31
	ctx.r6.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq 0x8233e738
	if (ctx.cr0.eq) goto loc_8233E738;
	// addi r10,r5,127
	ctx.r10.s64 = ctx.r5.s64 + 127;
	// clrlwi r8,r5,25
	ctx.r8.u64 = ctx.r5.u32 & 0x7F;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r9,4
	ctx.r9.s64 = 4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8233E7DC:
	// dcbt r9,r4
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// bdnz 0x8233e7dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E7DC;
	// add r12,r4,r5
	ctx.r12.u64 = ctx.r4.u64 + ctx.r5.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// subf r11,r9,r12
	ctx.r11.s64 = ctx.r12.s64 - ctx.r9.s64;
	// add r12,r3,r5
	ctx.r12.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8233E7FC:
	// li r6,8
	ctx.r6.s64 = 8;
loc_8233E800:
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// lwz r0,4(r4)
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r7,8(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r8,12(r4)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r4.u32 + 12);
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// stw r0,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r0.u32);
	// lwzu r0,16(r4)
	ea = 16 + ctx.r4.u32;
	ctx.r0.u64 = PPC_LOAD_U32(ea);
	ctx.r4.u32 = ea;
	// stw r7,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stw r8,12(r3)
	PPC_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// stwu r0,16(r3)
	ea = 16 + ctx.r3.u32;
	PPC_STORE_U32(ea, ctx.r0.u32);
	ctx.r3.u32 = ea;
	// bne 0x8233e800
	if (!ctx.cr0.eq) goto loc_8233E800;
	// cmplw r4,r11
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge 0x8233e840
	if (!ctx.cr0.lt) goto loc_8233E840;
	// dcbt r9,r4
	// bdnz 0x8233e7fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E7FC;
	// b 0x8233e738
	goto loc_8233E738;
loc_8233E840:
	// beq cr1,0x8233e850
	if (ctx.cr1.eq) goto loc_8233E850;
	// li r8,-1
	ctx.r8.s64 = -1;
	// dcbtst r8,r12
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
loc_8233E850:
	// bdnz 0x8233e7fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E7FC;
	// b 0x8233e738
	goto loc_8233E738;
loc_8233E858:
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// bge cr7,0x8233e88c
	if (!ctx.cr7.lt) goto loc_8233E88C;
	// dcbtst r0,r3
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
loc_8233E868:
	// clrlwi r6,r5,25
	ctx.r6.u64 = ctx.r5.u32 & 0x7F;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// beq 0x8233e884
	if (ctx.cr0.eq) goto loc_8233E884;
loc_8233E878:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8233e878
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E878;
loc_8233E884:
	// ld r3,-8(r1)
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8233E88C:
	// clrlwi r6,r3,25
	ctx.r6.u64 = ctx.r3.u32 & 0x7F;
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// subfic r6,r6,128
	ctx.xer.ca = ctx.r6.u32 <= 128;
	ctx.r6.s64 = 128 - ctx.r6.s64;
	// beq 0x8233e8b4
	if (ctx.cr0.eq) goto loc_8233E8B4;
	// subf r5,r6,r5
	ctx.r5.s64 = ctx.r5.s64 - ctx.r6.s64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8233E8A8:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = PPC_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	PPC_STORE_U8(ea, ctx.r6.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8233e8a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E8A8;
loc_8233E8B4:
	// rlwinm r6,r5,25,7,31
	ctx.r6.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq 0x8233e868
	if (ctx.cr0.eq) goto loc_8233E868;
	// addi r10,r5,127
	ctx.r10.s64 = ctx.r5.s64 + 127;
	// clrlwi r8,r5,25
	ctx.r8.u64 = ctx.r5.u32 & 0x7F;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = rotl64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8233E8E4:
	// dcbt r9,r4
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// bdnz 0x8233e8e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E8E4;
	// add r12,r4,r5
	ctx.r12.u64 = ctx.r4.u64 + ctx.r5.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// subf r11,r9,r12
	ctx.r11.s64 = ctx.r12.s64 - ctx.r9.s64;
	// add r12,r3,r5
	ctx.r12.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8233E904:
	// li r6,32
	ctx.r6.s64 = 32;
loc_8233E908:
	// lbz r7,4(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 4);
	// lbz r8,3(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (rotl32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r9,2(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// rlwimi r7,r9,16,8,15
	ctx.r7.u64 = (rotl32(ctx.r9.u32, 16) & 0xFF0000) | (ctx.r7.u64 & 0xFFFFFFFFFF00FFFF);
	// lbz r10,1(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// rlwimi r7,r10,24,0,7
	ctx.r7.u64 = (rotl32(ctx.r10.u32, 24) & 0xFF000000) | (ctx.r7.u64 & 0xFFFFFFFF00FFFFFF);
	// stw r7,1(r3)
	PPC_STORE_U32(ctx.r3.u32 + 1, ctx.r7.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bne 0x8233e908
	if (!ctx.cr0.eq) goto loc_8233E908;
	// cmplw r4,r11
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge 0x8233e950
	if (!ctx.cr0.lt) goto loc_8233E950;
	// dcbt r9,r4
	// bdnz 0x8233e904
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E904;
	// b 0x8233e868
	goto loc_8233E868;
loc_8233E950:
	// beq cr1,0x8233e960
	if (ctx.cr1.eq) goto loc_8233E960;
	// li r8,-1
	ctx.r8.s64 = -1;
	// dcbtst r8,r12
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
loc_8233E960:
	// bdnz 0x8233e904
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E904;
	// b 0x8233e868
	goto loc_8233E868;
}

__attribute__((alias("__imp__sub_8233E968"))) PPC_WEAK_FUNC(sub_8233E968);
PPC_FUNC_IMPL(__imp__sub_8233E968) {
	PPC_FUNC_PROLOGUE();
	// addi r0,r5,1
	ctx.r0.s64 = ctx.r5.s64 + 1;
	// ori r6,r3,0
	ctx.r6.u64 = ctx.r3.u64 | 0;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// b 0x8233e98c
	goto loc_8233E98C;
loc_8233E978:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// lbz r0,0(r4)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// stb r0,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r0.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
loc_8233E98C:
	// andi. r0,r6,3
	ctx.r0.u64 = ctx.r6.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// bdnzf eq,0x8233e978
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0 && !ctx.cr0.eq) goto loc_8233E978;
	// rlwinm. r0,r5,30,2,31
	ctx.r0.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// beq- 0x8233e9bc
	if (ctx.cr0.eq) goto loc_8233E9BC;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// andi. r0,r4,3
	ctx.r0.u64 = ctx.r4.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// bne- 0x8233e9e0
	if (!ctx.cr0.eq) goto loc_8233E9E0;
loc_8233E9A8:
	// lwz r7,0(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + 0);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdnz+ 0x8233e9a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E9A8;
loc_8233E9BC:
	// andi. r0,r5,3
	ctx.r0.u64 = ctx.r5.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// beqlr+ 
	if (ctx.cr0.eq) return;
loc_8233E9C8:
	// lbz r0,0(r4)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// stb r0,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r0.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// bdnz+ 0x8233e9c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E9C8;
	// blr 
	return;
loc_8233E9E0:
	// lbz r7,3(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + 3);
	// lbz r8,2(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + 2);
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (rotl32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r9,1(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + 1);
	// rlwimi r7,r9,16,8,15
	ctx.r7.u64 = (rotl32(ctx.r9.u32, 16) & 0xFF0000) | (ctx.r7.u64 & 0xFFFFFFFFFF00FFFF);
	// lbz r10,0(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + 0);
	// rlwimi r7,r10,24,0,7
	ctx.r7.u64 = (rotl32(ctx.r10.u32, 24) & 0xFF000000) | (ctx.r7.u64 & 0xFFFFFFFF00FFFFFF);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// stw r7,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r7.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdnz 0x8233e9e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233E9E0;
	// b 0x8233e9bc
	goto loc_8233E9BC;
}

__attribute__((alias("__imp__sub_8233EA10"))) PPC_WEAK_FUNC(sub_8233EA10);
PPC_FUNC_IMPL(__imp__sub_8233EA10) {
	PPC_FUNC_PROLOGUE();
	// fctidz f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.s64 = (ctx.f1.f64 > double(LLONG_MAX)) ? LLONG_MAX : simd::truncate_f64_to_i64(ctx.f1.f64);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// fabs f11,f1
	ctx.f11.u64 = ctx.f1.u64 & 0x7FFFFFFFFFFFFFFF;
	// lis r10,-32251
	ctx.r10.s64 = -2113601536;
	// lfd f13,9024(r11)
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r11.u32 + 9024);
	// lfd f0,4280(r10)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r10.u32 + 4280);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fsub f0,f0,f11
	ctx.f0.f64 = ctx.f0.f64 - ctx.f11.f64;
	// fneg f11,f11
	ctx.f11.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// fsub f10,f12,f1
	ctx.f10.f64 = ctx.f12.f64 - ctx.f1.f64;
	// fadd f13,f12,f13
	ctx.f13.f64 = ctx.f12.f64 + ctx.f13.f64;
	// fsel f13,f10,f12,f13
	ctx.f13.f64 = ctx.f10.f64 >= 0.0 ? ctx.f12.f64 : ctx.f13.f64;
	// fsel f0,f0,f13,f1
	ctx.f0.f64 = ctx.f0.f64 >= 0.0 ? ctx.f13.f64 : ctx.f1.f64;
	// fsel f1,f11,f1,f0
	ctx.f1.f64 = ctx.f11.f64 >= 0.0 ? ctx.f1.f64 : ctx.f0.f64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233EA4C"))) PPC_WEAK_FUNC(sub_8233EA4C);
PPC_FUNC_IMPL(__imp__sub_8233EA4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233EA50"))) PPC_WEAK_FUNC(sub_8233EA50);
PPC_FUNC_IMPL(__imp__sub_8233EA50) {
	PPC_FUNC_PROLOGUE();
	// std r30,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r8,-32198
	ctx.r8.s64 = -2110128128;
	// lis r11,-32204
	ctx.r11.s64 = -2110521344;
	// addi r30,r8,-18736
	ctx.r30.s64 = ctx.r8.s64 + -18736;
	// addi r11,r11,28008
	ctx.r11.s64 = ctx.r11.s64 + 28008;
	// lis r10,-32204
	ctx.r10.s64 = -2110521344;
	// lis r9,-32204
	ctx.r9.s64 = -2110521344;
	// stw r11,-18736(r8)
	PPC_STORE_U32(ctx.r8.u32 + -18736, ctx.r11.u32);
	// lis r31,-32204
	ctx.r31.s64 = -2110521344;
	// addi r10,r10,25096
	ctx.r10.s64 = ctx.r10.s64 + 25096;
	// addi r9,r9,25080
	ctx.r9.s64 = ctx.r9.s64 + 25080;
	// addi r11,r31,25088
	ctx.r11.s64 = ctx.r31.s64 + 25088;
	// stw r10,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r10.u32);
	// lis r3,-32204
	ctx.r3.s64 = -2110521344;
	// stw r9,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r9.u32);
	// lis r4,-32204
	ctx.r4.s64 = -2110521344;
	// stw r11,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// lis r5,-32204
	ctx.r5.s64 = -2110521344;
	// addi r10,r3,24952
	ctx.r10.s64 = ctx.r3.s64 + 24952;
	// addi r9,r4,28008
	ctx.r9.s64 = ctx.r4.s64 + 28008;
	// addi r11,r5,27928
	ctx.r11.s64 = ctx.r5.s64 + 27928;
	// stw r10,16(r30)
	PPC_STORE_U32(ctx.r30.u32 + 16, ctx.r10.u32);
	// lis r6,-32204
	ctx.r6.s64 = -2110521344;
	// stw r9,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r9.u32);
	// lis r7,-32204
	ctx.r7.s64 = -2110521344;
	// stw r11,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// lis r8,-32204
	ctx.r8.s64 = -2110521344;
	// addi r10,r6,24984
	ctx.r10.s64 = ctx.r6.s64 + 24984;
	// addi r9,r7,24776
	ctx.r9.s64 = ctx.r7.s64 + 24776;
	// addi r11,r8,24616
	ctx.r11.s64 = ctx.r8.s64 + 24616;
	// stw r10,28(r30)
	PPC_STORE_U32(ctx.r30.u32 + 28, ctx.r10.u32);
	// stw r9,32(r30)
	PPC_STORE_U32(ctx.r30.u32 + 32, ctx.r9.u32);
	// stw r11,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r11.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233EAE4"))) PPC_WEAK_FUNC(sub_8233EAE4);
PPC_FUNC_IMPL(__imp__sub_8233EAE4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233EAE8"))) PPC_WEAK_FUNC(sub_8233EAE8);
PPC_FUNC_IMPL(__imp__sub_8233EAE8) {
	PPC_FUNC_PROLOGUE();
	// b 0x8233ea50
	sub_8233EA50(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233EAEC"))) PPC_WEAK_FUNC(sub_8233EAEC);
PPC_FUNC_IMPL(__imp__sub_8233EAEC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233EAF0"))) PPC_WEAK_FUNC(sub_8233EAF0);
PPC_FUNC_IMPL(__imp__sub_8233EAF0) {
	PPC_FUNC_PROLOGUE();
	// addi r0,r5,1
	ctx.r0.s64 = ctx.r5.s64 + 1;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// ori r6,r3,0
	ctx.r6.u64 = ctx.r3.u64 | 0;
	// b 0x8233eb0c
	goto loc_8233EB0C;
loc_8233EB00:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// stb r4,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r4.u8);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
loc_8233EB0C:
	// andi. r0,r6,3
	ctx.r0.u64 = ctx.r6.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// bdnzf eq,0x8233eb00
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0 && !ctx.cr0.eq) goto loc_8233EB00;
	// rlwimi r4,r4,8,16,23
	ctx.r4.u64 = (rotl32(ctx.r4.u32, 8) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// rlwinm. r0,r5,28,4,31
	ctx.r0.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 28) & 0xFFFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// rlwimi r4,r4,16,0,15
	ctx.r4.u64 = (rotl32(ctx.r4.u32, 16) & 0xFFFF0000) | (ctx.r4.u64 & 0xFFFFFFFF0000FFFF);
	// beq+ 0x8233eb40
	if (ctx.cr0.eq) goto loc_8233EB40;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
loc_8233EB28:
	// stw r4,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
	// stw r4,4(r6)
	PPC_STORE_U32(ctx.r6.u32 + 4, ctx.r4.u32);
	// stw r4,8(r6)
	PPC_STORE_U32(ctx.r6.u32 + 8, ctx.r4.u32);
	// stw r4,12(r6)
	PPC_STORE_U32(ctx.r6.u32 + 12, ctx.r4.u32);
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// bdnz+ 0x8233eb28
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233EB28;
loc_8233EB40:
	// rlwinm. r0,r5,30,30,31
	ctx.r0.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// beq- 0x8233eb6c
	if (ctx.cr0.eq) goto loc_8233EB6C;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// stw r4,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdz- 0x8233eb6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8233EB6C;
	// stw r4,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdz- 0x8233eb6c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) goto loc_8233EB6C;
	// stw r4,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r4.u32);
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
loc_8233EB6C:
	// andi. r0,r5,3
	ctx.r0.u64 = ctx.r5.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// beqlr+ 
	if (ctx.cr0.eq) return;
	// stb r4,0(r6)
	PPC_STORE_U8(ctx.r6.u32 + 0, ctx.r4.u8);
	// bdzlr- 
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) return;
}

__attribute__((alias("__imp__sub_8233EB80"))) PPC_WEAK_FUNC(sub_8233EB80);
PPC_FUNC_IMPL(__imp__sub_8233EB80) {
	PPC_FUNC_PROLOGUE();
	// stb r4,1(r6)
	PPC_STORE_U8(ctx.r6.u32 + 1, ctx.r4.u8);
	// bdzlr- 
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0) return;
}

__attribute__((alias("__imp__sub_8233EB88"))) PPC_WEAK_FUNC(sub_8233EB88);
PPC_FUNC_IMPL(__imp__sub_8233EB88) {
	PPC_FUNC_PROLOGUE();
	// stb r4,2(r6)
	PPC_STORE_U8(ctx.r6.u32 + 2, ctx.r4.u8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233EB90"))) PPC_WEAK_FUNC(sub_8233EB90);
PPC_FUNC_IMPL(__imp__sub_8233EB90) {
	PPC_FUNC_PROLOGUE();
	// cmpw r3,r4
	ctx.cr0.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, ctx.xer);
	// beqlr- 
	if (ctx.cr0.eq) return;
	// bge+ 0x8233eba0
	if (!ctx.cr0.lt) goto loc_8233EBA0;
	// b 0x8233e4e0
	sub_8233E4E0(ctx, base);
	return;
loc_8233EBA0:
	// addi r0,r5,1
	ctx.r0.s64 = ctx.r5.s64 + 1;
	// add r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 + ctx.r5.u64;
	// add r4,r4,r5
	ctx.r4.u64 = ctx.r4.u64 + ctx.r5.u64;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// b 0x8233ebc8
	goto loc_8233EBC8;
loc_8233EBB4:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// lbz r0,-1(r4)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r4.u32 + -1);
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// stb r0,-1(r3)
	PPC_STORE_U8(ctx.r3.u32 + -1, ctx.r0.u8);
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
loc_8233EBC8:
	// andi. r0,r3,3
	ctx.r0.u64 = ctx.r3.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// bdnzf eq,0x8233ebb4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0 && !ctx.cr0.eq) goto loc_8233EBB4;
	// rlwinm. r0,r5,30,2,31
	ctx.r0.u64 = rotl64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// beq- 0x8233ebf8
	if (ctx.cr0.eq) goto loc_8233EBF8;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// andi. r0,r4,3
	ctx.r0.u64 = ctx.r4.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// bne- 0x8233ec1c
	if (!ctx.cr0.eq) goto loc_8233EC1C;
loc_8233EBE4:
	// lwz r7,-4(r4)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r4.u32 + -4);
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// stw r7,-4(r3)
	PPC_STORE_U32(ctx.r3.u32 + -4, ctx.r7.u32);
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// bdnz+ 0x8233ebe4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233EBE4;
loc_8233EBF8:
	// andi. r0,r5,3
	ctx.r0.u64 = ctx.r5.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// beqlr+ 
	if (ctx.cr0.eq) return;
loc_8233EC04:
	// lbz r0,-1(r4)
	ctx.r0.u64 = PPC_LOAD_U8(ctx.r4.u32 + -1);
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// stb r0,-1(r3)
	PPC_STORE_U8(ctx.r3.u32 + -1, ctx.r0.u8);
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// bdnz+ 0x8233ec04
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233EC04;
	// blr 
	return;
loc_8233EC1C:
	// lbz r7,-1(r4)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r4.u32 + -1);
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// lbz r8,-2(r4)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r4.u32 + -2);
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (rotl32(ctx.r8.u32, 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r9,-3(r4)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r4.u32 + -3);
	// rlwimi r7,r9,16,8,15
	ctx.r7.u64 = (rotl32(ctx.r9.u32, 16) & 0xFF0000) | (ctx.r7.u64 & 0xFFFFFFFFFF00FFFF);
	// lbz r10,-4(r4)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r4.u32 + -4);
	// rlwimi r7,r10,24,0,7
	ctx.r7.u64 = (rotl32(ctx.r10.u32, 24) & 0xFF000000) | (ctx.r7.u64 & 0xFFFFFFFF00FFFFFF);
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// stw r7,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// bdnz 0x8233ec1c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8233EC1C;
	// b 0x8233ebf8
	goto loc_8233EBF8;
}

__attribute__((alias("__imp__sub_8233EC4C"))) PPC_WEAK_FUNC(sub_8233EC4C);
PPC_FUNC_IMPL(__imp__sub_8233EC4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233EC50"))) PPC_WEAK_FUNC(sub_8233EC50);
PPC_FUNC_IMPL(__imp__sub_8233EC50) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-72(r1)
	PPC_STORE_U64(ctx.r1.u32 + -72, ctx.r31.u64);
	// mflr r31
	ctx.r31.u64 = ctx.lr;
	// stwu r1,-80(r1)
	ea = -80 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// bl 0x82389264
	ctx.lr = 0x8233EC68;
	__imp__RtlUnwind(ctx, base);
	// mtlr r31
	ctx.lr = ctx.r31.u64;
	// ld r31,8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + 8);
	// addi r1,r1,80
	ctx.r1.s64 = ctx.r1.s64 + 80;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233EC78"))) PPC_WEAK_FUNC(sub_8233EC78);
PPC_FUNC_IMPL(__imp__sub_8233EC78) {
	PPC_FUNC_PROLOGUE();
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82388e14
	__imp__KeBugCheck(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233EC80"))) PPC_WEAK_FUNC(sub_8233EC80);
PPC_FUNC_IMPL(__imp__sub_8233EC80) {
	PPC_FUNC_PROLOGUE();
	// li r3,8
	ctx.r3.s64 = 8;
	// b 0x823470b0
	sub_823470B0(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233EC88"))) PPC_WEAK_FUNC(sub_8233EC88);
PPC_FUNC_IMPL(__imp__sub_8233EC88) {
	PPC_FUNC_PROLOGUE();
	// li r3,8
	ctx.r3.s64 = 8;
	// b 0x82346e30
	sub_82346E30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233EC90"))) PPC_WEAK_FUNC(sub_8233EC90);
PPC_FUNC_IMPL(__imp__sub_8233EC90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	PPC_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823471e0
	ctx.lr = 0x8233ECA4;
	sub_823471E0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82342be0
	ctx.lr = 0x8233ECAC;
	sub_82342BE0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82342830
	ctx.lr = 0x8233ECB4;
	sub_82342830(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823471c8
	ctx.lr = 0x8233ECBC;
	sub_823471C8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233ECCC"))) PPC_WEAK_FUNC(sub_8233ECCC);
PPC_FUNC_IMPL(__imp__sub_8233ECCC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233ECD0"))) PPC_WEAK_FUNC(sub_8233ECD0);
PPC_FUNC_IMPL(__imp__sub_8233ECD0) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// b 0x8233ed08
	goto loc_8233ED08;
loc_8233ECF0:
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8233ed04
	if (ctx.cr6.eq) goto loc_8233ED04;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8233ED04;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8233ED04:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
loc_8233ED08:
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x8233ecf0
	if (ctx.cr6.lt) goto loc_8233ECF0;
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

__attribute__((alias("__imp__sub_8233ED28"))) PPC_WEAK_FUNC(sub_8233ED28);
PPC_FUNC_IMPL(__imp__sub_8233ED28) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r17,-30396(r24)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r24.u32 + -30396);
	// lwz r16,-13272(r6)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r6.u32 + -13272);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e458
	ctx.lr = 0x8233ED38;
	__restfpr_24(ctx, base);
	// addi r31,r1,-176
	ctx.r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// stw r4,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r4.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x823470b0
	ctx.lr = 0x8233ED54;
	sub_823470B0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r11,-32183
	ctx.r11.s64 = -2109145088;
	// lwz r11,23248(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 23248);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8233ee6c
	if (ctx.cr6.eq) goto loc_8233EE6C;
	// lis r9,-32183
	ctx.r9.s64 = -2109145088;
	// lwz r11,23244(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 23244);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8233ed80
	if (!ctx.cr6.eq) goto loc_8233ED80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388e14
	ctx.lr = 0x8233ED80;
	__imp__KeBugCheck(ctx, base);
loc_8233ED80:
	// lis r8,-32183
	ctx.r8.s64 = -2109145088;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,23244(r9)
	PPC_STORE_U32(ctx.r9.u32 + 23244, ctx.r11.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stb r24,23240(r8)
	PPC_STORE_U8(ctx.r8.u32 + 23240, ctx.r24.u8);
	// bne cr6,0x8233ee58
	if (!ctx.cr6.eq) goto loc_8233EE58;
	// lis r25,-32170
	ctx.r25.s64 = -2108293120;
	// lwz r28,-24368(r25)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r25.u32 + -24368);
	// stw r28,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r28.u32);
	// cmplwi r28,0
	ctx.cr0.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq 0x8233ee44
	if (ctx.cr0.eq) goto loc_8233EE44;
	// lis r27,-32170
	ctx.r27.s64 = -2108293120;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// lwz r30,-24372(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -24372);
	// mr r26,r30
	ctx.r26.u64 = ctx.r30.u64;
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r30.u32);
loc_8233EDC8:
	// addi r30,r30,-4
	ctx.r30.s64 = ctx.r30.s64 + -4;
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x8233ee44
	if (ctx.cr6.lt) goto loc_8233EE44;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8233edec
	if (!ctx.cr6.eq) goto loc_8233EDEC;
loc_8233EDE4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x8233edc8
	goto loc_8233EDC8;
loc_8233EDEC:
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x8233ee44
	if (ctx.cr6.lt) goto loc_8233EE44;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8233EE08;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-24368(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + -24368);
	// lwz r10,-24372(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + -24372);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8233ee20
	if (!ctx.cr6.eq) goto loc_8233EE20;
	// cmplw cr6,r26,r10
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8233ede4
	if (ctx.cr6.eq) goto loc_8233EDE4;
loc_8233EE20:
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// mr r26,r10
	ctx.r26.u64 = ctx.r10.u64;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// mr r30,r10
	ctx.r30.u64 = ctx.r10.u64;
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// b 0x8233ede4
	goto loc_8233EDE4;
loc_8233EE44:
	// lis r11,-32199
	ctx.r11.s64 = -2110193664;
	// lis r10,-32199
	ctx.r10.s64 = -2110193664;
	// addi r4,r11,1916
	ctx.r4.s64 = ctx.r11.s64 + 1916;
	// addi r3,r10,1904
	ctx.r3.s64 = ctx.r10.s64 + 1904;
	// bl 0x8233ecd0
	ctx.lr = 0x8233EE58;
	sub_8233ECD0(ctx, base);
loc_8233EE58:
	// lis r11,-32199
	ctx.r11.s64 = -2110193664;
	// lis r10,-32199
	ctx.r10.s64 = -2110193664;
	// addi r4,r11,1924
	ctx.r4.s64 = ctx.r11.s64 + 1924;
	// addi r3,r10,1920
	ctx.r3.s64 = ctx.r10.s64 + 1920;
	// bl 0x8233ecd0
	ctx.lr = 0x8233EE6C;
	sub_8233ECD0(ctx, base);
loc_8233EE6C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,176
	ctx.r12.s64 = ctx.r31.s64 + 176;
	// bl 0x8233eeb4
	ctx.lr = 0x8233EE78;
	sub_8233EEB4(ctx, base);
	// lwz r11,204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8233ee8c
	if (!ctx.cr6.eq) goto loc_8233EE8C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388e14
	ctx.lr = 0x8233EE8C;
	__imp__KeBugCheck(ctx, base);
loc_8233EE8C:
	// addi r1,r31,176
	ctx.r1.s64 = ctx.r31.s64 + 176;
	// b 0x8233e4a8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233ED30"))) PPC_WEAK_FUNC(sub_8233ED30);
PPC_FUNC_IMPL(__imp__sub_8233ED30) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e458
	ctx.lr = 0x8233ED38;
	__restfpr_24(ctx, base);
	// addi r31,r1,-176
	ctx.r31.s64 = ctx.r1.s64 + -176;
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// stw r4,204(r31)
	PPC_STORE_U32(ctx.r31.u32 + 204, ctx.r4.u32);
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x823470b0
	ctx.lr = 0x8233ED54;
	sub_823470B0(ctx, base);
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// lis r11,-32183
	ctx.r11.s64 = -2109145088;
	// lwz r11,23248(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 23248);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x8233ee6c
	if (ctx.cr6.eq) goto loc_8233EE6C;
	// lis r9,-32183
	ctx.r9.s64 = -2109145088;
	// lwz r11,23244(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 23244);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8233ed80
	if (!ctx.cr6.eq) goto loc_8233ED80;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388e14
	ctx.lr = 0x8233ED80;
	__imp__KeBugCheck(ctx, base);
loc_8233ED80:
	// lis r8,-32183
	ctx.r8.s64 = -2109145088;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,23244(r9)
	PPC_STORE_U32(ctx.r9.u32 + 23244, ctx.r11.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stb r24,23240(r8)
	PPC_STORE_U8(ctx.r8.u32 + 23240, ctx.r24.u8);
	// bne cr6,0x8233ee58
	if (!ctx.cr6.eq) goto loc_8233EE58;
	// lis r25,-32170
	ctx.r25.s64 = -2108293120;
	// lwz r28,-24368(r25)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r25.u32 + -24368);
	// stw r28,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r28.u32);
	// cmplwi r28,0
	ctx.cr0.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq 0x8233ee44
	if (ctx.cr0.eq) goto loc_8233EE44;
	// lis r27,-32170
	ctx.r27.s64 = -2108293120;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// stw r28,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r28.u32);
	// lwz r30,-24372(r27)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r27.u32 + -24372);
	// mr r26,r30
	ctx.r26.u64 = ctx.r30.u64;
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// stw r30,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r30.u32);
loc_8233EDC8:
	// addi r30,r30,-4
	ctx.r30.s64 = ctx.r30.s64 + -4;
	// stw r30,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r30.u32);
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x8233ee44
	if (ctx.cr6.lt) goto loc_8233EE44;
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8233edec
	if (!ctx.cr6.eq) goto loc_8233EDEC;
loc_8233EDE4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x8233edc8
	goto loc_8233EDC8;
loc_8233EDEC:
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// blt cr6,0x8233ee44
	if (ctx.cr6.lt) goto loc_8233EE44;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8233EE08;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-24368(r25)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r25.u32 + -24368);
	// lwz r10,-24372(r27)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + -24372);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8233ee20
	if (!ctx.cr6.eq) goto loc_8233EE20;
	// cmplw cr6,r26,r10
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8233ede4
	if (ctx.cr6.eq) goto loc_8233EDE4;
loc_8233EE20:
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// mr r26,r10
	ctx.r26.u64 = ctx.r10.u64;
	// stw r11,84(r31)
	PPC_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// mr r30,r10
	ctx.r30.u64 = ctx.r10.u64;
	// stw r11,88(r31)
	PPC_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// stw r10,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// stw r10,80(r31)
	PPC_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// b 0x8233ede4
	goto loc_8233EDE4;
loc_8233EE44:
	// lis r11,-32199
	ctx.r11.s64 = -2110193664;
	// lis r10,-32199
	ctx.r10.s64 = -2110193664;
	// addi r4,r11,1916
	ctx.r4.s64 = ctx.r11.s64 + 1916;
	// addi r3,r10,1904
	ctx.r3.s64 = ctx.r10.s64 + 1904;
	// bl 0x8233ecd0
	ctx.lr = 0x8233EE58;
	sub_8233ECD0(ctx, base);
loc_8233EE58:
	// lis r11,-32199
	ctx.r11.s64 = -2110193664;
	// lis r10,-32199
	ctx.r10.s64 = -2110193664;
	// addi r4,r11,1924
	ctx.r4.s64 = ctx.r11.s64 + 1924;
	// addi r3,r10,1920
	ctx.r3.s64 = ctx.r10.s64 + 1920;
	// bl 0x8233ecd0
	ctx.lr = 0x8233EE6C;
	sub_8233ECD0(ctx, base);
loc_8233EE6C:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// addi r12,r31,176
	ctx.r12.s64 = ctx.r31.s64 + 176;
	// bl 0x8233eeb4
	ctx.lr = 0x8233EE78;
	sub_8233EEB4(ctx, base);
	// lwz r11,204(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8233ee8c
	if (!ctx.cr6.eq) goto loc_8233EE8C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82388e14
	ctx.lr = 0x8233EE8C;
	__imp__KeBugCheck(ctx, base);
loc_8233EE8C:
	// addi r1,r31,176
	ctx.r1.s64 = ctx.r31.s64 + 176;
	// b 0x8233e4a8
	__restgprlr_24(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233EE94"))) PPC_WEAK_FUNC(sub_8233EE94);
PPC_FUNC_IMPL(__imp__sub_8233EE94) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-176
	ctx.r31.s64 = ctx.r12.s64 + -176;
	// std r24,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r24.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r24,204(r31)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r31.u32 + 204);
	// b 0x8233eecc
	goto loc_8233EECC;
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-176
	ctx.r31.s64 = ctx.r12.s64 + -176;
	// std r24,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r24.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
loc_8233EECC:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x8233eedc
	if (ctx.cr6.eq) goto loc_8233EEDC;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82346e30
	ctx.lr = 0x8233EEDC;
	sub_82346E30(ctx, base);
loc_8233EEDC:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r24,-16(r1)
	ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233EEB4"))) PPC_WEAK_FUNC(sub_8233EEB4);
PPC_FUNC_IMPL(__imp__sub_8233EEB4) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-176
	ctx.r31.s64 = ctx.r12.s64 + -176;
	// std r24,-16(r1)
	PPC_STORE_U64(ctx.r1.u32 + -16, ctx.r24.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	PPC_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x8233eedc
	if (ctx.cr6.eq) goto loc_8233EEDC;
	// li r3,8
	ctx.r3.s64 = 8;
	// bl 0x82346e30
	ctx.lr = 0x8233EEDC;
	sub_82346E30(ctx, base);
loc_8233EEDC:
	// lwz r1,0(r1)
	ctx.r1.u64 = PPC_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// ld r24,-16(r1)
	ctx.r24.u64 = PPC_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = PPC_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233EEF4"))) PPC_WEAK_FUNC(sub_8233EEF4);
PPC_FUNC_IMPL(__imp__sub_8233EEF4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233EEF8"))) PPC_WEAK_FUNC(sub_8233EEF8);
PPC_FUNC_IMPL(__imp__sub_8233EEF8) {
	PPC_FUNC_PROLOGUE();
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8233ed30
	sub_8233ED30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233EF04"))) PPC_WEAK_FUNC(sub_8233EF04);
PPC_FUNC_IMPL(__imp__sub_8233EF04) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233EF08"))) PPC_WEAK_FUNC(sub_8233EF08);
PPC_FUNC_IMPL(__imp__sub_8233EF08) {
	PPC_FUNC_PROLOGUE();
	// li r4,1
	ctx.r4.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8233ed30
	sub_8233ED30(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233EF14"))) PPC_WEAK_FUNC(sub_8233EF14);
PPC_FUNC_IMPL(__imp__sub_8233EF14) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233EF18"))) PPC_WEAK_FUNC(sub_8233EF18);
PPC_FUNC_IMPL(__imp__sub_8233EF18) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x823427e8
	ctx.lr = 0x8233EF30;
	sub_823427E8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823427b8
	ctx.lr = 0x8233EF38;
	sub_823427B8(ctx, base);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x8233ed30
	ctx.lr = 0x8233EF44;
	sub_8233ED30(ctx, base);
}

__attribute__((alias("__imp__sub_8233EF44"))) PPC_WEAK_FUNC(sub_8233EF44);
PPC_FUNC_IMPL(__imp__sub_8233EF44) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233EF48"))) PPC_WEAK_FUNC(sub_8233EF48);
PPC_FUNC_IMPL(__imp__sub_8233EF48) {
	PPC_FUNC_PROLOGUE();
	// b 0x82388734
	__imp__KeTlsGetValue(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233EF4C"))) PPC_WEAK_FUNC(sub_8233EF4C);
PPC_FUNC_IMPL(__imp__sub_8233EF4C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233EF50"))) PPC_WEAK_FUNC(sub_8233EF50);
PPC_FUNC_IMPL(__imp__sub_8233EF50) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32198
	ctx.r11.s64 = -2110128128;
	// lwz r3,-20416(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + -20416);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233EF5C"))) PPC_WEAK_FUNC(sub_8233EF5C);
PPC_FUNC_IMPL(__imp__sub_8233EF5C) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233EF60"))) PPC_WEAK_FUNC(sub_8233EF60);
PPC_FUNC_IMPL(__imp__sub_8233EF60) {
	PPC_FUNC_PROLOGUE();
	// b 0x82388744
	__imp__KeTlsSetValue(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233EF64"))) PPC_WEAK_FUNC(sub_8233EF64);
PPC_FUNC_IMPL(__imp__sub_8233EF64) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233EF68"))) PPC_WEAK_FUNC(sub_8233EF68);
PPC_FUNC_IMPL(__imp__sub_8233EF68) {
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
	// lis r31,-32198
	ctx.r31.s64 = -2110128128;
	// lwz r3,-20416(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + -20416);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8233ef94
	if (ctx.cr6.eq) goto loc_8233EF94;
	// bl 0x82389274
	ctx.lr = 0x8233EF8C;
	__imp__KeTlsFree(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,-20416(r31)
	PPC_STORE_U32(ctx.r31.u32 + -20416, ctx.r11.u32);
loc_8233EF94:
	// bl 0x82346dc0
	ctx.lr = 0x8233EF98;
	sub_82346DC0(ctx, base);
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

__attribute__((alias("__imp__sub_8233EFAC"))) PPC_WEAK_FUNC(sub_8233EFAC);
PPC_FUNC_IMPL(__imp__sub_8233EFAC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233EFB0"))) PPC_WEAK_FUNC(sub_8233EFB0);
PPC_FUNC_IMPL(__imp__sub_8233EFB0) {
	PPC_FUNC_PROLOGUE();
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,6816
	ctx.r11.s64 = ctx.r11.s64 + 6816;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r11,92(r3)
	PPC_STORE_U32(ctx.r3.u32 + 92, ctx.r11.u32);
	// stw r9,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r9.u32);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_8233EFD0"))) PPC_WEAK_FUNC(sub_8233EFD0);
PPC_FUNC_IMPL(__imp__sub_8233EFD0) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e46c
	ctx.lr = 0x8233EFD8;
	__restfpr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x822471d0
	ctx.lr = 0x8233EFE0;
	sub_822471D0(ctx, base);
	// lis r30,-32198
	ctx.r30.s64 = -2110128128;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,-20416(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + -20416);
	// bl 0x82388734
	ctx.lr = 0x8233EFF0;
	__imp__KeTlsGetValue(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8233f080
	if (!ctx.cr0.eq) goto loc_8233F080;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,-20416(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + -20416);
	// bl 0x82388744
	ctx.lr = 0x8233F004;
	__imp__KeTlsSetValue(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8233f090
	if (ctx.cr0.eq) goto loc_8233F090;
	// li r4,196
	ctx.r4.s64 = 196;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82342b78
	ctx.lr = 0x8233F018;
	sub_82342B78(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// lwz r3,-20416(r30)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r30.u32 + -20416);
	// beq 0x8233f074
	if (ctx.cr0.eq) goto loc_8233F074;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82388744
	ctx.lr = 0x8233F02C;
	__imp__KeTlsSetValue(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8233f064
	if (ctx.cr0.eq) goto loc_8233F064;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,6816
	ctx.r11.s64 = ctx.r11.s64 + 6816;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// bl 0x82247330
	ctx.lr = 0x8233F054;
	sub_82247330(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// stw r11,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x8233f090
	goto loc_8233F090;
loc_8233F064:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82341940
	ctx.lr = 0x8233F06C;
	sub_82341940(ctx, base);
	// li r31,0
	ctx.r31.s64 = 0;
	// b 0x8233f090
	goto loc_8233F090;
loc_8233F074:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x82388744
	ctx.lr = 0x8233F07C;
	__imp__KeTlsSetValue(ctx, base);
	// b 0x8233f090
	goto loc_8233F090;
loc_8233F080:
	// addi r11,r31,-1
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.s64 = 0 - ctx.r11.s64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 & ctx.r31.u64;
loc_8233F090:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8224b5b8
	ctx.lr = 0x8233F098;
	sub_8224B5B8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x8233e4bc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233F0A4"))) PPC_WEAK_FUNC(sub_8233F0A4);
PPC_FUNC_IMPL(__imp__sub_8233F0A4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233F0A8"))) PPC_WEAK_FUNC(sub_8233F0A8);
PPC_FUNC_IMPL(__imp__sub_8233F0A8) {
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
	// bl 0x8233efd0
	ctx.lr = 0x8233F0BC;
	sub_8233EFD0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8233f0cc
	if (!ctx.cr0.eq) goto loc_8233F0CC;
	// li r3,16
	ctx.r3.s64 = 16;
	// bl 0x8233ef18
	ctx.lr = 0x8233F0CC;
	sub_8233EF18(ctx, base);
loc_8233F0CC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

__attribute__((alias("__imp__sub_8233F0E4"))) PPC_WEAK_FUNC(sub_8233F0E4);
PPC_FUNC_IMPL(__imp__sub_8233F0E4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233F0E8"))) PPC_WEAK_FUNC(sub_8233F0E8);
PPC_FUNC_IMPL(__imp__sub_8233F0E8) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8233f194
	if (ctx.cr6.eq) goto loc_8233F194;
	// lwz r3,36(r3)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r3.u32 + 36);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8233f114
	if (ctx.cr6.eq) goto loc_8233F114;
	// bl 0x82341940
	ctx.lr = 0x8233F114;
	sub_82341940(ctx, base);
loc_8233F114:
	// lwz r3,44(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 44);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8233f124
	if (ctx.cr6.eq) goto loc_8233F124;
	// bl 0x82341940
	ctx.lr = 0x8233F124;
	sub_82341940(ctx, base);
loc_8233F124:
	// lwz r3,52(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8233f134
	if (ctx.cr6.eq) goto loc_8233F134;
	// bl 0x82341940
	ctx.lr = 0x8233F134;
	sub_82341940(ctx, base);
loc_8233F134:
	// lwz r3,60(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 60);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8233f144
	if (ctx.cr6.eq) goto loc_8233F144;
	// bl 0x82341940
	ctx.lr = 0x8233F144;
	sub_82341940(ctx, base);
loc_8233F144:
	// lwz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8233f154
	if (ctx.cr6.eq) goto loc_8233F154;
	// bl 0x82341940
	ctx.lr = 0x8233F154;
	sub_82341940(ctx, base);
loc_8233F154:
	// lwz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8233f164
	if (ctx.cr6.eq) goto loc_8233F164;
	// bl 0x82341940
	ctx.lr = 0x8233F164;
	sub_82341940(ctx, base);
loc_8233F164:
	// lwz r3,72(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8233f174
	if (ctx.cr6.eq) goto loc_8233F174;
	// bl 0x82341940
	ctx.lr = 0x8233F174;
	sub_82341940(ctx, base);
loc_8233F174:
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// lwz r3,92(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 92);
	// addi r11,r11,6816
	ctx.r11.s64 = ctx.r11.s64 + 6816;
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8233f18c
	if (ctx.cr6.eq) goto loc_8233F18C;
	// bl 0x82341940
	ctx.lr = 0x8233F18C;
	sub_82341940(ctx, base);
loc_8233F18C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82341940
	ctx.lr = 0x8233F194;
	sub_82341940(ctx, base);
loc_8233F194:
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

__attribute__((alias("__imp__sub_8233F1A8"))) PPC_WEAK_FUNC(sub_8233F1A8);
PPC_FUNC_IMPL(__imp__sub_8233F1A8) {
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
	// lis r30,-32198
	ctx.r30.s64 = -2110128128;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-20416(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -20416);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8233f1fc
	if (ctx.cr6.eq) goto loc_8233F1FC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x8233f1e8
	if (!ctx.cr6.eq) goto loc_8233F1E8;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82388734
	ctx.lr = 0x8233F1E0;
	__imp__KeTlsGetValue(ctx, base);
	// lwz r11,-20416(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + -20416);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8233F1E8:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x82388744
	ctx.lr = 0x8233F1F4;
	__imp__KeTlsSetValue(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8233f0e8
	ctx.lr = 0x8233F1FC;
	sub_8233F0E8(ctx, base);
loc_8233F1FC:
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

__attribute__((alias("__imp__sub_8233F214"))) PPC_WEAK_FUNC(sub_8233F214);
PPC_FUNC_IMPL(__imp__sub_8233F214) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233F218"))) PPC_WEAK_FUNC(sub_8233F218);
PPC_FUNC_IMPL(__imp__sub_8233F218) {
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
	// bl 0x8233ec90
	ctx.lr = 0x8233F230;
	sub_8233EC90(ctx, base);
	// bl 0x82346ee8
	ctx.lr = 0x8233F234;
	sub_82346EE8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8233f2d0
	if (ctx.cr0.eq) goto loc_8233F2D0;
	// bl 0x82389254
	ctx.lr = 0x8233F240;
	__imp__KeTlsAlloc(ctx, base);
	// lis r11,-32198
	ctx.r11.s64 = -2110128128;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// stw r3,-20416(r11)
	PPC_STORE_U32(ctx.r11.u32 + -20416, ctx.r3.u32);
	// beq cr6,0x8233f2d0
	if (ctx.cr6.eq) goto loc_8233F2D0;
	// li r4,196
	ctx.r4.s64 = 196;
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82342b78
	ctx.lr = 0x8233F260;
	sub_82342B78(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8233f2d0
	if (ctx.cr0.eq) goto loc_8233F2D0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82388744
	ctx.lr = 0x8233F274;
	__imp__KeTlsSetValue(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8233f2d0
	if (ctx.cr0.eq) goto loc_8233F2D0;
	// lis r11,-32251
	ctx.r11.s64 = -2113601536;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,6816
	ctx.r11.s64 = ctx.r11.s64 + 6816;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r11,92(r31)
	PPC_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// stw r9,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// bl 0x82247330
	ctx.lr = 0x8233F29C;
	sub_82247330(ctx, base);
	// lis r10,-32183
	ctx.r10.s64 = -2109145088;
	// lis r11,-32204
	ctx.r11.s64 = -2110521344;
	// stw r3,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// addi r10,r10,23252
	ctx.r10.s64 = ctx.r10.s64 + 23252;
	// li r9,-1
	ctx.r9.s64 = -1;
	// addi r11,r11,29240
	ctx.r11.s64 = ctx.r11.s64 + 29240;
	// stw r9,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r9.u32);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// li r4,1
	ctx.r4.s64 = 1;
	// stw r11,8(r10)
	PPC_STORE_U32(ctx.r10.u32 + 8, ctx.r11.u32);
	// bl 0x82253d38
	ctx.lr = 0x8233F2C8;
	sub_82253D38(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8233f2d8
	goto loc_8233F2D8;
loc_8233F2D0:
	// bl 0x8233ef68
	ctx.lr = 0x8233F2D4;
	sub_8233EF68(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8233F2D8:
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

__attribute__((alias("__imp__sub_8233F2F0"))) PPC_WEAK_FUNC(sub_8233F2F0);
PPC_FUNC_IMPL(__imp__sub_8233F2F0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x8233e46c
	ctx.lr = 0x8233F2F8;
	__restfpr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	PPC_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	PPC_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-16377
	ctx.r11.s64 = -1073283072;
	// stfd f1,160(r1)
	PPC_STORE_U64(ctx.r1.u32 + 160, ctx.f1.u64);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// ori r29,r11,65279
	ctx.r29.u64 = ctx.r11.u64 | 65279;
	// li r3,248
	ctx.r3.s64 = 248;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82347d10
	ctx.lr = 0x8233F324;
	sub_82347D10(ctx, base);
	// lhz r11,160(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 160);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// rlwinm r11,r11,0,17,27
	ctx.r11.u64 = rotl64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x7FF0;
	// cmplwi cr6,r11,32752
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32752, ctx.xer);
	// bne cr6,0x8233f3b0
	if (!ctx.cr6.eq) goto loc_8233F3B0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82343f08
	ctx.lr = 0x8233F340;
	sub_82343F08(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ble 0x8233f37c
	if (!ctx.cr0.gt) goto loc_8233F37C;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// ble cr6,0x8233f4a4
	if (!ctx.cr6.gt) goto loc_8233F4A4;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// bne cr6,0x8233f37c
	if (!ctx.cr6.eq) goto loc_8233F37C;
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// li r3,25
	ctx.r3.s64 = 25;
	// lfd f0,88(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f2,f0
	ctx.f2.f64 = double(ctx.f0.s64);
	// bl 0x82347ac8
	ctx.lr = 0x8233F378;
	sub_82347AC8(ctx, base);
	// b 0x8233f4b4
	goto loc_8233F4B4;
loc_8233F37C:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// extsw r10,r31
	ctx.r10.s64 = ctx.r31.s32;
	// li r3,8
	ctx.r3.s64 = 8;
	// std r10,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f2,f13
	ctx.f2.f64 = double(ctx.f13.s64);
	// lfd f0,9024(r11)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r11.u32 + 9024);
	// fadd f3,f31,f0
	ctx.f3.f64 = ctx.f31.f64 + ctx.f0.f64;
loc_8233F39C:
	// li r4,25
	ctx.r4.s64 = 25;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// bl 0x82347c20
	ctx.lr = 0x8233F3AC;
	sub_82347C20(ctx, base);
	// b 0x8233f4b4
	goto loc_8233F4B4;
loc_8233F3B0:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfd f30,9016(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r11.u32 + 9016);
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// beq cr6,0x8233f4a4
	if (ctx.cr6.eq) goto loc_8233F4A4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82343f90
	ctx.lr = 0x8233F3CC;
	sub_82343F90(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bge cr6,0x8233f3ec
	if (!ctx.cr6.lt) goto loc_8233F3EC;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r31.s64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x8233f460
	if (ctx.cr6.lt) goto loc_8233F460;
	// b 0x8233f400
	goto loc_8233F400;
loc_8233F3EC:
	// lis r10,32767
	ctx.r10.s64 = 2147418112;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// subf r10,r31,r10
	ctx.r10.s64 = ctx.r10.s64 - ctx.r31.s64;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bgt cr6,0x8233f40c
	if (ctx.cr6.gt) goto loc_8233F40C;
loc_8233F400:
	// add r4,r11,r31
	ctx.r4.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmpwi cr6,r4,2560
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2560, ctx.xer);
	// ble cr6,0x8233f438
	if (!ctx.cr6.gt) goto loc_8233F438;
loc_8233F40C:
	// lis r11,-32198
	ctx.r11.s64 = -2110128128;
	// fmr f2,f1
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f1.f64;
	// lfd f1,-19376(r11)
	ctx.f1.u64 = PPC_LOAD_U64(ctx.r11.u32 + -19376);
	// bl 0x82344088
	ctx.lr = 0x8233F41C;
	sub_82344088(ctx, base);
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
loc_8233F428:
	// li r3,17
	ctx.r3.s64 = 17;
loc_8233F42C:
	// fmr f3,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f1.f64;
loc_8233F430:
	// fcfid f2,f0
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(ctx.f0.s64);
	// b 0x8233f39c
	goto loc_8233F39C;
loc_8233F438:
	// cmpwi cr6,r4,1024
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1024, ctx.xer);
	// ble cr6,0x8233f458
	if (!ctx.cr6.gt) goto loc_8233F458;
	// addi r4,r4,-1536
	ctx.r4.s64 = ctx.r4.s64 + -1536;
	// bl 0x82343ec8
	ctx.lr = 0x8233F448;
	sub_82343EC8(ctx, base);
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x8233f428
	goto loc_8233F428;
loc_8233F458:
	// cmpwi cr6,r4,-2557
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -2557, ctx.xer);
	// bge cr6,0x8233f478
	if (!ctx.cr6.lt) goto loc_8233F478;
loc_8233F460:
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// fmul f3,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f1.f64 * ctx.f30.f64;
	// li r3,18
	ctx.r3.s64 = 18;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x8233f430
	goto loc_8233F430;
loc_8233F478:
	// cmpwi cr6,r4,-1021
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1021, ctx.xer);
	// bge cr6,0x8233f49c
	if (!ctx.cr6.lt) goto loc_8233F49C;
	// addi r4,r4,1536
	ctx.r4.s64 = ctx.r4.s64 + 1536;
	// bl 0x82343ec8
	ctx.lr = 0x8233F488;
	sub_82343EC8(ctx, base);
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// li r3,18
	ctx.r3.s64 = 18;
	// std r11,88(r1)
	PPC_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = PPC_LOAD_U64(ctx.r1.u32 + 88);
	// b 0x8233f42c
	goto loc_8233F42C;
loc_8233F49C:
	// bl 0x82343ec8
	ctx.lr = 0x8233F4A0;
	sub_82343EC8(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
loc_8233F4A4:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82347d10
	ctx.lr = 0x8233F4B0;
	sub_82347D10(ctx, base);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
loc_8233F4B4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = PPC_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x8233e4bc
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_8233F4C4"))) PPC_WEAK_FUNC(sub_8233F4C4);
PPC_FUNC_IMPL(__imp__sub_8233F4C4) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233F4C8"))) PPC_WEAK_FUNC(sub_8233F4C8);
PPC_FUNC_IMPL(__imp__sub_8233F4C8) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp__sub_8233F4CC"))) PPC_WEAK_FUNC(sub_8233F4CC);
PPC_FUNC_IMPL(__imp__sub_8233F4CC) {
	PPC_FUNC_PROLOGUE();
	// .long 0x0
}

__attribute__((alias("__imp____savevmx_14"))) PPC_WEAK_FUNC(__savevmx_14);
PPC_FUNC_IMPL(__imp____savevmx_14) {
	PPC_FUNC_PROLOGUE();
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx v14,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr14 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr14 = ctx.v14.u32[0];
	*(volatile uint32_t*)(addr14 + 4) = ctx.v14.u32[1];
	*(volatile uint32_t*)(addr14 + 8) = ctx.v14.u32[2];
	*(volatile uint32_t*)(addr14 + 12) = ctx.v14.u32[3];
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx v15,r11,r12
	uint32_t addr15 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr15 = ctx.v15.u32[0];
	*(volatile uint32_t*)(addr15 + 4) = ctx.v15.u32[1];
	*(volatile uint32_t*)(addr15 + 8) = ctx.v15.u32[2];
	*(volatile uint32_t*)(addr15 + 12) = ctx.v15.u32[3];
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx v16,r11,r12
	uint32_t addr16 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr16 = ctx.v16.u32[0];
	*(volatile uint32_t*)(addr16 + 4) = ctx.v16.u32[1];
	*(volatile uint32_t*)(addr16 + 8) = ctx.v16.u32[2];
	*(volatile uint32_t*)(addr16 + 12) = ctx.v16.u32[3];
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx v17,r11,r12
	uint32_t addr17 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr17 = ctx.v17.u32[0];
	*(volatile uint32_t*)(addr17 + 4) = ctx.v17.u32[1];
	*(volatile uint32_t*)(addr17 + 8) = ctx.v17.u32[2];
	*(volatile uint32_t*)(addr17 + 12) = ctx.v17.u32[3];
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx v18,r11,r12
	uint32_t addr18 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr18 = ctx.v18.u32[0];
	*(volatile uint32_t*)(addr18 + 4) = ctx.v18.u32[1];
	*(volatile uint32_t*)(addr18 + 8) = ctx.v18.u32[2];
	*(volatile uint32_t*)(addr18 + 12) = ctx.v18.u32[3];
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx v19,r11,r12
	uint32_t addr19 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr19 = ctx.v19.u32[0];
	*(volatile uint32_t*)(addr19 + 4) = ctx.v19.u32[1];
	*(volatile uint32_t*)(addr19 + 8) = ctx.v19.u32[2];
	*(volatile uint32_t*)(addr19 + 12) = ctx.v19.u32[3];
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx v20,r11,r12
	uint32_t addr20 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr20 = ctx.v20.u32[0];
	*(volatile uint32_t*)(addr20 + 4) = ctx.v20.u32[1];
	*(volatile uint32_t*)(addr20 + 8) = ctx.v20.u32[2];
	*(volatile uint32_t*)(addr20 + 12) = ctx.v20.u32[3];
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx v21,r11,r12
	uint32_t addr21 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr21 = ctx.v21.u32[0];
	*(volatile uint32_t*)(addr21 + 4) = ctx.v21.u32[1];
	*(volatile uint32_t*)(addr21 + 8) = ctx.v21.u32[2];
	*(volatile uint32_t*)(addr21 + 12) = ctx.v21.u32[3];
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx v22,r11,r12
	uint32_t addr22 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr22 = ctx.v22.u32[0];
	*(volatile uint32_t*)(addr22 + 4) = ctx.v22.u32[1];
	*(volatile uint32_t*)(addr22 + 8) = ctx.v22.u32[2];
	*(volatile uint32_t*)(addr22 + 12) = ctx.v22.u32[3];
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx v23,r11,r12
	uint32_t addr23 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr23 = ctx.v23.u32[0];
	*(volatile uint32_t*)(addr23 + 4) = ctx.v23.u32[1];
	*(volatile uint32_t*)(addr23 + 8) = ctx.v23.u32[2];
	*(volatile uint32_t*)(addr23 + 12) = ctx.v23.u32[3];
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx v24,r11,r12
	uint32_t addr24 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr24 = ctx.v24.u32[0];
	*(volatile uint32_t*)(addr24 + 4) = ctx.v24.u32[1];
	*(volatile uint32_t*)(addr24 + 8) = ctx.v24.u32[2];
	*(volatile uint32_t*)(addr24 + 12) = ctx.v24.u32[3];
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx v25,r11,r12
	uint32_t addr25 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr25 = ctx.v25.u32[0];
	*(volatile uint32_t*)(addr25 + 4) = ctx.v25.u32[1];
	*(volatile uint32_t*)(addr25 + 8) = ctx.v25.u32[2];
	*(volatile uint32_t*)(addr25 + 12) = ctx.v25.u32[3];
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	uint32_t addr26 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr26 = ctx.v26.u32[0];
	*(volatile uint32_t*)(addr26 + 4) = ctx.v26.u32[1];
	*(volatile uint32_t*)(addr26 + 8) = ctx.v26.u32[2];
	*(volatile uint32_t*)(addr26 + 12) = ctx.v26.u32[3];
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_15"))) PPC_WEAK_FUNC(__savevmx_15);
PPC_FUNC_IMPL(__imp____savevmx_15) {
	PPC_FUNC_PROLOGUE();
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx v15,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr15 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr15 = ctx.v15.u32[0];
	*(volatile uint32_t*)(addr15 + 4) = ctx.v15.u32[1];
	*(volatile uint32_t*)(addr15 + 8) = ctx.v15.u32[2];
	*(volatile uint32_t*)(addr15 + 12) = ctx.v15.u32[3];
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx v16,r11,r12
	uint32_t addr16 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr16 = ctx.v16.u32[0];
	*(volatile uint32_t*)(addr16 + 4) = ctx.v16.u32[1];
	*(volatile uint32_t*)(addr16 + 8) = ctx.v16.u32[2];
	*(volatile uint32_t*)(addr16 + 12) = ctx.v16.u32[3];
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx v17,r11,r12
	uint32_t addr17 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr17 = ctx.v17.u32[0];
	*(volatile uint32_t*)(addr17 + 4) = ctx.v17.u32[1];
	*(volatile uint32_t*)(addr17 + 8) = ctx.v17.u32[2];
	*(volatile uint32_t*)(addr17 + 12) = ctx.v17.u32[3];
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx v18,r11,r12
	uint32_t addr18 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr18 = ctx.v18.u32[0];
	*(volatile uint32_t*)(addr18 + 4) = ctx.v18.u32[1];
	*(volatile uint32_t*)(addr18 + 8) = ctx.v18.u32[2];
	*(volatile uint32_t*)(addr18 + 12) = ctx.v18.u32[3];
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx v19,r11,r12
	uint32_t addr19 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr19 = ctx.v19.u32[0];
	*(volatile uint32_t*)(addr19 + 4) = ctx.v19.u32[1];
	*(volatile uint32_t*)(addr19 + 8) = ctx.v19.u32[2];
	*(volatile uint32_t*)(addr19 + 12) = ctx.v19.u32[3];
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx v20,r11,r12
	uint32_t addr20 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr20 = ctx.v20.u32[0];
	*(volatile uint32_t*)(addr20 + 4) = ctx.v20.u32[1];
	*(volatile uint32_t*)(addr20 + 8) = ctx.v20.u32[2];
	*(volatile uint32_t*)(addr20 + 12) = ctx.v20.u32[3];
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx v21,r11,r12
	uint32_t addr21 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr21 = ctx.v21.u32[0];
	*(volatile uint32_t*)(addr21 + 4) = ctx.v21.u32[1];
	*(volatile uint32_t*)(addr21 + 8) = ctx.v21.u32[2];
	*(volatile uint32_t*)(addr21 + 12) = ctx.v21.u32[3];
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx v22,r11,r12
	uint32_t addr22 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr22 = ctx.v22.u32[0];
	*(volatile uint32_t*)(addr22 + 4) = ctx.v22.u32[1];
	*(volatile uint32_t*)(addr22 + 8) = ctx.v22.u32[2];
	*(volatile uint32_t*)(addr22 + 12) = ctx.v22.u32[3];
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx v23,r11,r12
	uint32_t addr23 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr23 = ctx.v23.u32[0];
	*(volatile uint32_t*)(addr23 + 4) = ctx.v23.u32[1];
	*(volatile uint32_t*)(addr23 + 8) = ctx.v23.u32[2];
	*(volatile uint32_t*)(addr23 + 12) = ctx.v23.u32[3];
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx v24,r11,r12
	uint32_t addr24 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr24 = ctx.v24.u32[0];
	*(volatile uint32_t*)(addr24 + 4) = ctx.v24.u32[1];
	*(volatile uint32_t*)(addr24 + 8) = ctx.v24.u32[2];
	*(volatile uint32_t*)(addr24 + 12) = ctx.v24.u32[3];
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx v25,r11,r12
	uint32_t addr25 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr25 = ctx.v25.u32[0];
	*(volatile uint32_t*)(addr25 + 4) = ctx.v25.u32[1];
	*(volatile uint32_t*)(addr25 + 8) = ctx.v25.u32[2];
	*(volatile uint32_t*)(addr25 + 12) = ctx.v25.u32[3];
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	uint32_t addr26 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr26 = ctx.v26.u32[0];
	*(volatile uint32_t*)(addr26 + 4) = ctx.v26.u32[1];
	*(volatile uint32_t*)(addr26 + 8) = ctx.v26.u32[2];
	*(volatile uint32_t*)(addr26 + 12) = ctx.v26.u32[3];
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_16"))) PPC_WEAK_FUNC(__savevmx_16);
PPC_FUNC_IMPL(__imp____savevmx_16) {
	PPC_FUNC_PROLOGUE();
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx v16,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr16 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr16 = ctx.v16.u32[0];
	*(volatile uint32_t*)(addr16 + 4) = ctx.v16.u32[1];
	*(volatile uint32_t*)(addr16 + 8) = ctx.v16.u32[2];
	*(volatile uint32_t*)(addr16 + 12) = ctx.v16.u32[3];
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx v17,r11,r12
	uint32_t addr17 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr17 = ctx.v17.u32[0];
	*(volatile uint32_t*)(addr17 + 4) = ctx.v17.u32[1];
	*(volatile uint32_t*)(addr17 + 8) = ctx.v17.u32[2];
	*(volatile uint32_t*)(addr17 + 12) = ctx.v17.u32[3];
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx v18,r11,r12
	uint32_t addr18 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr18 = ctx.v18.u32[0];
	*(volatile uint32_t*)(addr18 + 4) = ctx.v18.u32[1];
	*(volatile uint32_t*)(addr18 + 8) = ctx.v18.u32[2];
	*(volatile uint32_t*)(addr18 + 12) = ctx.v18.u32[3];
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx v19,r11,r12
	uint32_t addr19 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr19 = ctx.v19.u32[0];
	*(volatile uint32_t*)(addr19 + 4) = ctx.v19.u32[1];
	*(volatile uint32_t*)(addr19 + 8) = ctx.v19.u32[2];
	*(volatile uint32_t*)(addr19 + 12) = ctx.v19.u32[3];
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx v20,r11,r12
	uint32_t addr20 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr20 = ctx.v20.u32[0];
	*(volatile uint32_t*)(addr20 + 4) = ctx.v20.u32[1];
	*(volatile uint32_t*)(addr20 + 8) = ctx.v20.u32[2];
	*(volatile uint32_t*)(addr20 + 12) = ctx.v20.u32[3];
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx v21,r11,r12
	uint32_t addr21 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr21 = ctx.v21.u32[0];
	*(volatile uint32_t*)(addr21 + 4) = ctx.v21.u32[1];
	*(volatile uint32_t*)(addr21 + 8) = ctx.v21.u32[2];
	*(volatile uint32_t*)(addr21 + 12) = ctx.v21.u32[3];
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx v22,r11,r12
	uint32_t addr22 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr22 = ctx.v22.u32[0];
	*(volatile uint32_t*)(addr22 + 4) = ctx.v22.u32[1];
	*(volatile uint32_t*)(addr22 + 8) = ctx.v22.u32[2];
	*(volatile uint32_t*)(addr22 + 12) = ctx.v22.u32[3];
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx v23,r11,r12
	uint32_t addr23 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr23 = ctx.v23.u32[0];
	*(volatile uint32_t*)(addr23 + 4) = ctx.v23.u32[1];
	*(volatile uint32_t*)(addr23 + 8) = ctx.v23.u32[2];
	*(volatile uint32_t*)(addr23 + 12) = ctx.v23.u32[3];
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx v24,r11,r12
	uint32_t addr24 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr24 = ctx.v24.u32[0];
	*(volatile uint32_t*)(addr24 + 4) = ctx.v24.u32[1];
	*(volatile uint32_t*)(addr24 + 8) = ctx.v24.u32[2];
	*(volatile uint32_t*)(addr24 + 12) = ctx.v24.u32[3];
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx v25,r11,r12
	uint32_t addr25 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr25 = ctx.v25.u32[0];
	*(volatile uint32_t*)(addr25 + 4) = ctx.v25.u32[1];
	*(volatile uint32_t*)(addr25 + 8) = ctx.v25.u32[2];
	*(volatile uint32_t*)(addr25 + 12) = ctx.v25.u32[3];
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	uint32_t addr26 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr26 = ctx.v26.u32[0];
	*(volatile uint32_t*)(addr26 + 4) = ctx.v26.u32[1];
	*(volatile uint32_t*)(addr26 + 8) = ctx.v26.u32[2];
	*(volatile uint32_t*)(addr26 + 12) = ctx.v26.u32[3];
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_17"))) PPC_WEAK_FUNC(__savevmx_17);
PPC_FUNC_IMPL(__imp____savevmx_17) {
	PPC_FUNC_PROLOGUE();
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx v17,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr17 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr17 = ctx.v17.u32[0];
	*(volatile uint32_t*)(addr17 + 4) = ctx.v17.u32[1];
	*(volatile uint32_t*)(addr17 + 8) = ctx.v17.u32[2];
	*(volatile uint32_t*)(addr17 + 12) = ctx.v17.u32[3];
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx v18,r11,r12
	uint32_t addr18 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr18 = ctx.v18.u32[0];
	*(volatile uint32_t*)(addr18 + 4) = ctx.v18.u32[1];
	*(volatile uint32_t*)(addr18 + 8) = ctx.v18.u32[2];
	*(volatile uint32_t*)(addr18 + 12) = ctx.v18.u32[3];
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx v19,r11,r12
	uint32_t addr19 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr19 = ctx.v19.u32[0];
	*(volatile uint32_t*)(addr19 + 4) = ctx.v19.u32[1];
	*(volatile uint32_t*)(addr19 + 8) = ctx.v19.u32[2];
	*(volatile uint32_t*)(addr19 + 12) = ctx.v19.u32[3];
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx v20,r11,r12
	uint32_t addr20 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr20 = ctx.v20.u32[0];
	*(volatile uint32_t*)(addr20 + 4) = ctx.v20.u32[1];
	*(volatile uint32_t*)(addr20 + 8) = ctx.v20.u32[2];
	*(volatile uint32_t*)(addr20 + 12) = ctx.v20.u32[3];
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx v21,r11,r12
	uint32_t addr21 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr21 = ctx.v21.u32[0];
	*(volatile uint32_t*)(addr21 + 4) = ctx.v21.u32[1];
	*(volatile uint32_t*)(addr21 + 8) = ctx.v21.u32[2];
	*(volatile uint32_t*)(addr21 + 12) = ctx.v21.u32[3];
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx v22,r11,r12
	uint32_t addr22 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr22 = ctx.v22.u32[0];
	*(volatile uint32_t*)(addr22 + 4) = ctx.v22.u32[1];
	*(volatile uint32_t*)(addr22 + 8) = ctx.v22.u32[2];
	*(volatile uint32_t*)(addr22 + 12) = ctx.v22.u32[3];
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx v23,r11,r12
	uint32_t addr23 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr23 = ctx.v23.u32[0];
	*(volatile uint32_t*)(addr23 + 4) = ctx.v23.u32[1];
	*(volatile uint32_t*)(addr23 + 8) = ctx.v23.u32[2];
	*(volatile uint32_t*)(addr23 + 12) = ctx.v23.u32[3];
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx v24,r11,r12
	uint32_t addr24 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr24 = ctx.v24.u32[0];
	*(volatile uint32_t*)(addr24 + 4) = ctx.v24.u32[1];
	*(volatile uint32_t*)(addr24 + 8) = ctx.v24.u32[2];
	*(volatile uint32_t*)(addr24 + 12) = ctx.v24.u32[3];
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx v25,r11,r12
	uint32_t addr25 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr25 = ctx.v25.u32[0];
	*(volatile uint32_t*)(addr25 + 4) = ctx.v25.u32[1];
	*(volatile uint32_t*)(addr25 + 8) = ctx.v25.u32[2];
	*(volatile uint32_t*)(addr25 + 12) = ctx.v25.u32[3];
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	uint32_t addr26 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr26 = ctx.v26.u32[0];
	*(volatile uint32_t*)(addr26 + 4) = ctx.v26.u32[1];
	*(volatile uint32_t*)(addr26 + 8) = ctx.v26.u32[2];
	*(volatile uint32_t*)(addr26 + 12) = ctx.v26.u32[3];
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_18"))) PPC_WEAK_FUNC(__savevmx_18);
PPC_FUNC_IMPL(__imp____savevmx_18) {
	PPC_FUNC_PROLOGUE();
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx v18,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr18 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr18 = ctx.v18.u32[0];
	*(volatile uint32_t*)(addr18 + 4) = ctx.v18.u32[1];
	*(volatile uint32_t*)(addr18 + 8) = ctx.v18.u32[2];
	*(volatile uint32_t*)(addr18 + 12) = ctx.v18.u32[3];
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx v19,r11,r12
	uint32_t addr19 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr19 = ctx.v19.u32[0];
	*(volatile uint32_t*)(addr19 + 4) = ctx.v19.u32[1];
	*(volatile uint32_t*)(addr19 + 8) = ctx.v19.u32[2];
	*(volatile uint32_t*)(addr19 + 12) = ctx.v19.u32[3];
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx v20,r11,r12
	uint32_t addr20 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr20 = ctx.v20.u32[0];
	*(volatile uint32_t*)(addr20 + 4) = ctx.v20.u32[1];
	*(volatile uint32_t*)(addr20 + 8) = ctx.v20.u32[2];
	*(volatile uint32_t*)(addr20 + 12) = ctx.v20.u32[3];
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx v21,r11,r12
	uint32_t addr21 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr21 = ctx.v21.u32[0];
	*(volatile uint32_t*)(addr21 + 4) = ctx.v21.u32[1];
	*(volatile uint32_t*)(addr21 + 8) = ctx.v21.u32[2];
	*(volatile uint32_t*)(addr21 + 12) = ctx.v21.u32[3];
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx v22,r11,r12
	uint32_t addr22 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr22 = ctx.v22.u32[0];
	*(volatile uint32_t*)(addr22 + 4) = ctx.v22.u32[1];
	*(volatile uint32_t*)(addr22 + 8) = ctx.v22.u32[2];
	*(volatile uint32_t*)(addr22 + 12) = ctx.v22.u32[3];
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx v23,r11,r12
	uint32_t addr23 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr23 = ctx.v23.u32[0];
	*(volatile uint32_t*)(addr23 + 4) = ctx.v23.u32[1];
	*(volatile uint32_t*)(addr23 + 8) = ctx.v23.u32[2];
	*(volatile uint32_t*)(addr23 + 12) = ctx.v23.u32[3];
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx v24,r11,r12
	uint32_t addr24 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr24 = ctx.v24.u32[0];
	*(volatile uint32_t*)(addr24 + 4) = ctx.v24.u32[1];
	*(volatile uint32_t*)(addr24 + 8) = ctx.v24.u32[2];
	*(volatile uint32_t*)(addr24 + 12) = ctx.v24.u32[3];
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx v25,r11,r12
	uint32_t addr25 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr25 = ctx.v25.u32[0];
	*(volatile uint32_t*)(addr25 + 4) = ctx.v25.u32[1];
	*(volatile uint32_t*)(addr25 + 8) = ctx.v25.u32[2];
	*(volatile uint32_t*)(addr25 + 12) = ctx.v25.u32[3];
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	uint32_t addr26 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr26 = ctx.v26.u32[0];
	*(volatile uint32_t*)(addr26 + 4) = ctx.v26.u32[1];
	*(volatile uint32_t*)(addr26 + 8) = ctx.v26.u32[2];
	*(volatile uint32_t*)(addr26 + 12) = ctx.v26.u32[3];
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_19"))) PPC_WEAK_FUNC(__savevmx_19);
PPC_FUNC_IMPL(__imp____savevmx_19) {
	PPC_FUNC_PROLOGUE();
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx v19,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr19 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr19 = ctx.v19.u32[0];
	*(volatile uint32_t*)(addr19 + 4) = ctx.v19.u32[1];
	*(volatile uint32_t*)(addr19 + 8) = ctx.v19.u32[2];
	*(volatile uint32_t*)(addr19 + 12) = ctx.v19.u32[3];
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx v20,r11,r12
	uint32_t addr20 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr20 = ctx.v20.u32[0];
	*(volatile uint32_t*)(addr20 + 4) = ctx.v20.u32[1];
	*(volatile uint32_t*)(addr20 + 8) = ctx.v20.u32[2];
	*(volatile uint32_t*)(addr20 + 12) = ctx.v20.u32[3];
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx v21,r11,r12
	uint32_t addr21 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr21 = ctx.v21.u32[0];
	*(volatile uint32_t*)(addr21 + 4) = ctx.v21.u32[1];
	*(volatile uint32_t*)(addr21 + 8) = ctx.v21.u32[2];
	*(volatile uint32_t*)(addr21 + 12) = ctx.v21.u32[3];
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx v22,r11,r12
	uint32_t addr22 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr22 = ctx.v22.u32[0];
	*(volatile uint32_t*)(addr22 + 4) = ctx.v22.u32[1];
	*(volatile uint32_t*)(addr22 + 8) = ctx.v22.u32[2];
	*(volatile uint32_t*)(addr22 + 12) = ctx.v22.u32[3];
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx v23,r11,r12
	uint32_t addr23 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr23 = ctx.v23.u32[0];
	*(volatile uint32_t*)(addr23 + 4) = ctx.v23.u32[1];
	*(volatile uint32_t*)(addr23 + 8) = ctx.v23.u32[2];
	*(volatile uint32_t*)(addr23 + 12) = ctx.v23.u32[3];
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx v24,r11,r12
	uint32_t addr24 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr24 = ctx.v24.u32[0];
	*(volatile uint32_t*)(addr24 + 4) = ctx.v24.u32[1];
	*(volatile uint32_t*)(addr24 + 8) = ctx.v24.u32[2];
	*(volatile uint32_t*)(addr24 + 12) = ctx.v24.u32[3];
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx v25,r11,r12
	uint32_t addr25 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr25 = ctx.v25.u32[0];
	*(volatile uint32_t*)(addr25 + 4) = ctx.v25.u32[1];
	*(volatile uint32_t*)(addr25 + 8) = ctx.v25.u32[2];
	*(volatile uint32_t*)(addr25 + 12) = ctx.v25.u32[3];
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	uint32_t addr26 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr26 = ctx.v26.u32[0];
	*(volatile uint32_t*)(addr26 + 4) = ctx.v26.u32[1];
	*(volatile uint32_t*)(addr26 + 8) = ctx.v26.u32[2];
	*(volatile uint32_t*)(addr26 + 12) = ctx.v26.u32[3];
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_20"))) PPC_WEAK_FUNC(__savevmx_20);
PPC_FUNC_IMPL(__imp____savevmx_20) {
	PPC_FUNC_PROLOGUE();
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx v20,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr20 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr20 = ctx.v20.u32[0];
	*(volatile uint32_t*)(addr20 + 4) = ctx.v20.u32[1];
	*(volatile uint32_t*)(addr20 + 8) = ctx.v20.u32[2];
	*(volatile uint32_t*)(addr20 + 12) = ctx.v20.u32[3];
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx v21,r11,r12
	uint32_t addr21 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr21 = ctx.v21.u32[0];
	*(volatile uint32_t*)(addr21 + 4) = ctx.v21.u32[1];
	*(volatile uint32_t*)(addr21 + 8) = ctx.v21.u32[2];
	*(volatile uint32_t*)(addr21 + 12) = ctx.v21.u32[3];
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx v22,r11,r12
	uint32_t addr22 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr22 = ctx.v22.u32[0];
	*(volatile uint32_t*)(addr22 + 4) = ctx.v22.u32[1];
	*(volatile uint32_t*)(addr22 + 8) = ctx.v22.u32[2];
	*(volatile uint32_t*)(addr22 + 12) = ctx.v22.u32[3];
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx v23,r11,r12
	uint32_t addr23 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr23 = ctx.v23.u32[0];
	*(volatile uint32_t*)(addr23 + 4) = ctx.v23.u32[1];
	*(volatile uint32_t*)(addr23 + 8) = ctx.v23.u32[2];
	*(volatile uint32_t*)(addr23 + 12) = ctx.v23.u32[3];
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx v24,r11,r12
	uint32_t addr24 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr24 = ctx.v24.u32[0];
	*(volatile uint32_t*)(addr24 + 4) = ctx.v24.u32[1];
	*(volatile uint32_t*)(addr24 + 8) = ctx.v24.u32[2];
	*(volatile uint32_t*)(addr24 + 12) = ctx.v24.u32[3];
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx v25,r11,r12
	uint32_t addr25 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr25 = ctx.v25.u32[0];
	*(volatile uint32_t*)(addr25 + 4) = ctx.v25.u32[1];
	*(volatile uint32_t*)(addr25 + 8) = ctx.v25.u32[2];
	*(volatile uint32_t*)(addr25 + 12) = ctx.v25.u32[3];
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	uint32_t addr26 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr26 = ctx.v26.u32[0];
	*(volatile uint32_t*)(addr26 + 4) = ctx.v26.u32[1];
	*(volatile uint32_t*)(addr26 + 8) = ctx.v26.u32[2];
	*(volatile uint32_t*)(addr26 + 12) = ctx.v26.u32[3];
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_21"))) PPC_WEAK_FUNC(__savevmx_21);
PPC_FUNC_IMPL(__imp____savevmx_21) {
	PPC_FUNC_PROLOGUE();
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx v21,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr21 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr21 = ctx.v21.u32[0];
	*(volatile uint32_t*)(addr21 + 4) = ctx.v21.u32[1];
	*(volatile uint32_t*)(addr21 + 8) = ctx.v21.u32[2];
	*(volatile uint32_t*)(addr21 + 12) = ctx.v21.u32[3];
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx v22,r11,r12
	uint32_t addr22 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr22 = ctx.v22.u32[0];
	*(volatile uint32_t*)(addr22 + 4) = ctx.v22.u32[1];
	*(volatile uint32_t*)(addr22 + 8) = ctx.v22.u32[2];
	*(volatile uint32_t*)(addr22 + 12) = ctx.v22.u32[3];
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx v23,r11,r12
	uint32_t addr23 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr23 = ctx.v23.u32[0];
	*(volatile uint32_t*)(addr23 + 4) = ctx.v23.u32[1];
	*(volatile uint32_t*)(addr23 + 8) = ctx.v23.u32[2];
	*(volatile uint32_t*)(addr23 + 12) = ctx.v23.u32[3];
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx v24,r11,r12
	uint32_t addr24 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr24 = ctx.v24.u32[0];
	*(volatile uint32_t*)(addr24 + 4) = ctx.v24.u32[1];
	*(volatile uint32_t*)(addr24 + 8) = ctx.v24.u32[2];
	*(volatile uint32_t*)(addr24 + 12) = ctx.v24.u32[3];
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx v25,r11,r12
	uint32_t addr25 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr25 = ctx.v25.u32[0];
	*(volatile uint32_t*)(addr25 + 4) = ctx.v25.u32[1];
	*(volatile uint32_t*)(addr25 + 8) = ctx.v25.u32[2];
	*(volatile uint32_t*)(addr25 + 12) = ctx.v25.u32[3];
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	uint32_t addr26 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr26 = ctx.v26.u32[0];
	*(volatile uint32_t*)(addr26 + 4) = ctx.v26.u32[1];
	*(volatile uint32_t*)(addr26 + 8) = ctx.v26.u32[2];
	*(volatile uint32_t*)(addr26 + 12) = ctx.v26.u32[3];
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_22"))) PPC_WEAK_FUNC(__savevmx_22);
PPC_FUNC_IMPL(__imp____savevmx_22) {
	PPC_FUNC_PROLOGUE();
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx v22,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr22 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr22 = ctx.v22.u32[0];
	*(volatile uint32_t*)(addr22 + 4) = ctx.v22.u32[1];
	*(volatile uint32_t*)(addr22 + 8) = ctx.v22.u32[2];
	*(volatile uint32_t*)(addr22 + 12) = ctx.v22.u32[3];
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx v23,r11,r12
	uint32_t addr23 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr23 = ctx.v23.u32[0];
	*(volatile uint32_t*)(addr23 + 4) = ctx.v23.u32[1];
	*(volatile uint32_t*)(addr23 + 8) = ctx.v23.u32[2];
	*(volatile uint32_t*)(addr23 + 12) = ctx.v23.u32[3];
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx v24,r11,r12
	uint32_t addr24 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr24 = ctx.v24.u32[0];
	*(volatile uint32_t*)(addr24 + 4) = ctx.v24.u32[1];
	*(volatile uint32_t*)(addr24 + 8) = ctx.v24.u32[2];
	*(volatile uint32_t*)(addr24 + 12) = ctx.v24.u32[3];
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx v25,r11,r12
	uint32_t addr25 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr25 = ctx.v25.u32[0];
	*(volatile uint32_t*)(addr25 + 4) = ctx.v25.u32[1];
	*(volatile uint32_t*)(addr25 + 8) = ctx.v25.u32[2];
	*(volatile uint32_t*)(addr25 + 12) = ctx.v25.u32[3];
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	uint32_t addr26 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr26 = ctx.v26.u32[0];
	*(volatile uint32_t*)(addr26 + 4) = ctx.v26.u32[1];
	*(volatile uint32_t*)(addr26 + 8) = ctx.v26.u32[2];
	*(volatile uint32_t*)(addr26 + 12) = ctx.v26.u32[3];
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_23"))) PPC_WEAK_FUNC(__savevmx_23);
PPC_FUNC_IMPL(__imp____savevmx_23) {
	PPC_FUNC_PROLOGUE();
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx v23,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr23 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr23 = ctx.v23.u32[0];
	*(volatile uint32_t*)(addr23 + 4) = ctx.v23.u32[1];
	*(volatile uint32_t*)(addr23 + 8) = ctx.v23.u32[2];
	*(volatile uint32_t*)(addr23 + 12) = ctx.v23.u32[3];
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx v24,r11,r12
	uint32_t addr24 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr24 = ctx.v24.u32[0];
	*(volatile uint32_t*)(addr24 + 4) = ctx.v24.u32[1];
	*(volatile uint32_t*)(addr24 + 8) = ctx.v24.u32[2];
	*(volatile uint32_t*)(addr24 + 12) = ctx.v24.u32[3];
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx v25,r11,r12
	uint32_t addr25 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr25 = ctx.v25.u32[0];
	*(volatile uint32_t*)(addr25 + 4) = ctx.v25.u32[1];
	*(volatile uint32_t*)(addr25 + 8) = ctx.v25.u32[2];
	*(volatile uint32_t*)(addr25 + 12) = ctx.v25.u32[3];
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	uint32_t addr26 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr26 = ctx.v26.u32[0];
	*(volatile uint32_t*)(addr26 + 4) = ctx.v26.u32[1];
	*(volatile uint32_t*)(addr26 + 8) = ctx.v26.u32[2];
	*(volatile uint32_t*)(addr26 + 12) = ctx.v26.u32[3];
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_24"))) PPC_WEAK_FUNC(__savevmx_24);
PPC_FUNC_IMPL(__imp____savevmx_24) {
	PPC_FUNC_PROLOGUE();
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx v24,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr24 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr24 = ctx.v24.u32[0];
	*(volatile uint32_t*)(addr24 + 4) = ctx.v24.u32[1];
	*(volatile uint32_t*)(addr24 + 8) = ctx.v24.u32[2];
	*(volatile uint32_t*)(addr24 + 12) = ctx.v24.u32[3];
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx v25,r11,r12
	uint32_t addr25 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr25 = ctx.v25.u32[0];
	*(volatile uint32_t*)(addr25 + 4) = ctx.v25.u32[1];
	*(volatile uint32_t*)(addr25 + 8) = ctx.v25.u32[2];
	*(volatile uint32_t*)(addr25 + 12) = ctx.v25.u32[3];
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	uint32_t addr26 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr26 = ctx.v26.u32[0];
	*(volatile uint32_t*)(addr26 + 4) = ctx.v26.u32[1];
	*(volatile uint32_t*)(addr26 + 8) = ctx.v26.u32[2];
	*(volatile uint32_t*)(addr26 + 12) = ctx.v26.u32[3];
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_25"))) PPC_WEAK_FUNC(__savevmx_25);
PPC_FUNC_IMPL(__imp____savevmx_25) {
	PPC_FUNC_PROLOGUE();
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx v25,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr25 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr25 = ctx.v25.u32[0];
	*(volatile uint32_t*)(addr25 + 4) = ctx.v25.u32[1];
	*(volatile uint32_t*)(addr25 + 8) = ctx.v25.u32[2];
	*(volatile uint32_t*)(addr25 + 12) = ctx.v25.u32[3];
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	uint32_t addr26 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr26 = ctx.v26.u32[0];
	*(volatile uint32_t*)(addr26 + 4) = ctx.v26.u32[1];
	*(volatile uint32_t*)(addr26 + 8) = ctx.v26.u32[2];
	*(volatile uint32_t*)(addr26 + 12) = ctx.v26.u32[3];
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_26"))) PPC_WEAK_FUNC(__savevmx_26);
PPC_FUNC_IMPL(__imp____savevmx_26) {
	PPC_FUNC_PROLOGUE();
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx v26,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr26 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr26 = ctx.v26.u32[0];
	*(volatile uint32_t*)(addr26 + 4) = ctx.v26.u32[1];
	*(volatile uint32_t*)(addr26 + 8) = ctx.v26.u32[2];
	*(volatile uint32_t*)(addr26 + 12) = ctx.v26.u32[3];
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_27"))) PPC_WEAK_FUNC(__savevmx_27);
PPC_FUNC_IMPL(__imp____savevmx_27) {
	PPC_FUNC_PROLOGUE();
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr27 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr27 = ctx.v27.u32[0];
	*(volatile uint32_t*)(addr27 + 4) = ctx.v27.u32[1];
	*(volatile uint32_t*)(addr27 + 8) = ctx.v27.u32[2];
	*(volatile uint32_t*)(addr27 + 12) = ctx.v27.u32[3];
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_28"))) PPC_WEAK_FUNC(__savevmx_28);
PPC_FUNC_IMPL(__imp____savevmx_28) {
	PPC_FUNC_PROLOGUE();
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr28 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr28 = ctx.v28.u32[0];
	*(volatile uint32_t*)(addr28 + 4) = ctx.v28.u32[1];
	*(volatile uint32_t*)(addr28 + 8) = ctx.v28.u32[2];
	*(volatile uint32_t*)(addr28 + 12) = ctx.v28.u32[3];
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_29"))) PPC_WEAK_FUNC(__savevmx_29);
PPC_FUNC_IMPL(__imp____savevmx_29) {
	PPC_FUNC_PROLOGUE();
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr29 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr29 = ctx.v29.u32[0];
	*(volatile uint32_t*)(addr29 + 4) = ctx.v29.u32[1];
	*(volatile uint32_t*)(addr29 + 8) = ctx.v29.u32[2];
	*(volatile uint32_t*)(addr29 + 12) = ctx.v29.u32[3];
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_30"))) PPC_WEAK_FUNC(__savevmx_30);
PPC_FUNC_IMPL(__imp____savevmx_30) {
	PPC_FUNC_PROLOGUE();
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr30 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr30 = ctx.v30.u32[0];
	*(volatile uint32_t*)(addr30 + 4) = ctx.v30.u32[1];
	*(volatile uint32_t*)(addr30 + 8) = ctx.v30.u32[2];
	*(volatile uint32_t*)(addr30 + 12) = ctx.v30.u32[3];
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_31"))) PPC_WEAK_FUNC(__savevmx_31);
PPC_FUNC_IMPL(__imp____savevmx_31) {
	PPC_FUNC_PROLOGUE();
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	ctx.fpscr.enableFlushMode();
	uint32_t addr31 = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	*(volatile uint32_t*)addr31 = ctx.v31.u32[0];
	*(volatile uint32_t*)(addr31 + 4) = ctx.v31.u32[1];
	*(volatile uint32_t*)(addr31 + 8) = ctx.v31.u32[2];
	*(volatile uint32_t*)(addr31 + 12) = ctx.v31.u32[3];
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_64"))) PPC_WEAK_FUNC(__savevmx_64);
PPC_FUNC_IMPL(__imp____savevmx_64) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-1024
	ctx.r11.s64 = -1024;
	// stvx128 v64,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v64), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-1008
	ctx.r11.s64 = -1008;
	// stvx128 v65,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v65), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-992
	ctx.r11.s64 = -992;
	// stvx128 v66,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v66), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-976
	ctx.r11.s64 = -976;
	// stvx128 v67,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v67), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-960
	ctx.r11.s64 = -960;
	// stvx128 v68,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v68), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-944
	ctx.r11.s64 = -944;
	// stvx128 v69,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v69), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-928
	ctx.r11.s64 = -928;
	// stvx128 v70,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v70), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-912
	ctx.r11.s64 = -912;
	// stvx128 v71,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v71), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-896
	ctx.r11.s64 = -896;
	// stvx128 v72,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v72), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-880
	ctx.r11.s64 = -880;
	// stvx128 v73,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v73), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-864
	ctx.r11.s64 = -864;
	// stvx128 v74,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v74), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-848
	ctx.r11.s64 = -848;
	// stvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v75), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v76), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_65"))) PPC_WEAK_FUNC(__savevmx_65);
PPC_FUNC_IMPL(__imp____savevmx_65) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-1008
	ctx.r11.s64 = -1008;
	// stvx128 v65,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v65), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-992
	ctx.r11.s64 = -992;
	// stvx128 v66,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v66), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-976
	ctx.r11.s64 = -976;
	// stvx128 v67,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v67), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-960
	ctx.r11.s64 = -960;
	// stvx128 v68,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v68), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-944
	ctx.r11.s64 = -944;
	// stvx128 v69,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v69), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-928
	ctx.r11.s64 = -928;
	// stvx128 v70,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v70), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-912
	ctx.r11.s64 = -912;
	// stvx128 v71,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v71), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-896
	ctx.r11.s64 = -896;
	// stvx128 v72,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v72), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-880
	ctx.r11.s64 = -880;
	// stvx128 v73,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v73), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-864
	ctx.r11.s64 = -864;
	// stvx128 v74,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v74), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-848
	ctx.r11.s64 = -848;
	// stvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v75), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v76), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_66"))) PPC_WEAK_FUNC(__savevmx_66);
PPC_FUNC_IMPL(__imp____savevmx_66) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-992
	ctx.r11.s64 = -992;
	// stvx128 v66,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v66), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-976
	ctx.r11.s64 = -976;
	// stvx128 v67,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v67), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-960
	ctx.r11.s64 = -960;
	// stvx128 v68,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v68), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-944
	ctx.r11.s64 = -944;
	// stvx128 v69,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v69), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-928
	ctx.r11.s64 = -928;
	// stvx128 v70,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v70), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-912
	ctx.r11.s64 = -912;
	// stvx128 v71,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v71), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-896
	ctx.r11.s64 = -896;
	// stvx128 v72,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v72), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-880
	ctx.r11.s64 = -880;
	// stvx128 v73,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v73), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-864
	ctx.r11.s64 = -864;
	// stvx128 v74,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v74), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-848
	ctx.r11.s64 = -848;
	// stvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v75), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v76), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_67"))) PPC_WEAK_FUNC(__savevmx_67);
PPC_FUNC_IMPL(__imp____savevmx_67) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-976
	ctx.r11.s64 = -976;
	// stvx128 v67,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v67), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-960
	ctx.r11.s64 = -960;
	// stvx128 v68,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v68), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-944
	ctx.r11.s64 = -944;
	// stvx128 v69,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v69), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-928
	ctx.r11.s64 = -928;
	// stvx128 v70,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v70), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-912
	ctx.r11.s64 = -912;
	// stvx128 v71,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v71), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-896
	ctx.r11.s64 = -896;
	// stvx128 v72,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v72), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-880
	ctx.r11.s64 = -880;
	// stvx128 v73,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v73), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-864
	ctx.r11.s64 = -864;
	// stvx128 v74,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v74), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-848
	ctx.r11.s64 = -848;
	// stvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v75), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v76), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_68"))) PPC_WEAK_FUNC(__savevmx_68);
PPC_FUNC_IMPL(__imp____savevmx_68) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-960
	ctx.r11.s64 = -960;
	// stvx128 v68,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v68), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-944
	ctx.r11.s64 = -944;
	// stvx128 v69,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v69), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-928
	ctx.r11.s64 = -928;
	// stvx128 v70,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v70), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-912
	ctx.r11.s64 = -912;
	// stvx128 v71,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v71), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-896
	ctx.r11.s64 = -896;
	// stvx128 v72,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v72), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-880
	ctx.r11.s64 = -880;
	// stvx128 v73,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v73), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-864
	ctx.r11.s64 = -864;
	// stvx128 v74,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v74), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-848
	ctx.r11.s64 = -848;
	// stvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v75), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v76), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_69"))) PPC_WEAK_FUNC(__savevmx_69);
PPC_FUNC_IMPL(__imp____savevmx_69) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-944
	ctx.r11.s64 = -944;
	// stvx128 v69,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v69), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-928
	ctx.r11.s64 = -928;
	// stvx128 v70,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v70), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-912
	ctx.r11.s64 = -912;
	// stvx128 v71,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v71), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-896
	ctx.r11.s64 = -896;
	// stvx128 v72,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v72), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-880
	ctx.r11.s64 = -880;
	// stvx128 v73,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v73), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-864
	ctx.r11.s64 = -864;
	// stvx128 v74,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v74), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-848
	ctx.r11.s64 = -848;
	// stvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v75), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v76), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_70"))) PPC_WEAK_FUNC(__savevmx_70);
PPC_FUNC_IMPL(__imp____savevmx_70) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-928
	ctx.r11.s64 = -928;
	// stvx128 v70,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v70), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-912
	ctx.r11.s64 = -912;
	// stvx128 v71,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v71), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-896
	ctx.r11.s64 = -896;
	// stvx128 v72,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v72), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-880
	ctx.r11.s64 = -880;
	// stvx128 v73,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v73), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-864
	ctx.r11.s64 = -864;
	// stvx128 v74,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v74), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-848
	ctx.r11.s64 = -848;
	// stvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v75), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v76), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_71"))) PPC_WEAK_FUNC(__savevmx_71);
PPC_FUNC_IMPL(__imp____savevmx_71) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-912
	ctx.r11.s64 = -912;
	// stvx128 v71,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v71), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-896
	ctx.r11.s64 = -896;
	// stvx128 v72,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v72), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-880
	ctx.r11.s64 = -880;
	// stvx128 v73,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v73), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-864
	ctx.r11.s64 = -864;
	// stvx128 v74,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v74), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-848
	ctx.r11.s64 = -848;
	// stvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v75), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v76), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_72"))) PPC_WEAK_FUNC(__savevmx_72);
PPC_FUNC_IMPL(__imp____savevmx_72) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-896
	ctx.r11.s64 = -896;
	// stvx128 v72,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v72), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-880
	ctx.r11.s64 = -880;
	// stvx128 v73,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v73), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-864
	ctx.r11.s64 = -864;
	// stvx128 v74,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v74), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-848
	ctx.r11.s64 = -848;
	// stvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v75), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v76), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_73"))) PPC_WEAK_FUNC(__savevmx_73);
PPC_FUNC_IMPL(__imp____savevmx_73) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-880
	ctx.r11.s64 = -880;
	// stvx128 v73,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v73), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-864
	ctx.r11.s64 = -864;
	// stvx128 v74,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v74), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-848
	ctx.r11.s64 = -848;
	// stvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v75), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v76), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_74"))) PPC_WEAK_FUNC(__savevmx_74);
PPC_FUNC_IMPL(__imp____savevmx_74) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-864
	ctx.r11.s64 = -864;
	// stvx128 v74,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v74), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-848
	ctx.r11.s64 = -848;
	// stvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v75), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v76), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_75"))) PPC_WEAK_FUNC(__savevmx_75);
PPC_FUNC_IMPL(__imp____savevmx_75) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-848
	ctx.r11.s64 = -848;
	// stvx128 v75,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v75), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v76), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_76"))) PPC_WEAK_FUNC(__savevmx_76);
PPC_FUNC_IMPL(__imp____savevmx_76) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-832
	ctx.r11.s64 = -832;
	// stvx128 v76,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v76), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_77"))) PPC_WEAK_FUNC(__savevmx_77);
PPC_FUNC_IMPL(__imp____savevmx_77) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-816
	ctx.r11.s64 = -816;
	// stvx128 v77,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v77), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_78"))) PPC_WEAK_FUNC(__savevmx_78);
PPC_FUNC_IMPL(__imp____savevmx_78) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-800
	ctx.r11.s64 = -800;
	// stvx128 v78,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v78), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_79"))) PPC_WEAK_FUNC(__savevmx_79);
PPC_FUNC_IMPL(__imp____savevmx_79) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-784
	ctx.r11.s64 = -784;
	// stvx128 v79,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v79), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_80"))) PPC_WEAK_FUNC(__savevmx_80);
PPC_FUNC_IMPL(__imp____savevmx_80) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-768
	ctx.r11.s64 = -768;
	// stvx128 v80,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v80), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_81"))) PPC_WEAK_FUNC(__savevmx_81);
PPC_FUNC_IMPL(__imp____savevmx_81) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-752
	ctx.r11.s64 = -752;
	// stvx128 v81,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v81), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_82"))) PPC_WEAK_FUNC(__savevmx_82);
PPC_FUNC_IMPL(__imp____savevmx_82) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-736
	ctx.r11.s64 = -736;
	// stvx128 v82,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v82), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_83"))) PPC_WEAK_FUNC(__savevmx_83);
PPC_FUNC_IMPL(__imp____savevmx_83) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-720
	ctx.r11.s64 = -720;
	// stvx128 v83,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v83), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_84"))) PPC_WEAK_FUNC(__savevmx_84);
PPC_FUNC_IMPL(__imp____savevmx_84) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-704
	ctx.r11.s64 = -704;
	// stvx128 v84,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v84), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_85"))) PPC_WEAK_FUNC(__savevmx_85);
PPC_FUNC_IMPL(__imp____savevmx_85) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-688
	ctx.r11.s64 = -688;
	// stvx128 v85,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v85), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_86"))) PPC_WEAK_FUNC(__savevmx_86);
PPC_FUNC_IMPL(__imp____savevmx_86) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-672
	ctx.r11.s64 = -672;
	// stvx128 v86,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v86), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_87"))) PPC_WEAK_FUNC(__savevmx_87);
PPC_FUNC_IMPL(__imp____savevmx_87) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-656
	ctx.r11.s64 = -656;
	// stvx128 v87,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v87), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_88"))) PPC_WEAK_FUNC(__savevmx_88);
PPC_FUNC_IMPL(__imp____savevmx_88) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-640
	ctx.r11.s64 = -640;
	// stvx128 v88,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v88), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_89"))) PPC_WEAK_FUNC(__savevmx_89);
PPC_FUNC_IMPL(__imp____savevmx_89) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v89), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_90"))) PPC_WEAK_FUNC(__savevmx_90);
PPC_FUNC_IMPL(__imp____savevmx_90) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v90), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_91"))) PPC_WEAK_FUNC(__savevmx_91);
PPC_FUNC_IMPL(__imp____savevmx_91) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v91), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_92"))) PPC_WEAK_FUNC(__savevmx_92);
PPC_FUNC_IMPL(__imp____savevmx_92) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v92), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_93"))) PPC_WEAK_FUNC(__savevmx_93);
PPC_FUNC_IMPL(__imp____savevmx_93) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v93), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_94"))) PPC_WEAK_FUNC(__savevmx_94);
PPC_FUNC_IMPL(__imp____savevmx_94) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v94), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_95"))) PPC_WEAK_FUNC(__savevmx_95);
PPC_FUNC_IMPL(__imp____savevmx_95) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v95), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_96"))) PPC_WEAK_FUNC(__savevmx_96);
PPC_FUNC_IMPL(__imp____savevmx_96) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v96), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_97"))) PPC_WEAK_FUNC(__savevmx_97);
PPC_FUNC_IMPL(__imp____savevmx_97) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v97), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_98"))) PPC_WEAK_FUNC(__savevmx_98);
PPC_FUNC_IMPL(__imp____savevmx_98) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v98), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_99"))) PPC_WEAK_FUNC(__savevmx_99);
PPC_FUNC_IMPL(__imp____savevmx_99) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v99), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_100"))) PPC_WEAK_FUNC(__savevmx_100);
PPC_FUNC_IMPL(__imp____savevmx_100) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v100), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_101"))) PPC_WEAK_FUNC(__savevmx_101);
PPC_FUNC_IMPL(__imp____savevmx_101) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v101), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_102"))) PPC_WEAK_FUNC(__savevmx_102);
PPC_FUNC_IMPL(__imp____savevmx_102) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v102), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_103"))) PPC_WEAK_FUNC(__savevmx_103);
PPC_FUNC_IMPL(__imp____savevmx_103) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v103), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_104"))) PPC_WEAK_FUNC(__savevmx_104);
PPC_FUNC_IMPL(__imp____savevmx_104) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v104), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_105"))) PPC_WEAK_FUNC(__savevmx_105);
PPC_FUNC_IMPL(__imp____savevmx_105) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v105), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_106"))) PPC_WEAK_FUNC(__savevmx_106);
PPC_FUNC_IMPL(__imp____savevmx_106) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v106), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_107"))) PPC_WEAK_FUNC(__savevmx_107);
PPC_FUNC_IMPL(__imp____savevmx_107) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v107), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_108"))) PPC_WEAK_FUNC(__savevmx_108);
PPC_FUNC_IMPL(__imp____savevmx_108) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v108), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_109"))) PPC_WEAK_FUNC(__savevmx_109);
PPC_FUNC_IMPL(__imp____savevmx_109) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v109), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_110"))) PPC_WEAK_FUNC(__savevmx_110);
PPC_FUNC_IMPL(__imp____savevmx_110) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v110), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_111"))) PPC_WEAK_FUNC(__savevmx_111);
PPC_FUNC_IMPL(__imp____savevmx_111) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v111), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_112"))) PPC_WEAK_FUNC(__savevmx_112);
PPC_FUNC_IMPL(__imp____savevmx_112) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v112), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_113"))) PPC_WEAK_FUNC(__savevmx_113);
PPC_FUNC_IMPL(__imp____savevmx_113) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v113), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_114"))) PPC_WEAK_FUNC(__savevmx_114);
PPC_FUNC_IMPL(__imp____savevmx_114) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v114), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_115"))) PPC_WEAK_FUNC(__savevmx_115);
PPC_FUNC_IMPL(__imp____savevmx_115) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v115), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_116"))) PPC_WEAK_FUNC(__savevmx_116);
PPC_FUNC_IMPL(__imp____savevmx_116) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v116), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_117"))) PPC_WEAK_FUNC(__savevmx_117);
PPC_FUNC_IMPL(__imp____savevmx_117) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v117), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_118"))) PPC_WEAK_FUNC(__savevmx_118);
PPC_FUNC_IMPL(__imp____savevmx_118) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v118), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_119"))) PPC_WEAK_FUNC(__savevmx_119);
PPC_FUNC_IMPL(__imp____savevmx_119) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v119), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_120"))) PPC_WEAK_FUNC(__savevmx_120);
PPC_FUNC_IMPL(__imp____savevmx_120) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v120), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_121"))) PPC_WEAK_FUNC(__savevmx_121);
PPC_FUNC_IMPL(__imp____savevmx_121) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v121), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_122"))) PPC_WEAK_FUNC(__savevmx_122);
PPC_FUNC_IMPL(__imp____savevmx_122) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v122), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_123"))) PPC_WEAK_FUNC(__savevmx_123);
PPC_FUNC_IMPL(__imp____savevmx_123) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v123), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_124"))) PPC_WEAK_FUNC(__savevmx_124);
PPC_FUNC_IMPL(__imp____savevmx_124) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v124), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_125"))) PPC_WEAK_FUNC(__savevmx_125);
PPC_FUNC_IMPL(__imp____savevmx_125) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v125), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_126"))) PPC_WEAK_FUNC(__savevmx_126);
PPC_FUNC_IMPL(__imp____savevmx_126) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v126), &VectorMaskL[(ea & 0xF) * 16]);
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____savevmx_127"))) PPC_WEAK_FUNC(__savevmx_127);
PPC_FUNC_IMPL(__imp____savevmx_127) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simd::store_shuffled(base + ea, simd::to_vec128i(ctx.v127), &VectorMaskL[(ea & 0xF) * 16]);
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_14"))) PPC_WEAK_FUNC(__restvmx_14);
PPC_FUNC_IMPL(__imp____restvmx_14) {
	PPC_FUNC_PROLOGUE();
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx v14,r11,r12
	simd::store_shuffled(ctx.v14, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx v15,r11,r12
	simd::store_shuffled(ctx.v15, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx v16,r11,r12
	simd::store_shuffled(ctx.v16, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx v17,r11,r12
	simd::store_shuffled(ctx.v17, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx v18,r11,r12
	simd::store_shuffled(ctx.v18, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx v19,r11,r12
	simd::store_shuffled(ctx.v19, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx v20,r11,r12
	simd::store_shuffled(ctx.v20, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx v21,r11,r12
	simd::store_shuffled(ctx.v21, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx v22,r11,r12
	simd::store_shuffled(ctx.v22, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx v23,r11,r12
	simd::store_shuffled(ctx.v23, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx v24,r11,r12
	simd::store_shuffled(ctx.v24, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	simd::store_shuffled(ctx.v25, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_15"))) PPC_WEAK_FUNC(__restvmx_15);
PPC_FUNC_IMPL(__imp____restvmx_15) {
	PPC_FUNC_PROLOGUE();
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx v15,r11,r12
	simd::store_shuffled(ctx.v15, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx v16,r11,r12
	simd::store_shuffled(ctx.v16, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx v17,r11,r12
	simd::store_shuffled(ctx.v17, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx v18,r11,r12
	simd::store_shuffled(ctx.v18, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx v19,r11,r12
	simd::store_shuffled(ctx.v19, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx v20,r11,r12
	simd::store_shuffled(ctx.v20, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx v21,r11,r12
	simd::store_shuffled(ctx.v21, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx v22,r11,r12
	simd::store_shuffled(ctx.v22, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx v23,r11,r12
	simd::store_shuffled(ctx.v23, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx v24,r11,r12
	simd::store_shuffled(ctx.v24, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	simd::store_shuffled(ctx.v25, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_16"))) PPC_WEAK_FUNC(__restvmx_16);
PPC_FUNC_IMPL(__imp____restvmx_16) {
	PPC_FUNC_PROLOGUE();
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx v16,r11,r12
	simd::store_shuffled(ctx.v16, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx v17,r11,r12
	simd::store_shuffled(ctx.v17, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx v18,r11,r12
	simd::store_shuffled(ctx.v18, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx v19,r11,r12
	simd::store_shuffled(ctx.v19, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx v20,r11,r12
	simd::store_shuffled(ctx.v20, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx v21,r11,r12
	simd::store_shuffled(ctx.v21, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx v22,r11,r12
	simd::store_shuffled(ctx.v22, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx v23,r11,r12
	simd::store_shuffled(ctx.v23, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx v24,r11,r12
	simd::store_shuffled(ctx.v24, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	simd::store_shuffled(ctx.v25, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_17"))) PPC_WEAK_FUNC(__restvmx_17);
PPC_FUNC_IMPL(__imp____restvmx_17) {
	PPC_FUNC_PROLOGUE();
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx v17,r11,r12
	simd::store_shuffled(ctx.v17, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx v18,r11,r12
	simd::store_shuffled(ctx.v18, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx v19,r11,r12
	simd::store_shuffled(ctx.v19, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx v20,r11,r12
	simd::store_shuffled(ctx.v20, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx v21,r11,r12
	simd::store_shuffled(ctx.v21, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx v22,r11,r12
	simd::store_shuffled(ctx.v22, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx v23,r11,r12
	simd::store_shuffled(ctx.v23, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx v24,r11,r12
	simd::store_shuffled(ctx.v24, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	simd::store_shuffled(ctx.v25, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_18"))) PPC_WEAK_FUNC(__restvmx_18);
PPC_FUNC_IMPL(__imp____restvmx_18) {
	PPC_FUNC_PROLOGUE();
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx v18,r11,r12
	simd::store_shuffled(ctx.v18, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx v19,r11,r12
	simd::store_shuffled(ctx.v19, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx v20,r11,r12
	simd::store_shuffled(ctx.v20, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx v21,r11,r12
	simd::store_shuffled(ctx.v21, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx v22,r11,r12
	simd::store_shuffled(ctx.v22, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx v23,r11,r12
	simd::store_shuffled(ctx.v23, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx v24,r11,r12
	simd::store_shuffled(ctx.v24, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	simd::store_shuffled(ctx.v25, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_19"))) PPC_WEAK_FUNC(__restvmx_19);
PPC_FUNC_IMPL(__imp____restvmx_19) {
	PPC_FUNC_PROLOGUE();
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx v19,r11,r12
	simd::store_shuffled(ctx.v19, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx v20,r11,r12
	simd::store_shuffled(ctx.v20, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx v21,r11,r12
	simd::store_shuffled(ctx.v21, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx v22,r11,r12
	simd::store_shuffled(ctx.v22, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx v23,r11,r12
	simd::store_shuffled(ctx.v23, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx v24,r11,r12
	simd::store_shuffled(ctx.v24, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	simd::store_shuffled(ctx.v25, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_20"))) PPC_WEAK_FUNC(__restvmx_20);
PPC_FUNC_IMPL(__imp____restvmx_20) {
	PPC_FUNC_PROLOGUE();
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx v20,r11,r12
	simd::store_shuffled(ctx.v20, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx v21,r11,r12
	simd::store_shuffled(ctx.v21, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx v22,r11,r12
	simd::store_shuffled(ctx.v22, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx v23,r11,r12
	simd::store_shuffled(ctx.v23, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx v24,r11,r12
	simd::store_shuffled(ctx.v24, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	simd::store_shuffled(ctx.v25, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_21"))) PPC_WEAK_FUNC(__restvmx_21);
PPC_FUNC_IMPL(__imp____restvmx_21) {
	PPC_FUNC_PROLOGUE();
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx v21,r11,r12
	simd::store_shuffled(ctx.v21, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx v22,r11,r12
	simd::store_shuffled(ctx.v22, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx v23,r11,r12
	simd::store_shuffled(ctx.v23, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx v24,r11,r12
	simd::store_shuffled(ctx.v24, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	simd::store_shuffled(ctx.v25, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_22"))) PPC_WEAK_FUNC(__restvmx_22);
PPC_FUNC_IMPL(__imp____restvmx_22) {
	PPC_FUNC_PROLOGUE();
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx v22,r11,r12
	simd::store_shuffled(ctx.v22, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx v23,r11,r12
	simd::store_shuffled(ctx.v23, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx v24,r11,r12
	simd::store_shuffled(ctx.v24, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	simd::store_shuffled(ctx.v25, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_23"))) PPC_WEAK_FUNC(__restvmx_23);
PPC_FUNC_IMPL(__imp____restvmx_23) {
	PPC_FUNC_PROLOGUE();
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx v23,r11,r12
	simd::store_shuffled(ctx.v23, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx v24,r11,r12
	simd::store_shuffled(ctx.v24, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	simd::store_shuffled(ctx.v25, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_24"))) PPC_WEAK_FUNC(__restvmx_24);
PPC_FUNC_IMPL(__imp____restvmx_24) {
	PPC_FUNC_PROLOGUE();
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx v24,r11,r12
	simd::store_shuffled(ctx.v24, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	simd::store_shuffled(ctx.v25, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_25"))) PPC_WEAK_FUNC(__restvmx_25);
PPC_FUNC_IMPL(__imp____restvmx_25) {
	PPC_FUNC_PROLOGUE();
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx v25,r11,r12
	simd::store_shuffled(ctx.v25, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_26"))) PPC_WEAK_FUNC(__restvmx_26);
PPC_FUNC_IMPL(__imp____restvmx_26) {
	PPC_FUNC_PROLOGUE();
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx v26,r11,r12
	simd::store_shuffled(ctx.v26, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_27"))) PPC_WEAK_FUNC(__restvmx_27);
PPC_FUNC_IMPL(__imp____restvmx_27) {
	PPC_FUNC_PROLOGUE();
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx v27,r11,r12
	simd::store_shuffled(ctx.v27, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_28"))) PPC_WEAK_FUNC(__restvmx_28);
PPC_FUNC_IMPL(__imp____restvmx_28) {
	PPC_FUNC_PROLOGUE();
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx v28,r11,r12
	simd::store_shuffled(ctx.v28, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_29"))) PPC_WEAK_FUNC(__restvmx_29);
PPC_FUNC_IMPL(__imp____restvmx_29) {
	PPC_FUNC_PROLOGUE();
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx v29,r11,r12
	simd::store_shuffled(ctx.v29, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_30"))) PPC_WEAK_FUNC(__restvmx_30);
PPC_FUNC_IMPL(__imp____restvmx_30) {
	PPC_FUNC_PROLOGUE();
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx v30,r11,r12
	simd::store_shuffled(ctx.v30, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_31"))) PPC_WEAK_FUNC(__restvmx_31);
PPC_FUNC_IMPL(__imp____restvmx_31) {
	PPC_FUNC_PROLOGUE();
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx v31,r11,r12
	simd::store_shuffled(ctx.v31, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_64"))) PPC_WEAK_FUNC(__restvmx_64);
PPC_FUNC_IMPL(__imp____restvmx_64) {
	PPC_FUNC_PROLOGUE();
	// li r11,-1024
	ctx.r11.s64 = -1024;
	// lvx128 v64,r11,r12
	simd::store_shuffled(ctx.v64, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-1008
	ctx.r11.s64 = -1008;
	// lvx128 v65,r11,r12
	simd::store_shuffled(ctx.v65, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-992
	ctx.r11.s64 = -992;
	// lvx128 v66,r11,r12
	simd::store_shuffled(ctx.v66, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-976
	ctx.r11.s64 = -976;
	// lvx128 v67,r11,r12
	simd::store_shuffled(ctx.v67, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-960
	ctx.r11.s64 = -960;
	// lvx128 v68,r11,r12
	simd::store_shuffled(ctx.v68, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-944
	ctx.r11.s64 = -944;
	// lvx128 v69,r11,r12
	simd::store_shuffled(ctx.v69, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-928
	ctx.r11.s64 = -928;
	// lvx128 v70,r11,r12
	simd::store_shuffled(ctx.v70, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-912
	ctx.r11.s64 = -912;
	// lvx128 v71,r11,r12
	simd::store_shuffled(ctx.v71, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-896
	ctx.r11.s64 = -896;
	// lvx128 v72,r11,r12
	simd::store_shuffled(ctx.v72, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-880
	ctx.r11.s64 = -880;
	// lvx128 v73,r11,r12
	simd::store_shuffled(ctx.v73, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-864
	ctx.r11.s64 = -864;
	// lvx128 v74,r11,r12
	simd::store_shuffled(ctx.v74, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-848
	ctx.r11.s64 = -848;
	// lvx128 v75,r11,r12
	simd::store_shuffled(ctx.v75, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-832
	ctx.r11.s64 = -832;
	// lvx128 v76,r11,r12
	simd::store_shuffled(ctx.v76, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-816
	ctx.r11.s64 = -816;
	// lvx128 v77,r11,r12
	simd::store_shuffled(ctx.v77, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-800
	ctx.r11.s64 = -800;
	// lvx128 v78,r11,r12
	simd::store_shuffled(ctx.v78, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-784
	ctx.r11.s64 = -784;
	// lvx128 v79,r11,r12
	simd::store_shuffled(ctx.v79, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-768
	ctx.r11.s64 = -768;
	// lvx128 v80,r11,r12
	simd::store_shuffled(ctx.v80, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-752
	ctx.r11.s64 = -752;
	// lvx128 v81,r11,r12
	simd::store_shuffled(ctx.v81, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-736
	ctx.r11.s64 = -736;
	// lvx128 v82,r11,r12
	simd::store_shuffled(ctx.v82, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-720
	ctx.r11.s64 = -720;
	// lvx128 v83,r11,r12
	simd::store_shuffled(ctx.v83, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-704
	ctx.r11.s64 = -704;
	// lvx128 v84,r11,r12
	simd::store_shuffled(ctx.v84, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-688
	ctx.r11.s64 = -688;
	// lvx128 v85,r11,r12
	simd::store_shuffled(ctx.v85, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-672
	ctx.r11.s64 = -672;
	// lvx128 v86,r11,r12
	simd::store_shuffled(ctx.v86, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-656
	ctx.r11.s64 = -656;
	// lvx128 v87,r11,r12
	simd::store_shuffled(ctx.v87, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-640
	ctx.r11.s64 = -640;
	// lvx128 v88,r11,r12
	simd::store_shuffled(ctx.v88, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-624
	ctx.r11.s64 = -624;
	// lvx128 v89,r11,r12
	simd::store_shuffled(ctx.v89, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-608
	ctx.r11.s64 = -608;
	// lvx128 v90,r11,r12
	simd::store_shuffled(ctx.v90, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-592
	ctx.r11.s64 = -592;
	// lvx128 v91,r11,r12
	simd::store_shuffled(ctx.v91, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-576
	ctx.r11.s64 = -576;
	// lvx128 v92,r11,r12
	simd::store_shuffled(ctx.v92, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-560
	ctx.r11.s64 = -560;
	// lvx128 v93,r11,r12
	simd::store_shuffled(ctx.v93, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-544
	ctx.r11.s64 = -544;
	// lvx128 v94,r11,r12
	simd::store_shuffled(ctx.v94, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-528
	ctx.r11.s64 = -528;
	// lvx128 v95,r11,r12
	simd::store_shuffled(ctx.v95, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-512
	ctx.r11.s64 = -512;
	// lvx128 v96,r11,r12
	simd::store_shuffled(ctx.v96, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-496
	ctx.r11.s64 = -496;
	// lvx128 v97,r11,r12
	simd::store_shuffled(ctx.v97, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-480
	ctx.r11.s64 = -480;
	// lvx128 v98,r11,r12
	simd::store_shuffled(ctx.v98, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-464
	ctx.r11.s64 = -464;
	// lvx128 v99,r11,r12
	simd::store_shuffled(ctx.v99, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-448
	ctx.r11.s64 = -448;
	// lvx128 v100,r11,r12
	simd::store_shuffled(ctx.v100, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-432
	ctx.r11.s64 = -432;
	// lvx128 v101,r11,r12
	simd::store_shuffled(ctx.v101, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-416
	ctx.r11.s64 = -416;
	// lvx128 v102,r11,r12
	simd::store_shuffled(ctx.v102, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-400
	ctx.r11.s64 = -400;
	// lvx128 v103,r11,r12
	simd::store_shuffled(ctx.v103, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-384
	ctx.r11.s64 = -384;
	// lvx128 v104,r11,r12
	simd::store_shuffled(ctx.v104, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-368
	ctx.r11.s64 = -368;
	// lvx128 v105,r11,r12
	simd::store_shuffled(ctx.v105, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-352
	ctx.r11.s64 = -352;
	// lvx128 v106,r11,r12
	simd::store_shuffled(ctx.v106, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-336
	ctx.r11.s64 = -336;
	// lvx128 v107,r11,r12
	simd::store_shuffled(ctx.v107, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-320
	ctx.r11.s64 = -320;
	// lvx128 v108,r11,r12
	simd::store_shuffled(ctx.v108, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-304
	ctx.r11.s64 = -304;
	// lvx128 v109,r11,r12
	simd::store_shuffled(ctx.v109, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx128 v110,r11,r12
	simd::store_shuffled(ctx.v110, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx128 v111,r11,r12
	simd::store_shuffled(ctx.v111, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx128 v112,r11,r12
	simd::store_shuffled(ctx.v112, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx128 v113,r11,r12
	simd::store_shuffled(ctx.v113, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx128 v114,r11,r12
	simd::store_shuffled(ctx.v114, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx128 v115,r11,r12
	simd::store_shuffled(ctx.v115, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx128 v116,r11,r12
	simd::store_shuffled(ctx.v116, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx128 v117,r11,r12
	simd::store_shuffled(ctx.v117, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx128 v118,r11,r12
	simd::store_shuffled(ctx.v118, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx128 v119,r11,r12
	simd::store_shuffled(ctx.v119, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx128 v120,r11,r12
	simd::store_shuffled(ctx.v120, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx128 v121,r11,r12
	simd::store_shuffled(ctx.v121, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx128 v122,r11,r12
	simd::store_shuffled(ctx.v122, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx128 v123,r11,r12
	simd::store_shuffled(ctx.v123, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx128 v124,r11,r12
	simd::store_shuffled(ctx.v124, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx128 v125,r11,r12
	simd::store_shuffled(ctx.v125, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx128 v126,r11,r12
	simd::store_shuffled(ctx.v126, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx128 v127,r11,r12
	simd::store_shuffled(ctx.v127, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_65"))) PPC_WEAK_FUNC(__restvmx_65);
PPC_FUNC_IMPL(__imp____restvmx_65) {
	PPC_FUNC_PROLOGUE();
	// li r11,-1008
	ctx.r11.s64 = -1008;
	// lvx128 v65,r11,r12
	simd::store_shuffled(ctx.v65, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-992
	ctx.r11.s64 = -992;
	// lvx128 v66,r11,r12
	simd::store_shuffled(ctx.v66, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-976
	ctx.r11.s64 = -976;
	// lvx128 v67,r11,r12
	simd::store_shuffled(ctx.v67, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-960
	ctx.r11.s64 = -960;
	// lvx128 v68,r11,r12
	simd::store_shuffled(ctx.v68, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-944
	ctx.r11.s64 = -944;
	// lvx128 v69,r11,r12
	simd::store_shuffled(ctx.v69, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-928
	ctx.r11.s64 = -928;
	// lvx128 v70,r11,r12
	simd::store_shuffled(ctx.v70, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-912
	ctx.r11.s64 = -912;
	// lvx128 v71,r11,r12
	simd::store_shuffled(ctx.v71, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-896
	ctx.r11.s64 = -896;
	// lvx128 v72,r11,r12
	simd::store_shuffled(ctx.v72, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-880
	ctx.r11.s64 = -880;
	// lvx128 v73,r11,r12
	simd::store_shuffled(ctx.v73, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-864
	ctx.r11.s64 = -864;
	// lvx128 v74,r11,r12
	simd::store_shuffled(ctx.v74, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-848
	ctx.r11.s64 = -848;
	// lvx128 v75,r11,r12
	simd::store_shuffled(ctx.v75, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-832
	ctx.r11.s64 = -832;
	// lvx128 v76,r11,r12
	simd::store_shuffled(ctx.v76, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-816
	ctx.r11.s64 = -816;
	// lvx128 v77,r11,r12
	simd::store_shuffled(ctx.v77, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-800
	ctx.r11.s64 = -800;
	// lvx128 v78,r11,r12
	simd::store_shuffled(ctx.v78, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-784
	ctx.r11.s64 = -784;
	// lvx128 v79,r11,r12
	simd::store_shuffled(ctx.v79, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-768
	ctx.r11.s64 = -768;
	// lvx128 v80,r11,r12
	simd::store_shuffled(ctx.v80, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-752
	ctx.r11.s64 = -752;
	// lvx128 v81,r11,r12
	simd::store_shuffled(ctx.v81, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-736
	ctx.r11.s64 = -736;
	// lvx128 v82,r11,r12
	simd::store_shuffled(ctx.v82, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-720
	ctx.r11.s64 = -720;
	// lvx128 v83,r11,r12
	simd::store_shuffled(ctx.v83, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-704
	ctx.r11.s64 = -704;
	// lvx128 v84,r11,r12
	simd::store_shuffled(ctx.v84, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-688
	ctx.r11.s64 = -688;
	// lvx128 v85,r11,r12
	simd::store_shuffled(ctx.v85, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-672
	ctx.r11.s64 = -672;
	// lvx128 v86,r11,r12
	simd::store_shuffled(ctx.v86, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-656
	ctx.r11.s64 = -656;
	// lvx128 v87,r11,r12
	simd::store_shuffled(ctx.v87, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-640
	ctx.r11.s64 = -640;
	// lvx128 v88,r11,r12
	simd::store_shuffled(ctx.v88, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-624
	ctx.r11.s64 = -624;
	// lvx128 v89,r11,r12
	simd::store_shuffled(ctx.v89, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-608
	ctx.r11.s64 = -608;
	// lvx128 v90,r11,r12
	simd::store_shuffled(ctx.v90, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-592
	ctx.r11.s64 = -592;
	// lvx128 v91,r11,r12
	simd::store_shuffled(ctx.v91, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-576
	ctx.r11.s64 = -576;
	// lvx128 v92,r11,r12
	simd::store_shuffled(ctx.v92, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-560
	ctx.r11.s64 = -560;
	// lvx128 v93,r11,r12
	simd::store_shuffled(ctx.v93, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-544
	ctx.r11.s64 = -544;
	// lvx128 v94,r11,r12
	simd::store_shuffled(ctx.v94, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-528
	ctx.r11.s64 = -528;
	// lvx128 v95,r11,r12
	simd::store_shuffled(ctx.v95, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-512
	ctx.r11.s64 = -512;
	// lvx128 v96,r11,r12
	simd::store_shuffled(ctx.v96, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-496
	ctx.r11.s64 = -496;
	// lvx128 v97,r11,r12
	simd::store_shuffled(ctx.v97, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-480
	ctx.r11.s64 = -480;
	// lvx128 v98,r11,r12
	simd::store_shuffled(ctx.v98, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-464
	ctx.r11.s64 = -464;
	// lvx128 v99,r11,r12
	simd::store_shuffled(ctx.v99, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-448
	ctx.r11.s64 = -448;
	// lvx128 v100,r11,r12
	simd::store_shuffled(ctx.v100, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-432
	ctx.r11.s64 = -432;
	// lvx128 v101,r11,r12
	simd::store_shuffled(ctx.v101, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-416
	ctx.r11.s64 = -416;
	// lvx128 v102,r11,r12
	simd::store_shuffled(ctx.v102, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-400
	ctx.r11.s64 = -400;
	// lvx128 v103,r11,r12
	simd::store_shuffled(ctx.v103, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-384
	ctx.r11.s64 = -384;
	// lvx128 v104,r11,r12
	simd::store_shuffled(ctx.v104, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-368
	ctx.r11.s64 = -368;
	// lvx128 v105,r11,r12
	simd::store_shuffled(ctx.v105, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-352
	ctx.r11.s64 = -352;
	// lvx128 v106,r11,r12
	simd::store_shuffled(ctx.v106, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-336
	ctx.r11.s64 = -336;
	// lvx128 v107,r11,r12
	simd::store_shuffled(ctx.v107, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-320
	ctx.r11.s64 = -320;
	// lvx128 v108,r11,r12
	simd::store_shuffled(ctx.v108, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-304
	ctx.r11.s64 = -304;
	// lvx128 v109,r11,r12
	simd::store_shuffled(ctx.v109, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx128 v110,r11,r12
	simd::store_shuffled(ctx.v110, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx128 v111,r11,r12
	simd::store_shuffled(ctx.v111, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx128 v112,r11,r12
	simd::store_shuffled(ctx.v112, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx128 v113,r11,r12
	simd::store_shuffled(ctx.v113, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx128 v114,r11,r12
	simd::store_shuffled(ctx.v114, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx128 v115,r11,r12
	simd::store_shuffled(ctx.v115, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx128 v116,r11,r12
	simd::store_shuffled(ctx.v116, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx128 v117,r11,r12
	simd::store_shuffled(ctx.v117, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx128 v118,r11,r12
	simd::store_shuffled(ctx.v118, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx128 v119,r11,r12
	simd::store_shuffled(ctx.v119, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx128 v120,r11,r12
	simd::store_shuffled(ctx.v120, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx128 v121,r11,r12
	simd::store_shuffled(ctx.v121, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx128 v122,r11,r12
	simd::store_shuffled(ctx.v122, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx128 v123,r11,r12
	simd::store_shuffled(ctx.v123, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx128 v124,r11,r12
	simd::store_shuffled(ctx.v124, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx128 v125,r11,r12
	simd::store_shuffled(ctx.v125, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx128 v126,r11,r12
	simd::store_shuffled(ctx.v126, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx128 v127,r11,r12
	simd::store_shuffled(ctx.v127, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_66"))) PPC_WEAK_FUNC(__restvmx_66);
PPC_FUNC_IMPL(__imp____restvmx_66) {
	PPC_FUNC_PROLOGUE();
	// li r11,-992
	ctx.r11.s64 = -992;
	// lvx128 v66,r11,r12
	simd::store_shuffled(ctx.v66, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-976
	ctx.r11.s64 = -976;
	// lvx128 v67,r11,r12
	simd::store_shuffled(ctx.v67, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-960
	ctx.r11.s64 = -960;
	// lvx128 v68,r11,r12
	simd::store_shuffled(ctx.v68, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-944
	ctx.r11.s64 = -944;
	// lvx128 v69,r11,r12
	simd::store_shuffled(ctx.v69, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-928
	ctx.r11.s64 = -928;
	// lvx128 v70,r11,r12
	simd::store_shuffled(ctx.v70, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-912
	ctx.r11.s64 = -912;
	// lvx128 v71,r11,r12
	simd::store_shuffled(ctx.v71, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-896
	ctx.r11.s64 = -896;
	// lvx128 v72,r11,r12
	simd::store_shuffled(ctx.v72, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-880
	ctx.r11.s64 = -880;
	// lvx128 v73,r11,r12
	simd::store_shuffled(ctx.v73, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-864
	ctx.r11.s64 = -864;
	// lvx128 v74,r11,r12
	simd::store_shuffled(ctx.v74, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-848
	ctx.r11.s64 = -848;
	// lvx128 v75,r11,r12
	simd::store_shuffled(ctx.v75, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-832
	ctx.r11.s64 = -832;
	// lvx128 v76,r11,r12
	simd::store_shuffled(ctx.v76, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-816
	ctx.r11.s64 = -816;
	// lvx128 v77,r11,r12
	simd::store_shuffled(ctx.v77, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-800
	ctx.r11.s64 = -800;
	// lvx128 v78,r11,r12
	simd::store_shuffled(ctx.v78, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-784
	ctx.r11.s64 = -784;
	// lvx128 v79,r11,r12
	simd::store_shuffled(ctx.v79, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-768
	ctx.r11.s64 = -768;
	// lvx128 v80,r11,r12
	simd::store_shuffled(ctx.v80, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-752
	ctx.r11.s64 = -752;
	// lvx128 v81,r11,r12
	simd::store_shuffled(ctx.v81, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-736
	ctx.r11.s64 = -736;
	// lvx128 v82,r11,r12
	simd::store_shuffled(ctx.v82, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-720
	ctx.r11.s64 = -720;
	// lvx128 v83,r11,r12
	simd::store_shuffled(ctx.v83, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-704
	ctx.r11.s64 = -704;
	// lvx128 v84,r11,r12
	simd::store_shuffled(ctx.v84, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-688
	ctx.r11.s64 = -688;
	// lvx128 v85,r11,r12
	simd::store_shuffled(ctx.v85, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-672
	ctx.r11.s64 = -672;
	// lvx128 v86,r11,r12
	simd::store_shuffled(ctx.v86, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-656
	ctx.r11.s64 = -656;
	// lvx128 v87,r11,r12
	simd::store_shuffled(ctx.v87, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-640
	ctx.r11.s64 = -640;
	// lvx128 v88,r11,r12
	simd::store_shuffled(ctx.v88, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-624
	ctx.r11.s64 = -624;
	// lvx128 v89,r11,r12
	simd::store_shuffled(ctx.v89, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-608
	ctx.r11.s64 = -608;
	// lvx128 v90,r11,r12
	simd::store_shuffled(ctx.v90, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-592
	ctx.r11.s64 = -592;
	// lvx128 v91,r11,r12
	simd::store_shuffled(ctx.v91, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-576
	ctx.r11.s64 = -576;
	// lvx128 v92,r11,r12
	simd::store_shuffled(ctx.v92, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-560
	ctx.r11.s64 = -560;
	// lvx128 v93,r11,r12
	simd::store_shuffled(ctx.v93, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-544
	ctx.r11.s64 = -544;
	// lvx128 v94,r11,r12
	simd::store_shuffled(ctx.v94, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-528
	ctx.r11.s64 = -528;
	// lvx128 v95,r11,r12
	simd::store_shuffled(ctx.v95, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-512
	ctx.r11.s64 = -512;
	// lvx128 v96,r11,r12
	simd::store_shuffled(ctx.v96, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-496
	ctx.r11.s64 = -496;
	// lvx128 v97,r11,r12
	simd::store_shuffled(ctx.v97, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-480
	ctx.r11.s64 = -480;
	// lvx128 v98,r11,r12
	simd::store_shuffled(ctx.v98, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-464
	ctx.r11.s64 = -464;
	// lvx128 v99,r11,r12
	simd::store_shuffled(ctx.v99, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-448
	ctx.r11.s64 = -448;
	// lvx128 v100,r11,r12
	simd::store_shuffled(ctx.v100, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-432
	ctx.r11.s64 = -432;
	// lvx128 v101,r11,r12
	simd::store_shuffled(ctx.v101, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-416
	ctx.r11.s64 = -416;
	// lvx128 v102,r11,r12
	simd::store_shuffled(ctx.v102, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-400
	ctx.r11.s64 = -400;
	// lvx128 v103,r11,r12
	simd::store_shuffled(ctx.v103, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-384
	ctx.r11.s64 = -384;
	// lvx128 v104,r11,r12
	simd::store_shuffled(ctx.v104, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-368
	ctx.r11.s64 = -368;
	// lvx128 v105,r11,r12
	simd::store_shuffled(ctx.v105, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-352
	ctx.r11.s64 = -352;
	// lvx128 v106,r11,r12
	simd::store_shuffled(ctx.v106, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-336
	ctx.r11.s64 = -336;
	// lvx128 v107,r11,r12
	simd::store_shuffled(ctx.v107, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-320
	ctx.r11.s64 = -320;
	// lvx128 v108,r11,r12
	simd::store_shuffled(ctx.v108, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-304
	ctx.r11.s64 = -304;
	// lvx128 v109,r11,r12
	simd::store_shuffled(ctx.v109, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx128 v110,r11,r12
	simd::store_shuffled(ctx.v110, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx128 v111,r11,r12
	simd::store_shuffled(ctx.v111, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx128 v112,r11,r12
	simd::store_shuffled(ctx.v112, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx128 v113,r11,r12
	simd::store_shuffled(ctx.v113, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx128 v114,r11,r12
	simd::store_shuffled(ctx.v114, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx128 v115,r11,r12
	simd::store_shuffled(ctx.v115, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx128 v116,r11,r12
	simd::store_shuffled(ctx.v116, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx128 v117,r11,r12
	simd::store_shuffled(ctx.v117, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx128 v118,r11,r12
	simd::store_shuffled(ctx.v118, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx128 v119,r11,r12
	simd::store_shuffled(ctx.v119, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx128 v120,r11,r12
	simd::store_shuffled(ctx.v120, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx128 v121,r11,r12
	simd::store_shuffled(ctx.v121, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx128 v122,r11,r12
	simd::store_shuffled(ctx.v122, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx128 v123,r11,r12
	simd::store_shuffled(ctx.v123, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx128 v124,r11,r12
	simd::store_shuffled(ctx.v124, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx128 v125,r11,r12
	simd::store_shuffled(ctx.v125, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx128 v126,r11,r12
	simd::store_shuffled(ctx.v126, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx128 v127,r11,r12
	simd::store_shuffled(ctx.v127, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_67"))) PPC_WEAK_FUNC(__restvmx_67);
PPC_FUNC_IMPL(__imp____restvmx_67) {
	PPC_FUNC_PROLOGUE();
	// li r11,-976
	ctx.r11.s64 = -976;
	// lvx128 v67,r11,r12
	simd::store_shuffled(ctx.v67, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-960
	ctx.r11.s64 = -960;
	// lvx128 v68,r11,r12
	simd::store_shuffled(ctx.v68, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-944
	ctx.r11.s64 = -944;
	// lvx128 v69,r11,r12
	simd::store_shuffled(ctx.v69, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-928
	ctx.r11.s64 = -928;
	// lvx128 v70,r11,r12
	simd::store_shuffled(ctx.v70, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-912
	ctx.r11.s64 = -912;
	// lvx128 v71,r11,r12
	simd::store_shuffled(ctx.v71, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-896
	ctx.r11.s64 = -896;
	// lvx128 v72,r11,r12
	simd::store_shuffled(ctx.v72, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-880
	ctx.r11.s64 = -880;
	// lvx128 v73,r11,r12
	simd::store_shuffled(ctx.v73, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-864
	ctx.r11.s64 = -864;
	// lvx128 v74,r11,r12
	simd::store_shuffled(ctx.v74, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-848
	ctx.r11.s64 = -848;
	// lvx128 v75,r11,r12
	simd::store_shuffled(ctx.v75, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-832
	ctx.r11.s64 = -832;
	// lvx128 v76,r11,r12
	simd::store_shuffled(ctx.v76, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-816
	ctx.r11.s64 = -816;
	// lvx128 v77,r11,r12
	simd::store_shuffled(ctx.v77, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-800
	ctx.r11.s64 = -800;
	// lvx128 v78,r11,r12
	simd::store_shuffled(ctx.v78, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-784
	ctx.r11.s64 = -784;
	// lvx128 v79,r11,r12
	simd::store_shuffled(ctx.v79, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-768
	ctx.r11.s64 = -768;
	// lvx128 v80,r11,r12
	simd::store_shuffled(ctx.v80, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-752
	ctx.r11.s64 = -752;
	// lvx128 v81,r11,r12
	simd::store_shuffled(ctx.v81, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-736
	ctx.r11.s64 = -736;
	// lvx128 v82,r11,r12
	simd::store_shuffled(ctx.v82, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-720
	ctx.r11.s64 = -720;
	// lvx128 v83,r11,r12
	simd::store_shuffled(ctx.v83, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-704
	ctx.r11.s64 = -704;
	// lvx128 v84,r11,r12
	simd::store_shuffled(ctx.v84, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-688
	ctx.r11.s64 = -688;
	// lvx128 v85,r11,r12
	simd::store_shuffled(ctx.v85, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-672
	ctx.r11.s64 = -672;
	// lvx128 v86,r11,r12
	simd::store_shuffled(ctx.v86, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-656
	ctx.r11.s64 = -656;
	// lvx128 v87,r11,r12
	simd::store_shuffled(ctx.v87, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-640
	ctx.r11.s64 = -640;
	// lvx128 v88,r11,r12
	simd::store_shuffled(ctx.v88, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-624
	ctx.r11.s64 = -624;
	// lvx128 v89,r11,r12
	simd::store_shuffled(ctx.v89, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-608
	ctx.r11.s64 = -608;
	// lvx128 v90,r11,r12
	simd::store_shuffled(ctx.v90, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-592
	ctx.r11.s64 = -592;
	// lvx128 v91,r11,r12
	simd::store_shuffled(ctx.v91, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-576
	ctx.r11.s64 = -576;
	// lvx128 v92,r11,r12
	simd::store_shuffled(ctx.v92, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-560
	ctx.r11.s64 = -560;
	// lvx128 v93,r11,r12
	simd::store_shuffled(ctx.v93, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-544
	ctx.r11.s64 = -544;
	// lvx128 v94,r11,r12
	simd::store_shuffled(ctx.v94, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-528
	ctx.r11.s64 = -528;
	// lvx128 v95,r11,r12
	simd::store_shuffled(ctx.v95, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-512
	ctx.r11.s64 = -512;
	// lvx128 v96,r11,r12
	simd::store_shuffled(ctx.v96, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-496
	ctx.r11.s64 = -496;
	// lvx128 v97,r11,r12
	simd::store_shuffled(ctx.v97, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-480
	ctx.r11.s64 = -480;
	// lvx128 v98,r11,r12
	simd::store_shuffled(ctx.v98, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-464
	ctx.r11.s64 = -464;
	// lvx128 v99,r11,r12
	simd::store_shuffled(ctx.v99, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-448
	ctx.r11.s64 = -448;
	// lvx128 v100,r11,r12
	simd::store_shuffled(ctx.v100, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-432
	ctx.r11.s64 = -432;
	// lvx128 v101,r11,r12
	simd::store_shuffled(ctx.v101, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-416
	ctx.r11.s64 = -416;
	// lvx128 v102,r11,r12
	simd::store_shuffled(ctx.v102, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-400
	ctx.r11.s64 = -400;
	// lvx128 v103,r11,r12
	simd::store_shuffled(ctx.v103, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-384
	ctx.r11.s64 = -384;
	// lvx128 v104,r11,r12
	simd::store_shuffled(ctx.v104, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-368
	ctx.r11.s64 = -368;
	// lvx128 v105,r11,r12
	simd::store_shuffled(ctx.v105, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-352
	ctx.r11.s64 = -352;
	// lvx128 v106,r11,r12
	simd::store_shuffled(ctx.v106, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-336
	ctx.r11.s64 = -336;
	// lvx128 v107,r11,r12
	simd::store_shuffled(ctx.v107, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-320
	ctx.r11.s64 = -320;
	// lvx128 v108,r11,r12
	simd::store_shuffled(ctx.v108, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-304
	ctx.r11.s64 = -304;
	// lvx128 v109,r11,r12
	simd::store_shuffled(ctx.v109, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx128 v110,r11,r12
	simd::store_shuffled(ctx.v110, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx128 v111,r11,r12
	simd::store_shuffled(ctx.v111, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx128 v112,r11,r12
	simd::store_shuffled(ctx.v112, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx128 v113,r11,r12
	simd::store_shuffled(ctx.v113, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx128 v114,r11,r12
	simd::store_shuffled(ctx.v114, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx128 v115,r11,r12
	simd::store_shuffled(ctx.v115, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx128 v116,r11,r12
	simd::store_shuffled(ctx.v116, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx128 v117,r11,r12
	simd::store_shuffled(ctx.v117, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx128 v118,r11,r12
	simd::store_shuffled(ctx.v118, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx128 v119,r11,r12
	simd::store_shuffled(ctx.v119, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx128 v120,r11,r12
	simd::store_shuffled(ctx.v120, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx128 v121,r11,r12
	simd::store_shuffled(ctx.v121, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx128 v122,r11,r12
	simd::store_shuffled(ctx.v122, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx128 v123,r11,r12
	simd::store_shuffled(ctx.v123, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx128 v124,r11,r12
	simd::store_shuffled(ctx.v124, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx128 v125,r11,r12
	simd::store_shuffled(ctx.v125, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx128 v126,r11,r12
	simd::store_shuffled(ctx.v126, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx128 v127,r11,r12
	simd::store_shuffled(ctx.v127, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_68"))) PPC_WEAK_FUNC(__restvmx_68);
PPC_FUNC_IMPL(__imp____restvmx_68) {
	PPC_FUNC_PROLOGUE();
	// li r11,-960
	ctx.r11.s64 = -960;
	// lvx128 v68,r11,r12
	simd::store_shuffled(ctx.v68, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-944
	ctx.r11.s64 = -944;
	// lvx128 v69,r11,r12
	simd::store_shuffled(ctx.v69, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-928
	ctx.r11.s64 = -928;
	// lvx128 v70,r11,r12
	simd::store_shuffled(ctx.v70, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-912
	ctx.r11.s64 = -912;
	// lvx128 v71,r11,r12
	simd::store_shuffled(ctx.v71, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-896
	ctx.r11.s64 = -896;
	// lvx128 v72,r11,r12
	simd::store_shuffled(ctx.v72, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-880
	ctx.r11.s64 = -880;
	// lvx128 v73,r11,r12
	simd::store_shuffled(ctx.v73, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-864
	ctx.r11.s64 = -864;
	// lvx128 v74,r11,r12
	simd::store_shuffled(ctx.v74, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-848
	ctx.r11.s64 = -848;
	// lvx128 v75,r11,r12
	simd::store_shuffled(ctx.v75, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-832
	ctx.r11.s64 = -832;
	// lvx128 v76,r11,r12
	simd::store_shuffled(ctx.v76, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-816
	ctx.r11.s64 = -816;
	// lvx128 v77,r11,r12
	simd::store_shuffled(ctx.v77, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-800
	ctx.r11.s64 = -800;
	// lvx128 v78,r11,r12
	simd::store_shuffled(ctx.v78, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-784
	ctx.r11.s64 = -784;
	// lvx128 v79,r11,r12
	simd::store_shuffled(ctx.v79, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-768
	ctx.r11.s64 = -768;
	// lvx128 v80,r11,r12
	simd::store_shuffled(ctx.v80, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-752
	ctx.r11.s64 = -752;
	// lvx128 v81,r11,r12
	simd::store_shuffled(ctx.v81, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-736
	ctx.r11.s64 = -736;
	// lvx128 v82,r11,r12
	simd::store_shuffled(ctx.v82, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-720
	ctx.r11.s64 = -720;
	// lvx128 v83,r11,r12
	simd::store_shuffled(ctx.v83, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-704
	ctx.r11.s64 = -704;
	// lvx128 v84,r11,r12
	simd::store_shuffled(ctx.v84, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-688
	ctx.r11.s64 = -688;
	// lvx128 v85,r11,r12
	simd::store_shuffled(ctx.v85, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-672
	ctx.r11.s64 = -672;
	// lvx128 v86,r11,r12
	simd::store_shuffled(ctx.v86, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-656
	ctx.r11.s64 = -656;
	// lvx128 v87,r11,r12
	simd::store_shuffled(ctx.v87, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-640
	ctx.r11.s64 = -640;
	// lvx128 v88,r11,r12
	simd::store_shuffled(ctx.v88, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-624
	ctx.r11.s64 = -624;
	// lvx128 v89,r11,r12
	simd::store_shuffled(ctx.v89, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-608
	ctx.r11.s64 = -608;
	// lvx128 v90,r11,r12
	simd::store_shuffled(ctx.v90, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-592
	ctx.r11.s64 = -592;
	// lvx128 v91,r11,r12
	simd::store_shuffled(ctx.v91, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-576
	ctx.r11.s64 = -576;
	// lvx128 v92,r11,r12
	simd::store_shuffled(ctx.v92, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-560
	ctx.r11.s64 = -560;
	// lvx128 v93,r11,r12
	simd::store_shuffled(ctx.v93, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-544
	ctx.r11.s64 = -544;
	// lvx128 v94,r11,r12
	simd::store_shuffled(ctx.v94, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-528
	ctx.r11.s64 = -528;
	// lvx128 v95,r11,r12
	simd::store_shuffled(ctx.v95, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-512
	ctx.r11.s64 = -512;
	// lvx128 v96,r11,r12
	simd::store_shuffled(ctx.v96, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-496
	ctx.r11.s64 = -496;
	// lvx128 v97,r11,r12
	simd::store_shuffled(ctx.v97, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-480
	ctx.r11.s64 = -480;
	// lvx128 v98,r11,r12
	simd::store_shuffled(ctx.v98, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-464
	ctx.r11.s64 = -464;
	// lvx128 v99,r11,r12
	simd::store_shuffled(ctx.v99, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-448
	ctx.r11.s64 = -448;
	// lvx128 v100,r11,r12
	simd::store_shuffled(ctx.v100, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-432
	ctx.r11.s64 = -432;
	// lvx128 v101,r11,r12
	simd::store_shuffled(ctx.v101, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-416
	ctx.r11.s64 = -416;
	// lvx128 v102,r11,r12
	simd::store_shuffled(ctx.v102, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-400
	ctx.r11.s64 = -400;
	// lvx128 v103,r11,r12
	simd::store_shuffled(ctx.v103, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-384
	ctx.r11.s64 = -384;
	// lvx128 v104,r11,r12
	simd::store_shuffled(ctx.v104, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-368
	ctx.r11.s64 = -368;
	// lvx128 v105,r11,r12
	simd::store_shuffled(ctx.v105, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-352
	ctx.r11.s64 = -352;
	// lvx128 v106,r11,r12
	simd::store_shuffled(ctx.v106, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-336
	ctx.r11.s64 = -336;
	// lvx128 v107,r11,r12
	simd::store_shuffled(ctx.v107, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-320
	ctx.r11.s64 = -320;
	// lvx128 v108,r11,r12
	simd::store_shuffled(ctx.v108, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-304
	ctx.r11.s64 = -304;
	// lvx128 v109,r11,r12
	simd::store_shuffled(ctx.v109, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx128 v110,r11,r12
	simd::store_shuffled(ctx.v110, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx128 v111,r11,r12
	simd::store_shuffled(ctx.v111, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx128 v112,r11,r12
	simd::store_shuffled(ctx.v112, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx128 v113,r11,r12
	simd::store_shuffled(ctx.v113, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx128 v114,r11,r12
	simd::store_shuffled(ctx.v114, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx128 v115,r11,r12
	simd::store_shuffled(ctx.v115, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx128 v116,r11,r12
	simd::store_shuffled(ctx.v116, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx128 v117,r11,r12
	simd::store_shuffled(ctx.v117, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx128 v118,r11,r12
	simd::store_shuffled(ctx.v118, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx128 v119,r11,r12
	simd::store_shuffled(ctx.v119, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx128 v120,r11,r12
	simd::store_shuffled(ctx.v120, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx128 v121,r11,r12
	simd::store_shuffled(ctx.v121, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx128 v122,r11,r12
	simd::store_shuffled(ctx.v122, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx128 v123,r11,r12
	simd::store_shuffled(ctx.v123, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx128 v124,r11,r12
	simd::store_shuffled(ctx.v124, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx128 v125,r11,r12
	simd::store_shuffled(ctx.v125, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx128 v126,r11,r12
	simd::store_shuffled(ctx.v126, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx128 v127,r11,r12
	simd::store_shuffled(ctx.v127, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_69"))) PPC_WEAK_FUNC(__restvmx_69);
PPC_FUNC_IMPL(__imp____restvmx_69) {
	PPC_FUNC_PROLOGUE();
	// li r11,-944
	ctx.r11.s64 = -944;
	// lvx128 v69,r11,r12
	simd::store_shuffled(ctx.v69, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-928
	ctx.r11.s64 = -928;
	// lvx128 v70,r11,r12
	simd::store_shuffled(ctx.v70, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-912
	ctx.r11.s64 = -912;
	// lvx128 v71,r11,r12
	simd::store_shuffled(ctx.v71, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-896
	ctx.r11.s64 = -896;
	// lvx128 v72,r11,r12
	simd::store_shuffled(ctx.v72, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-880
	ctx.r11.s64 = -880;
	// lvx128 v73,r11,r12
	simd::store_shuffled(ctx.v73, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-864
	ctx.r11.s64 = -864;
	// lvx128 v74,r11,r12
	simd::store_shuffled(ctx.v74, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-848
	ctx.r11.s64 = -848;
	// lvx128 v75,r11,r12
	simd::store_shuffled(ctx.v75, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-832
	ctx.r11.s64 = -832;
	// lvx128 v76,r11,r12
	simd::store_shuffled(ctx.v76, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-816
	ctx.r11.s64 = -816;
	// lvx128 v77,r11,r12
	simd::store_shuffled(ctx.v77, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-800
	ctx.r11.s64 = -800;
	// lvx128 v78,r11,r12
	simd::store_shuffled(ctx.v78, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-784
	ctx.r11.s64 = -784;
	// lvx128 v79,r11,r12
	simd::store_shuffled(ctx.v79, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-768
	ctx.r11.s64 = -768;
	// lvx128 v80,r11,r12
	simd::store_shuffled(ctx.v80, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-752
	ctx.r11.s64 = -752;
	// lvx128 v81,r11,r12
	simd::store_shuffled(ctx.v81, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-736
	ctx.r11.s64 = -736;
	// lvx128 v82,r11,r12
	simd::store_shuffled(ctx.v82, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-720
	ctx.r11.s64 = -720;
	// lvx128 v83,r11,r12
	simd::store_shuffled(ctx.v83, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-704
	ctx.r11.s64 = -704;
	// lvx128 v84,r11,r12
	simd::store_shuffled(ctx.v84, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-688
	ctx.r11.s64 = -688;
	// lvx128 v85,r11,r12
	simd::store_shuffled(ctx.v85, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-672
	ctx.r11.s64 = -672;
	// lvx128 v86,r11,r12
	simd::store_shuffled(ctx.v86, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-656
	ctx.r11.s64 = -656;
	// lvx128 v87,r11,r12
	simd::store_shuffled(ctx.v87, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-640
	ctx.r11.s64 = -640;
	// lvx128 v88,r11,r12
	simd::store_shuffled(ctx.v88, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-624
	ctx.r11.s64 = -624;
	// lvx128 v89,r11,r12
	simd::store_shuffled(ctx.v89, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-608
	ctx.r11.s64 = -608;
	// lvx128 v90,r11,r12
	simd::store_shuffled(ctx.v90, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-592
	ctx.r11.s64 = -592;
	// lvx128 v91,r11,r12
	simd::store_shuffled(ctx.v91, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-576
	ctx.r11.s64 = -576;
	// lvx128 v92,r11,r12
	simd::store_shuffled(ctx.v92, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-560
	ctx.r11.s64 = -560;
	// lvx128 v93,r11,r12
	simd::store_shuffled(ctx.v93, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-544
	ctx.r11.s64 = -544;
	// lvx128 v94,r11,r12
	simd::store_shuffled(ctx.v94, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-528
	ctx.r11.s64 = -528;
	// lvx128 v95,r11,r12
	simd::store_shuffled(ctx.v95, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-512
	ctx.r11.s64 = -512;
	// lvx128 v96,r11,r12
	simd::store_shuffled(ctx.v96, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-496
	ctx.r11.s64 = -496;
	// lvx128 v97,r11,r12
	simd::store_shuffled(ctx.v97, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-480
	ctx.r11.s64 = -480;
	// lvx128 v98,r11,r12
	simd::store_shuffled(ctx.v98, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-464
	ctx.r11.s64 = -464;
	// lvx128 v99,r11,r12
	simd::store_shuffled(ctx.v99, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-448
	ctx.r11.s64 = -448;
	// lvx128 v100,r11,r12
	simd::store_shuffled(ctx.v100, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-432
	ctx.r11.s64 = -432;
	// lvx128 v101,r11,r12
	simd::store_shuffled(ctx.v101, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-416
	ctx.r11.s64 = -416;
	// lvx128 v102,r11,r12
	simd::store_shuffled(ctx.v102, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-400
	ctx.r11.s64 = -400;
	// lvx128 v103,r11,r12
	simd::store_shuffled(ctx.v103, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-384
	ctx.r11.s64 = -384;
	// lvx128 v104,r11,r12
	simd::store_shuffled(ctx.v104, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-368
	ctx.r11.s64 = -368;
	// lvx128 v105,r11,r12
	simd::store_shuffled(ctx.v105, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-352
	ctx.r11.s64 = -352;
	// lvx128 v106,r11,r12
	simd::store_shuffled(ctx.v106, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-336
	ctx.r11.s64 = -336;
	// lvx128 v107,r11,r12
	simd::store_shuffled(ctx.v107, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-320
	ctx.r11.s64 = -320;
	// lvx128 v108,r11,r12
	simd::store_shuffled(ctx.v108, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-304
	ctx.r11.s64 = -304;
	// lvx128 v109,r11,r12
	simd::store_shuffled(ctx.v109, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx128 v110,r11,r12
	simd::store_shuffled(ctx.v110, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx128 v111,r11,r12
	simd::store_shuffled(ctx.v111, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx128 v112,r11,r12
	simd::store_shuffled(ctx.v112, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx128 v113,r11,r12
	simd::store_shuffled(ctx.v113, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx128 v114,r11,r12
	simd::store_shuffled(ctx.v114, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx128 v115,r11,r12
	simd::store_shuffled(ctx.v115, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx128 v116,r11,r12
	simd::store_shuffled(ctx.v116, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx128 v117,r11,r12
	simd::store_shuffled(ctx.v117, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx128 v118,r11,r12
	simd::store_shuffled(ctx.v118, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx128 v119,r11,r12
	simd::store_shuffled(ctx.v119, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx128 v120,r11,r12
	simd::store_shuffled(ctx.v120, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx128 v121,r11,r12
	simd::store_shuffled(ctx.v121, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx128 v122,r11,r12
	simd::store_shuffled(ctx.v122, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx128 v123,r11,r12
	simd::store_shuffled(ctx.v123, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx128 v124,r11,r12
	simd::store_shuffled(ctx.v124, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx128 v125,r11,r12
	simd::store_shuffled(ctx.v125, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx128 v126,r11,r12
	simd::store_shuffled(ctx.v126, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx128 v127,r11,r12
	simd::store_shuffled(ctx.v127, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_70"))) PPC_WEAK_FUNC(__restvmx_70);
PPC_FUNC_IMPL(__imp____restvmx_70) {
	PPC_FUNC_PROLOGUE();
	// li r11,-928
	ctx.r11.s64 = -928;
	// lvx128 v70,r11,r12
	simd::store_shuffled(ctx.v70, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-912
	ctx.r11.s64 = -912;
	// lvx128 v71,r11,r12
	simd::store_shuffled(ctx.v71, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-896
	ctx.r11.s64 = -896;
	// lvx128 v72,r11,r12
	simd::store_shuffled(ctx.v72, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-880
	ctx.r11.s64 = -880;
	// lvx128 v73,r11,r12
	simd::store_shuffled(ctx.v73, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-864
	ctx.r11.s64 = -864;
	// lvx128 v74,r11,r12
	simd::store_shuffled(ctx.v74, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-848
	ctx.r11.s64 = -848;
	// lvx128 v75,r11,r12
	simd::store_shuffled(ctx.v75, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-832
	ctx.r11.s64 = -832;
	// lvx128 v76,r11,r12
	simd::store_shuffled(ctx.v76, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-816
	ctx.r11.s64 = -816;
	// lvx128 v77,r11,r12
	simd::store_shuffled(ctx.v77, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-800
	ctx.r11.s64 = -800;
	// lvx128 v78,r11,r12
	simd::store_shuffled(ctx.v78, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-784
	ctx.r11.s64 = -784;
	// lvx128 v79,r11,r12
	simd::store_shuffled(ctx.v79, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-768
	ctx.r11.s64 = -768;
	// lvx128 v80,r11,r12
	simd::store_shuffled(ctx.v80, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-752
	ctx.r11.s64 = -752;
	// lvx128 v81,r11,r12
	simd::store_shuffled(ctx.v81, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-736
	ctx.r11.s64 = -736;
	// lvx128 v82,r11,r12
	simd::store_shuffled(ctx.v82, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-720
	ctx.r11.s64 = -720;
	// lvx128 v83,r11,r12
	simd::store_shuffled(ctx.v83, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-704
	ctx.r11.s64 = -704;
	// lvx128 v84,r11,r12
	simd::store_shuffled(ctx.v84, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-688
	ctx.r11.s64 = -688;
	// lvx128 v85,r11,r12
	simd::store_shuffled(ctx.v85, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-672
	ctx.r11.s64 = -672;
	// lvx128 v86,r11,r12
	simd::store_shuffled(ctx.v86, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-656
	ctx.r11.s64 = -656;
	// lvx128 v87,r11,r12
	simd::store_shuffled(ctx.v87, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-640
	ctx.r11.s64 = -640;
	// lvx128 v88,r11,r12
	simd::store_shuffled(ctx.v88, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-624
	ctx.r11.s64 = -624;
	// lvx128 v89,r11,r12
	simd::store_shuffled(ctx.v89, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-608
	ctx.r11.s64 = -608;
	// lvx128 v90,r11,r12
	simd::store_shuffled(ctx.v90, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-592
	ctx.r11.s64 = -592;
	// lvx128 v91,r11,r12
	simd::store_shuffled(ctx.v91, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-576
	ctx.r11.s64 = -576;
	// lvx128 v92,r11,r12
	simd::store_shuffled(ctx.v92, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-560
	ctx.r11.s64 = -560;
	// lvx128 v93,r11,r12
	simd::store_shuffled(ctx.v93, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-544
	ctx.r11.s64 = -544;
	// lvx128 v94,r11,r12
	simd::store_shuffled(ctx.v94, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-528
	ctx.r11.s64 = -528;
	// lvx128 v95,r11,r12
	simd::store_shuffled(ctx.v95, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-512
	ctx.r11.s64 = -512;
	// lvx128 v96,r11,r12
	simd::store_shuffled(ctx.v96, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-496
	ctx.r11.s64 = -496;
	// lvx128 v97,r11,r12
	simd::store_shuffled(ctx.v97, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-480
	ctx.r11.s64 = -480;
	// lvx128 v98,r11,r12
	simd::store_shuffled(ctx.v98, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-464
	ctx.r11.s64 = -464;
	// lvx128 v99,r11,r12
	simd::store_shuffled(ctx.v99, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-448
	ctx.r11.s64 = -448;
	// lvx128 v100,r11,r12
	simd::store_shuffled(ctx.v100, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-432
	ctx.r11.s64 = -432;
	// lvx128 v101,r11,r12
	simd::store_shuffled(ctx.v101, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-416
	ctx.r11.s64 = -416;
	// lvx128 v102,r11,r12
	simd::store_shuffled(ctx.v102, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-400
	ctx.r11.s64 = -400;
	// lvx128 v103,r11,r12
	simd::store_shuffled(ctx.v103, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-384
	ctx.r11.s64 = -384;
	// lvx128 v104,r11,r12
	simd::store_shuffled(ctx.v104, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-368
	ctx.r11.s64 = -368;
	// lvx128 v105,r11,r12
	simd::store_shuffled(ctx.v105, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-352
	ctx.r11.s64 = -352;
	// lvx128 v106,r11,r12
	simd::store_shuffled(ctx.v106, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-336
	ctx.r11.s64 = -336;
	// lvx128 v107,r11,r12
	simd::store_shuffled(ctx.v107, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-320
	ctx.r11.s64 = -320;
	// lvx128 v108,r11,r12
	simd::store_shuffled(ctx.v108, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-304
	ctx.r11.s64 = -304;
	// lvx128 v109,r11,r12
	simd::store_shuffled(ctx.v109, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx128 v110,r11,r12
	simd::store_shuffled(ctx.v110, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx128 v111,r11,r12
	simd::store_shuffled(ctx.v111, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx128 v112,r11,r12
	simd::store_shuffled(ctx.v112, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx128 v113,r11,r12
	simd::store_shuffled(ctx.v113, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx128 v114,r11,r12
	simd::store_shuffled(ctx.v114, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx128 v115,r11,r12
	simd::store_shuffled(ctx.v115, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx128 v116,r11,r12
	simd::store_shuffled(ctx.v116, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx128 v117,r11,r12
	simd::store_shuffled(ctx.v117, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx128 v118,r11,r12
	simd::store_shuffled(ctx.v118, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx128 v119,r11,r12
	simd::store_shuffled(ctx.v119, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx128 v120,r11,r12
	simd::store_shuffled(ctx.v120, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx128 v121,r11,r12
	simd::store_shuffled(ctx.v121, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx128 v122,r11,r12
	simd::store_shuffled(ctx.v122, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx128 v123,r11,r12
	simd::store_shuffled(ctx.v123, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx128 v124,r11,r12
	simd::store_shuffled(ctx.v124, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx128 v125,r11,r12
	simd::store_shuffled(ctx.v125, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx128 v126,r11,r12
	simd::store_shuffled(ctx.v126, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx128 v127,r11,r12
	simd::store_shuffled(ctx.v127, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_71"))) PPC_WEAK_FUNC(__restvmx_71);
PPC_FUNC_IMPL(__imp____restvmx_71) {
	PPC_FUNC_PROLOGUE();
	// li r11,-912
	ctx.r11.s64 = -912;
	// lvx128 v71,r11,r12
	simd::store_shuffled(ctx.v71, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-896
	ctx.r11.s64 = -896;
	// lvx128 v72,r11,r12
	simd::store_shuffled(ctx.v72, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-880
	ctx.r11.s64 = -880;
	// lvx128 v73,r11,r12
	simd::store_shuffled(ctx.v73, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-864
	ctx.r11.s64 = -864;
	// lvx128 v74,r11,r12
	simd::store_shuffled(ctx.v74, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-848
	ctx.r11.s64 = -848;
	// lvx128 v75,r11,r12
	simd::store_shuffled(ctx.v75, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-832
	ctx.r11.s64 = -832;
	// lvx128 v76,r11,r12
	simd::store_shuffled(ctx.v76, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-816
	ctx.r11.s64 = -816;
	// lvx128 v77,r11,r12
	simd::store_shuffled(ctx.v77, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-800
	ctx.r11.s64 = -800;
	// lvx128 v78,r11,r12
	simd::store_shuffled(ctx.v78, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-784
	ctx.r11.s64 = -784;
	// lvx128 v79,r11,r12
	simd::store_shuffled(ctx.v79, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-768
	ctx.r11.s64 = -768;
	// lvx128 v80,r11,r12
	simd::store_shuffled(ctx.v80, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-752
	ctx.r11.s64 = -752;
	// lvx128 v81,r11,r12
	simd::store_shuffled(ctx.v81, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-736
	ctx.r11.s64 = -736;
	// lvx128 v82,r11,r12
	simd::store_shuffled(ctx.v82, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-720
	ctx.r11.s64 = -720;
	// lvx128 v83,r11,r12
	simd::store_shuffled(ctx.v83, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-704
	ctx.r11.s64 = -704;
	// lvx128 v84,r11,r12
	simd::store_shuffled(ctx.v84, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-688
	ctx.r11.s64 = -688;
	// lvx128 v85,r11,r12
	simd::store_shuffled(ctx.v85, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-672
	ctx.r11.s64 = -672;
	// lvx128 v86,r11,r12
	simd::store_shuffled(ctx.v86, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-656
	ctx.r11.s64 = -656;
	// lvx128 v87,r11,r12
	simd::store_shuffled(ctx.v87, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-640
	ctx.r11.s64 = -640;
	// lvx128 v88,r11,r12
	simd::store_shuffled(ctx.v88, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-624
	ctx.r11.s64 = -624;
	// lvx128 v89,r11,r12
	simd::store_shuffled(ctx.v89, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-608
	ctx.r11.s64 = -608;
	// lvx128 v90,r11,r12
	simd::store_shuffled(ctx.v90, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-592
	ctx.r11.s64 = -592;
	// lvx128 v91,r11,r12
	simd::store_shuffled(ctx.v91, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-576
	ctx.r11.s64 = -576;
	// lvx128 v92,r11,r12
	simd::store_shuffled(ctx.v92, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-560
	ctx.r11.s64 = -560;
	// lvx128 v93,r11,r12
	simd::store_shuffled(ctx.v93, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-544
	ctx.r11.s64 = -544;
	// lvx128 v94,r11,r12
	simd::store_shuffled(ctx.v94, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-528
	ctx.r11.s64 = -528;
	// lvx128 v95,r11,r12
	simd::store_shuffled(ctx.v95, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-512
	ctx.r11.s64 = -512;
	// lvx128 v96,r11,r12
	simd::store_shuffled(ctx.v96, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-496
	ctx.r11.s64 = -496;
	// lvx128 v97,r11,r12
	simd::store_shuffled(ctx.v97, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-480
	ctx.r11.s64 = -480;
	// lvx128 v98,r11,r12
	simd::store_shuffled(ctx.v98, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-464
	ctx.r11.s64 = -464;
	// lvx128 v99,r11,r12
	simd::store_shuffled(ctx.v99, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-448
	ctx.r11.s64 = -448;
	// lvx128 v100,r11,r12
	simd::store_shuffled(ctx.v100, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-432
	ctx.r11.s64 = -432;
	// lvx128 v101,r11,r12
	simd::store_shuffled(ctx.v101, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-416
	ctx.r11.s64 = -416;
	// lvx128 v102,r11,r12
	simd::store_shuffled(ctx.v102, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-400
	ctx.r11.s64 = -400;
	// lvx128 v103,r11,r12
	simd::store_shuffled(ctx.v103, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-384
	ctx.r11.s64 = -384;
	// lvx128 v104,r11,r12
	simd::store_shuffled(ctx.v104, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-368
	ctx.r11.s64 = -368;
	// lvx128 v105,r11,r12
	simd::store_shuffled(ctx.v105, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-352
	ctx.r11.s64 = -352;
	// lvx128 v106,r11,r12
	simd::store_shuffled(ctx.v106, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-336
	ctx.r11.s64 = -336;
	// lvx128 v107,r11,r12
	simd::store_shuffled(ctx.v107, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-320
	ctx.r11.s64 = -320;
	// lvx128 v108,r11,r12
	simd::store_shuffled(ctx.v108, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-304
	ctx.r11.s64 = -304;
	// lvx128 v109,r11,r12
	simd::store_shuffled(ctx.v109, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx128 v110,r11,r12
	simd::store_shuffled(ctx.v110, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx128 v111,r11,r12
	simd::store_shuffled(ctx.v111, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx128 v112,r11,r12
	simd::store_shuffled(ctx.v112, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx128 v113,r11,r12
	simd::store_shuffled(ctx.v113, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx128 v114,r11,r12
	simd::store_shuffled(ctx.v114, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx128 v115,r11,r12
	simd::store_shuffled(ctx.v115, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx128 v116,r11,r12
	simd::store_shuffled(ctx.v116, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx128 v117,r11,r12
	simd::store_shuffled(ctx.v117, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx128 v118,r11,r12
	simd::store_shuffled(ctx.v118, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx128 v119,r11,r12
	simd::store_shuffled(ctx.v119, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx128 v120,r11,r12
	simd::store_shuffled(ctx.v120, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx128 v121,r11,r12
	simd::store_shuffled(ctx.v121, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx128 v122,r11,r12
	simd::store_shuffled(ctx.v122, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx128 v123,r11,r12
	simd::store_shuffled(ctx.v123, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx128 v124,r11,r12
	simd::store_shuffled(ctx.v124, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx128 v125,r11,r12
	simd::store_shuffled(ctx.v125, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx128 v126,r11,r12
	simd::store_shuffled(ctx.v126, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx128 v127,r11,r12
	simd::store_shuffled(ctx.v127, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

__attribute__((alias("__imp____restvmx_72"))) PPC_WEAK_FUNC(__restvmx_72);
PPC_FUNC_IMPL(__imp____restvmx_72) {
	PPC_FUNC_PROLOGUE();
	// li r11,-896
	ctx.r11.s64 = -896;
	// lvx128 v72,r11,r12
	simd::store_shuffled(ctx.v72, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-880
	ctx.r11.s64 = -880;
	// lvx128 v73,r11,r12
	simd::store_shuffled(ctx.v73, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-864
	ctx.r11.s64 = -864;
	// lvx128 v74,r11,r12
	simd::store_shuffled(ctx.v74, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-848
	ctx.r11.s64 = -848;
	// lvx128 v75,r11,r12
	simd::store_shuffled(ctx.v75, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-832
	ctx.r11.s64 = -832;
	// lvx128 v76,r11,r12
	simd::store_shuffled(ctx.v76, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-816
	ctx.r11.s64 = -816;
	// lvx128 v77,r11,r12
	simd::store_shuffled(ctx.v77, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-800
	ctx.r11.s64 = -800;
	// lvx128 v78,r11,r12
	simd::store_shuffled(ctx.v78, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-784
	ctx.r11.s64 = -784;
	// lvx128 v79,r11,r12
	simd::store_shuffled(ctx.v79, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-768
	ctx.r11.s64 = -768;
	// lvx128 v80,r11,r12
	simd::store_shuffled(ctx.v80, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-752
	ctx.r11.s64 = -752;
	// lvx128 v81,r11,r12
	simd::store_shuffled(ctx.v81, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-736
	ctx.r11.s64 = -736;
	// lvx128 v82,r11,r12
	simd::store_shuffled(ctx.v82, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-720
	ctx.r11.s64 = -720;
	// lvx128 v83,r11,r12
	simd::store_shuffled(ctx.v83, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-704
	ctx.r11.s64 = -704;
	// lvx128 v84,r11,r12
	simd::store_shuffled(ctx.v84, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-688
	ctx.r11.s64 = -688;
	// lvx128 v85,r11,r12
	simd::store_shuffled(ctx.v85, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-672
	ctx.r11.s64 = -672;
	// lvx128 v86,r11,r12
	simd::store_shuffled(ctx.v86, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-656
	ctx.r11.s64 = -656;
	// lvx128 v87,r11,r12
	simd::store_shuffled(ctx.v87, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-640
	ctx.r11.s64 = -640;
	// lvx128 v88,r11,r12
	simd::store_shuffled(ctx.v88, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-624
	ctx.r11.s64 = -624;
	// lvx128 v89,r11,r12
	simd::store_shuffled(ctx.v89, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-608
	ctx.r11.s64 = -608;
	// lvx128 v90,r11,r12
	simd::store_shuffled(ctx.v90, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-592
	ctx.r11.s64 = -592;
	// lvx128 v91,r11,r12
	simd::store_shuffled(ctx.v91, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-576
	ctx.r11.s64 = -576;
	// lvx128 v92,r11,r12
	simd::store_shuffled(ctx.v92, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-560
	ctx.r11.s64 = -560;
	// lvx128 v93,r11,r12
	simd::store_shuffled(ctx.v93, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-544
	ctx.r11.s64 = -544;
	// lvx128 v94,r11,r12
	simd::store_shuffled(ctx.v94, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-528
	ctx.r11.s64 = -528;
	// lvx128 v95,r11,r12
	simd::store_shuffled(ctx.v95, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-512
	ctx.r11.s64 = -512;
	// lvx128 v96,r11,r12
	simd::store_shuffled(ctx.v96, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-496
	ctx.r11.s64 = -496;
	// lvx128 v97,r11,r12
	simd::store_shuffled(ctx.v97, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-480
	ctx.r11.s64 = -480;
	// lvx128 v98,r11,r12
	simd::store_shuffled(ctx.v98, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-464
	ctx.r11.s64 = -464;
	// lvx128 v99,r11,r12
	simd::store_shuffled(ctx.v99, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-448
	ctx.r11.s64 = -448;
	// lvx128 v100,r11,r12
	simd::store_shuffled(ctx.v100, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-432
	ctx.r11.s64 = -432;
	// lvx128 v101,r11,r12
	simd::store_shuffled(ctx.v101, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-416
	ctx.r11.s64 = -416;
	// lvx128 v102,r11,r12
	simd::store_shuffled(ctx.v102, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-400
	ctx.r11.s64 = -400;
	// lvx128 v103,r11,r12
	simd::store_shuffled(ctx.v103, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-384
	ctx.r11.s64 = -384;
	// lvx128 v104,r11,r12
	simd::store_shuffled(ctx.v104, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-368
	ctx.r11.s64 = -368;
	// lvx128 v105,r11,r12
	simd::store_shuffled(ctx.v105, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-352
	ctx.r11.s64 = -352;
	// lvx128 v106,r11,r12
	simd::store_shuffled(ctx.v106, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-336
	ctx.r11.s64 = -336;
	// lvx128 v107,r11,r12
	simd::store_shuffled(ctx.v107, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-320
	ctx.r11.s64 = -320;
	// lvx128 v108,r11,r12
	simd::store_shuffled(ctx.v108, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-304
	ctx.r11.s64 = -304;
	// lvx128 v109,r11,r12
	simd::store_shuffled(ctx.v109, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx128 v110,r11,r12
	simd::store_shuffled(ctx.v110, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx128 v111,r11,r12
	simd::store_shuffled(ctx.v111, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx128 v112,r11,r12
	simd::store_shuffled(ctx.v112, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx128 v113,r11,r12
	simd::store_shuffled(ctx.v113, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx128 v114,r11,r12
	simd::store_shuffled(ctx.v114, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx128 v115,r11,r12
	simd::store_shuffled(ctx.v115, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx128 v116,r11,r12
	simd::store_shuffled(ctx.v116, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx128 v117,r11,r12
	simd::store_shuffled(ctx.v117, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx128 v118,r11,r12
	simd::store_shuffled(ctx.v118, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx128 v119,r11,r12
	simd::store_shuffled(ctx.v119, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx128 v120,r11,r12
	simd::store_shuffled(ctx.v120, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx128 v121,r11,r12
	simd::store_shuffled(ctx.v121, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx128 v122,r11,r12
	simd::store_shuffled(ctx.v122, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx128 v123,r11,r12
	simd::store_shuffled(ctx.v123, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx128 v124,r11,r12
	simd::store_shuffled(ctx.v124, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx128 v125,r11,r12
	simd::store_shuffled(ctx.v125, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx128 v126,r11,r12
	simd::store_shuffled(ctx.v126, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx128 v127,r11,r12
	simd::store_shuffled(ctx.v127, simd::load_and_shuffle(base + ((ctx.r11.u32 + ctx.r12.u32) & ~0xF), VectorMaskL));
	// blr 
	return;
}

