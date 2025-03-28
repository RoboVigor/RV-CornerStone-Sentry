#ifndef __HANDLE_H
#define __HANDLE_H

#include "sys.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "config.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "vegmath.h"
#include "Driver_BSP.h"
#include "Driver_Filter.h"

#include "Driver_PID.h"
#include "Driver_DBUS.h"
#include "Driver_CAN.h"
#include "Driver_Motor.h"
#include "Driver_Chassis.h"
#include "mpu6500_driver.h"
#include "Driver_Gyroscope.h"
#include "Driver_Protocol.h"
#include "Driver_Bridge.h"
#include "Driver_Magic.h"
#include "Driver_Fsm.h"
#include "Driver_Vofa.h"

#ifdef __HANDLE_GLOBALS
#define __HANDLE_EXT
#else
#define __HANDLE_EXT extern
#endif
__HANDLE_EXT uint16_t test;
// Stone Id
__HANDLE_EXT uint8_t Board_Id, Robot_Id;

// TIM
__HANDLE_EXT volatile uint32_t ulHighFrequencyTimerTicks;

// 功能开关
__HANDLE_EXT uint8_t ControlMode;
__HANDLE_EXT uint8_t FrictEnabled, StirEnabled, MagzineOpened;
__HANDLE_EXT uint8_t PsAimEnabled, PsShootEnabled;
__HANDLE_EXT uint8_t SwingMode, SafetyMode, PigeonMode;
 typedef enum {normalMove = 0, fastMove = 1, frictMove = 2}moveMode_t;
 typedef enum {normalShoot = 0, fastShoot = 1, frictShoot = 2}ShootMode_t;
__HANDLE_EXT moveMode_t moveMode;
__HANDLE_EXT ShootMode_t ShootMode;
__HANDLE_EXT uint8_t AutoEnabled;

// 上位机
__HANDLE_EXT uint8_t        FacingEnemyMode;
__HANDLE_EXT autoaim_data_t HostAutoaimData_L, HostAutoaimData_R;
__HANDLE_EXT chassis_data_t HostChassisData;

// 电机
__HANDLE_EXT Motor_Type Motor_LF, Motor_RF, Motor_RB, Motor_LB, Motor_LAJI;

// 云台
__HANDLE_EXT Motor_Type Motor_Yaw, Motor_Pitch, Motor_Pitch_L, Motor_Pitch_R, Motor_Yaw_L, Motor_Yaw_R;
__HANDLE_EXT PID_Type   PID_Cloud_YawAngle, PID_Cloud_YawSpeed, PID_Cloud_PitchAngle, PID_Cloud_PitchSpeed, PID_Cloud_MotorYawSpeed, \
                        PID_Secondary_PitchAngle_L, PID_Secondary_PitchAngle_R, PID_Secondary_PitchSpeed_L, PID_Secondary_PitchSpeed_R, \
                        PID_Secondary_YawAngle_L, PID_Secondary_YawAngle_R, PID_Secondary_YawSpeed_L, PID_Secondary_YawSpeed_R;
__HANDLE_EXT PID_Type   PID_Follow_Angle, PID_Follow_Speed;

// 遥控器
__HANDLE_EXT uint8_t       remoteBuffer[DBUS_LENGTH + DBUS_BACK_LENGTH];
__HANDLE_EXT Remote_Type   remoteData;
__HANDLE_EXT Keyboard_Type keyboardData;
__HANDLE_EXT Mouse_Type    mouseData;

// 陀螺仪
__HANDLE_EXT volatile ImuData_Type       ImuData;
__HANDLE_EXT volatile GyroscopeData_Type Gyroscope_EulerData;

// 调试数据
__HANDLE_EXT DebugData_Type *DebugData;
__HANDLE_EXT VofaData_type *VofaData;

// 底盘
__HANDLE_EXT ChassisData_Type ChassisData;
__HANDLE_EXT PID_Type         PID_LFCM, PID_LBCM, PID_RBCM, PID_RFCM, PID_YawAngle, PID_YawSpeed, PID_Fx, PID_Fy, PID_T, PID_Power, PID_Dx, PID_Dy;
__HANDLE_EXT uint8_t          PigeonCurrent, PigeonVoltage, PigeonEnergy, PigeonChargeEnable;

// 通讯协议
__HANDLE_EXT ProtocolData_Type ProtocolData;
__HANDLE_EXT Node_Type         Node_Judge, Node_Host, Node_Board, Node_SuperCap, Node_Debug;

// 弹舱盖舵机
__HANDLE_EXT PWM_Type PWM_Magazine_Servo;

//发射机构
__HANDLE_EXT Motor_Type Motor_Stir_L, Motor_Stir_R, Motor_FL_L,Motor_FR_L, Motor_FL_R, Motor_FR_R;                     // 左/右 摩擦轮 拨弹轮 电机
__HANDLE_EXT PID_Type   PID_StirSpeed_L, PID_StirAngle_L, PID_StirSpeed_R, PID_StirAngle_R, PID_FireL_L, PID_FireR_L, PID_FireL_R, PID_FireR_R; // 拨弹轮 速度/角度 PID

// PWM
__HANDLE_EXT PWM_Type PWM_Test;

// CAN
__HANDLE_EXT Bridge_Type BridgeData;
/**
 * @brief 初始化结构体
 * @note 该函数将在所有硬件及任务初始化之前执行
 */
void Handle_Init(void);

#endif
