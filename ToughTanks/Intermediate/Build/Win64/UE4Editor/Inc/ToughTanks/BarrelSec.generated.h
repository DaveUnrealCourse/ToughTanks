// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TOUGHTANKS_BarrelSec_generated_h
#error "BarrelSec.generated.h already included, missing '#pragma once' in BarrelSec.h"
#endif
#define TOUGHTANKS_BarrelSec_generated_h

#define ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_RPC_WRAPPERS
#define ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUBarrelSec(); \
	friend TOUGHTANKS_API class UClass* Z_Construct_UClass_UBarrelSec(); \
	public: \
	DECLARE_CLASS(UBarrelSec, UStaticMeshComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ToughTanks"), NO_API) \
	DECLARE_SERIALIZER(UBarrelSec) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_INCLASS \
	private: \
	static void StaticRegisterNativesUBarrelSec(); \
	friend TOUGHTANKS_API class UClass* Z_Construct_UClass_UBarrelSec(); \
	public: \
	DECLARE_CLASS(UBarrelSec, UStaticMeshComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/ToughTanks"), NO_API) \
	DECLARE_SERIALIZER(UBarrelSec) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBarrelSec(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBarrelSec) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBarrelSec); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBarrelSec); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UBarrelSec(UBarrelSec&&); \
	NO_API UBarrelSec(const UBarrelSec&); \
public:


#define ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UBarrelSec(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UBarrelSec(UBarrelSec&&); \
	NO_API UBarrelSec(const UBarrelSec&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UBarrelSec); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBarrelSec); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBarrelSec)


#define ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__MaxDegreesPerSecond() { return STRUCT_OFFSET(UBarrelSec, MaxDegreesPerSecond); } \
	FORCEINLINE static uint32 __PPO__MaxElevationDegrees() { return STRUCT_OFFSET(UBarrelSec, MaxElevationDegrees); } \
	FORCEINLINE static uint32 __PPO__MinElevationDegrees() { return STRUCT_OFFSET(UBarrelSec, MinElevationDegrees); }


#define ToughTanks_Source_ToughTanks_Public_BarrelSec_h_11_PROLOG
#define ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_PRIVATE_PROPERTY_OFFSET \
	ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_RPC_WRAPPERS \
	ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_INCLASS \
	ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_PRIVATE_PROPERTY_OFFSET \
	ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_INCLASS_NO_PURE_DECLS \
	ToughTanks_Source_ToughTanks_Public_BarrelSec_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ToughTanks_Source_ToughTanks_Public_BarrelSec_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
