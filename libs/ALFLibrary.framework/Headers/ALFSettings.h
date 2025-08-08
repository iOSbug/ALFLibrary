//
//  ALFSettings.h
//  ALFLibrary
//
//  Created by tmz on 2022/10/18.
//

#import <Foundation/Foundation.h>
#import "ALFError.h"
#import "ALFDiagnoseModel.h"
#import "ALFTimezoneModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ALFSettings : NSObject

+ (instancetype)shared;

/// 修改主设备的别名 （暂不使用，修改设备名称可直接使用changeUACDeviceAliasName）
/// @param deviceId 设备 ID
/// @param aliasName 别名
/// @param success success
/// @param failure failure
- (void)changeDeviceAliasName:(NSString *)deviceId
                    aliasName:(NSString *)aliasName
                      success:(nullable void (^)(void))success
                      failure:(nullable void (^)(ALFError *))failure;


/// 固件升级
/// @param deviceId  设备 ID
/// @param version 设备当前版本号 --> camera.base.newFwVersion
/// @param success success
/// @param failure failure
- (void)firmwareUpgrade:(NSString *)deviceId
                version:(NSString *)version
                success:(nullable void (^)(void))success
                failure:(nullable void (^)(ALFError *))failure;




/// 解绑设备
/// @param deviceId 设备 ID
/// @param success success
/// @param failure failure
- (void)unbindDevice:(NSString *)deviceId
             success:(nullable void (^)(void))success
             failure:(nullable void (^)(ALFError *))failure;



/// 图像旋转设置
/// @param deviceId  设备 ID
/// @param orientation  0 - 正常, 1 - 上下倒置, 2- 左右镜像, 3 - 镜像+倒置
/// @param success success
/// @param failure failure
- (void)orientationConfig:(NSString *)deviceId
              orientation:(NSString *)orientation
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(ALFError *))failure;


/// 照明频率设置
/// @param deviceId  设备 ID
/// @param freqValue  照明频率: 50Hz/60Hz,缺省值:50Hz, 北美地区-60Hz, 欧洲-50Hz
/// @param success success
/// @param failure failure
- (void)lightingFreqConfig:(NSString *)deviceId
                 freqValue:(NSInteger)freqValue
                   success:(nullable void (^)(void))success
                   failure:(nullable void (^)(ALFError *))failure;

/// 音频设置
/// @param deviceId 设备 ID
/// @param micEnable 麦克风开关 0 - 关，1 - 开
/// @param speakerVolume 麦克风音量 (0 - 100)
/// @param success success
/// @param failure failure
- (void)microphoneSetting:(NSString *)deviceId
                micEnable:(NSString *)micEnable
            speakerVolume:(NSString *)speakerVolume
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(ALFError *))failure;


/// 开启关闭指示灯
/// @param deviceId 设备 ID
/// @param enable  指示灯开关 0 - 关，1 - 开
/// @param success success
/// @param failure failure
- (void)indicatorLightConfig:(NSString *)deviceId
                      enable:(NSString *)enable
                     success:(nullable void (^)(void))success
                     failure:(nullable void (^)(ALFError *))failure;

/// 自动跟踪
/// @param deviceId 设备 ID
/// @param toggle  自动跟踪开关 off - 关闭，on - 开启
/// @param success success
/// @param failure failure
- (void)autoTrackConfig:(NSString *)deviceId
                 toggle:(NSString *)toggle
                success:(nullable void (^)(void))success
                failure:(nullable void (^)(ALFError *))failure;


/// 隐私模式配置 - 定时休眠
/// @param deviceId 设备 ID
/// @param enable 隐私模式总开关  0 - 关，1 - 开
/// @param wholeDayEnable 全天候开关  0 - 关，1 - 开
/// @param enable1 自定义时间1开关  0 - 关，1 - 开
/// @param startTime1 自定义1开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime1 自定义1结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays1 自定义1重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param enable2 自定义2开关  0 - 关，1 - 开
/// @param startTime2 自定义2开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime2 自定义2结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays2 自定义2重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param success success
/// @param failure failure
- (void)autoHibernateConfig:(NSString *)deviceId
                     enable:(NSString *)enable
             wholeDayEnable:(NSString *)wholeDayEnable
                    enable1:(NSString *)enable1
                 startTime1:(NSString *)startTime1
                   endTime1:(NSString *)endTime1
                  weekDays1:(NSArray<NSString *> *)weekDays1
                    enable2:(NSString *)enable2
                 startTime2:(NSString *)startTime2
                   endTime2:(NSString *)endTime2
                  weekDays2:(NSArray<NSString *> *)weekDays2
                    success:(nullable void (^)(void))success
                    failure:(nullable void (^)(ALFError *))failure;


/// 庭院灯灯光控制
/// @param deviceId 设备ID
/// @param toggle 开关：开 - "1"，关 - "0"
/// @param brightness 亮度 1-100
/// @param success success
/// @param failure failure
- (void)floodlightControl:(NSString *)deviceId
                   toggle:(NSString *)toggle
               brightness:(NSString *)brightness
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(ALFError *))failure;


/// 声音告警监测配置
/// @param deviceId 设备 ID
/// @param enable 隐私模式总开关  0 - 关，1 - 开
/// @param susceptiveness 灵敏度等级  0 ~ 5
/// @param wholeDayEnable 全天候开关  0 - 关，1 - 开
/// @param enable1 自定义时间1开关  0 - 关，1 - 开
/// @param startTime1 自定义1开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime1 自定义1结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays1 自定义1重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param enable2 自定义2开关  0 - 关，1 - 开
/// @param startTime2 自定义2开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime2 自定义2结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays2 自定义2重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param success success
/// @param failure failure
- (void)soundMonitorConfig:(NSString *)deviceId
                    enable:(NSString *)enable
            susceptiveness:(NSString *)susceptiveness
            wholeDayEnable:(NSString *)wholeDayEnable
                   enable1:(NSString *)enable1
                startTime1:(NSString *)startTime1
                  endTime1:(NSString *)endTime1
                 weekDays1:(NSArray<NSString *> *)weekDays1
                   enable2:(NSString *)enable2
                startTime2:(NSString *)startTime2
                  endTime2:(NSString *)endTime2
                 weekDays2:(NSArray<NSString *> *)weekDays2
                   success:(nullable void (^)(void))success
                   failure:(nullable void (^)(ALFError *))failure;


/// 隐私区域设置
/// @param deviceId 设备 ID
/// @param enable 启用隐私区域开关 0 - 关，1 - 开
/// @param 隐私区域位置 ["x0,y0,x1,y1"]，区间：整体最大 --> ["0,0,10000,10000"]
/// @param success success
/// @param failure failure
- (void)privateRegionConfig:(NSString *)deviceId
                     enable:(NSString *)enable
                         x0:(int)x0
                         y0:(int)y0
                         x1:(int)x1
                         y1:(int)y1
                    success:(nullable void (^)(void))success
                    failure:(nullable void (^)(ALFError *))failure;



/// 时区配置
/// @param deviceId 设备 ID
/// @param tzName 地区名称 例: 'Asia/Shanghai'
/// @param tzValue 时区时间 例: -480
/// @param autoAdjust 若从设备配置选择时区进行配置, 则autoAdjust = 0;  若绑定时, app获取手机操作系统时区(tzName,tzValue)对设备进行配置, 需autoAdjust = 1
/// @param tzDistrict 地区或城市, 统一使用城市: en 名称; app上按本地语言名称, 存储使用en名
/// @param success success
/// @param failure failure
- (void)timezoneConfig:(NSString *)deviceId
                tzName:(NSString *)tzName
               tzValue:(NSString *)tzValue
            autoAdjust:(NSString *)autoAdjust
            tzDistrict:(NSString *)tzDistrict
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(ALFError *))failure;

/// 时区列表
/// @param success success
/// @param failure failure
- (void)getTimezonelist:(nullable void (^)(NSArray<ALFTimezoneModel *> *))success
                failure:(nullable void (^)(ALFError *))failure;



/// 移动检测灵敏度等级和检测区域配置langge
/// @param deviceId 设备 ID
/// @param susceptiveness 灵敏度等级  0 ~ 5
/// @param fullViewport 是否全屏 0 - 是，1 - 否
/// @param  检测区域  ["'x0,y0,x1,y1"]，区间：整体最大 --> ["0,0,10000,10000"]
/// @param success success
/// @param failure failure
- (void)detectionsConfig:(NSString *)deviceId
          susceptiveness:(NSString *)susceptiveness
            fullViewport:(NSString *)fullViewport
                      x0:(int)x0
                      y0:(int)y0
                      x1:(int)x1
                      y1:(int)y1
                 success:(nullable void (^)(void))success
                 failure:(nullable void (^)(ALFError *))failure;


/// 人形侦测
/// @param deviceId 设备ID
/// @param humanoid 人形 0 - 关闭，1 - 开启
/// @param package  包裹 0 - 关闭，1 - 开启
/// @param pet 宠物  0 - 关闭，1 - 开启
/// @param vehicle  车辆 0 - 关闭，1 - 开启
/// @param pnmO1 其他  0 - 关闭，1 - 开启
/// @param success success
/// @param failure failure
- (void)alarmRekConfig:(NSString *)deviceId
              humanoid:(NSString *)humanoid
               package:(NSString *)package
                   pet:(NSString *)pet
               vehicle:(NSString *)vehicle
                 pnmO1:(NSString *)pnmO1
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(ALFError *))failure;


/// 移动告警 设置
/// @param deviceId 设备 ID
/// @param enable 0 - 关，1 - 开
/// @param genAlarmThumb 富文本通知，0 - 关，1 - 开
/// @param wholeDayEnable 全天候时间开关 0 - 关，1 - 开
/// @param enable1 自定义时间表1开关 0 - 关，1 - 开
/// @param startTime1 自定义1开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime1 自定义1结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays1 自定义1重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param enable2 自定义2开关  0 - 关，1 - 开
/// @param startTime2 自定义2开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime2 自定义2结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays2 自定义2重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param success success
/// @param failure failure
- (void)moveMonitorConfig:(NSString *)deviceId
                   enable:(NSString *)enable
            genAlarmThumb:(NSString *)genAlarmThumb
           wholeDayEnable:(NSString *)wholeDayEnable
                  enable1:(NSString *)enable1
               startTime1:(NSString *)startTime1
                 endTime1:(NSString *)endTime1
                weekDays1:(NSArray<NSString *> *)weekDays1
                  enable2:(NSString *)enable2
               startTime2:(NSString *)startTime2
                 endTime2:(NSString *)endTime2
                weekDays2:(NSArray<NSString *> *)weekDays2
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(ALFError *))failure;



/// 灯光与夜视配置
/// @param deviceId 设备ID
/// @param toggle 'on' | 'off', // 此值，从 floodlightConfig.toggle 获取
/// @param brightness 亮度
/// @param enable 自动夜视是否开启  0 - 关，1 - 开
/// @param lightingDur 延迟 后自动关闭时间
/// @param triggersOn action-detect(智能灯光模式)，night-mode(夜晚全彩模式)，timing(定时灯光模式)， infrared(自动红外模式)，lightOff(全关闭模式)
/// @param success success
/// @param failure failure
- (void)floodlightConfig:(NSString *)deviceId
                  toggle:(NSString *)toggle
              brightness:(NSString *)brightness
                  enable:(NSString *)enable
             lightingDur:(NSString *)lightingDur
              triggersOn:(NSArray<NSString *> *)triggersOn
                 success:(nullable void (^)(void))success
                 failure:(nullable void (^)(ALFError *))failure;



/// 本地存储配置
/// @param deviceId 设备ID
/// @param enable 本地存储总开关  0 - 关，1 - 开
/// @param nasPath nas 路径 localStorage.nasPath
/// @param playUrlRoot  localStorage.playUrlRoot (http://{netwowrkConfig.local_ip}/api)
/// @param quality 视频质量
/// @param storageType localStorage.storageType
/// @param triggerMode  0 - 缺省(移动或声音侦测), 1-24H
/// @param writeMode 当空间存满时，存储模式 ( 1 - 覆盖最早存储，2 - 停止存储 )
/// @param wholeDayEnable 全天候时间开关 0 - 关，1 - 开
/// @param wholeStartTime 全天候开始时间 ( 000000 )
/// @param wholeEndTime 全天候结束时间 ( 235959 )
/// @param wholeWeekDays 全天候星期配置 ( [1, 2, 3, 4, 5, 6, 7] - > 每天 )
/// @param wholeFormat localStorConfig.policies[0].format
/// @param enable1 自定义时间表1开关 0 - 关，1 - 开
/// @param startTime1 自定义1开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime1 自定义1结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays1 自定义1重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param format1 传 localStorConfig.policies[1].format
/// @param enable2 自定义2开关  0 - 关，1 - 开
/// @param startTime2 自定义2开始时间 (例：传093000，指 09: 30: 00)
/// @param endTime2 自定义2结束时间 (例：传173000，指 17: 30: 00)
/// @param weekDays2 自定义2重复天 ( 例：@[@"1", @"3", @"5", @"6"]，周一、三、五、六 )
/// @param format2 传 localStorConfig.policies[2].format
/// @param ecoRecordDurationLimit 仅电池供电时最长录制时长 ( [10, 20, 30, 40, 50, 60] ) 秒
/// @param success success
/// @param failure failure
- (void)localStorageSetting:(NSString *)deviceId
                     enable:(NSString *)enable
                    nasPath:(NSString *)nasPath
                playUrlRoot:(NSString *)playUrlRoot
                    quality:(NSString *)quality
                storageType:(NSString *)storageType
                triggerMode:(NSString *)triggerMode
                  writeMode:(NSString *)writeMode
             wholeDayEnable:(NSString *)wholeDayEnable
             wholeStartTime:(NSString *)wholeStartTime
               wholeEndTime:(NSString *)wholeEndTime
              wholeWeekDays:(NSArray<NSString *> *)wholeWeekDays
                wholeFormat:(NSString *)wholeFormat
                    enable1:(NSString *)enable1
                 startTime1:(NSString *)startTime1
                   endTime1:(NSString *)endTime1
                  weekDays1:(NSArray<NSString *> *)weekDays1
                    format1:(NSString *)format1
                    enable2:(NSString *)enable2
                 startTime2:(NSString *)startTime2
                   endTime2:(NSString *)endTime2
                  weekDays2:(NSArray<NSString *> *)weekDays2
                    format2:(NSString *)format2
     ecoRecordDurationLimit:(NSInteger)ecoRecordDurationLimit
                    success:(nullable void (^)(void))success
                    failure:(nullable void (^)(ALFError *))failure;



/// 格式化 TF 卡
/// @param deviceId 设备 ID
/// @param success success
/// @param failure failure
- (void)formatTfCard:(NSString *)deviceId
             success:(nullable void (^)(void))success
             failure:(nullable void (^)(ALFError *))failure;



/// 设备截取画面
/// @param deviceId 设备 ID
/// @param success success
/// @param failure failure
- (void)setSnapshot:(NSString *)deviceId
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(ALFError *))failure;



/// 摄像机开关 ON/OFF
/// @param deviceId 设备 ID
/// @param enable 开关 0 - 关，1 - 开
/// @param success success
/// @param failure failure
- (void)hibernateConfig:(NSString *)deviceId
                 enable:(NSString *)enable
                success:(nullable void (^)(void))success
                failure:(nullable void (^)(ALFError *))failure;



/// 恢复出厂设置
/// @param deviceId 设备 ID
/// @param success success
/// @param failure failure
- (void)retoreFactory:(NSString *)deviceId
              success:(nullable void (^)(void))success
              failure:(nullable void (^)(ALFError *))failure;



/// 重启设备
/// @param deviceId 设备 ID
/// @param success success
/// @param failure failure
- (void)restart:(NSString *)deviceId
        success:(nullable void (^)(void))success
        failure:(nullable void (^)(ALFError *))failure;


/// 报警开关控制
/// @param deviceId 设备 ID
/// @param isOn  0:关 1:开
/// @param success success
/// @param failure failure
- (void)sirenControl:(NSString *)deviceId
                isOn:(NSString *)isOn
             success:(nullable void (^)(void))success
             failure:(nullable void (^)(ALFError *))failure;



/// 移动触发报警开关控制
/// @param deviceId 设备 ID
/// @param isOn  0:关 1:开
/// @param success success
/// @param failure failure
- (void)sirenByMotionCtrl:(NSString *)deviceId
                     isOn:(NSString *)isOn
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(ALFError *))failure;


/// 加载诊断服务器地址
- (NSArray<ALFDiagnoseModel *>*)loadDiagnoseServiceUrls;

@end

NS_ASSUME_NONNULL_END
