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

/// Modify the alias of the primary device (not used yet; to change the device name, you can directly use changeUACDeviceAliasName).
/// @param deviceId deviceId
/// @param aliasName 别名
/// @param success success
/// @param failure failure
- (void)changeDeviceAliasName:(NSString *)deviceId
                    aliasName:(NSString *)aliasName
                      success:(nullable void (^)(void))success
                      failure:(nullable void (^)(ALFError *))failure;


/// Firmware upgrade
/// @param deviceId  deviceId
/// @param version  Current device version number --> camera.base.newFwVersion
/// @param success success
/// @param failure failure
- (void)firmwareUpgrade:(NSString *)deviceId
                version:(NSString *)version
                success:(nullable void (^)(void))success
                failure:(nullable void (^)(ALFError *))failure;




/// Unbind device
/// @param deviceId deviceId
/// @param success success
/// @param failure failure
- (void)unbindDevice:(NSString *)deviceId
             success:(nullable void (^)(void))success
             failure:(nullable void (^)(ALFError *))failure;



/// Image rotation settings
/// @param deviceId  deviceId
/// @param orientation  0 - Normal, 1 - Upside down, 2 - Mirror image, 3 - Mirror image + Upside down
/// @param success success
/// @param failure failure
- (void)orientationConfig:(NSString *)deviceId
              orientation:(NSString *)orientation
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(ALFError *))failure;


/// Lighting frequency settings
/// @param deviceId  deviceId
/// @param freqValue  Lighting frequency: 50Hz/60Hz, default: 50Hz, North America - 60Hz, Europe - 50Hz
/// @param success success
/// @param failure failure
- (void)lightingFreqConfig:(NSString *)deviceId
                 freqValue:(NSInteger)freqValue
                   success:(nullable void (^)(void))success
                   failure:(nullable void (^)(ALFError *))failure;

/// Audio settings
/// @param deviceId deviceId
/// @param micEnable  Microphone switch: 0 - Off, 1 - On
/// @param speakerVolume Microphone volume (0 - 100)
/// @param success success
/// @param failure failure
- (void)microphoneSetting:(NSString *)deviceId
                micEnable:(NSString *)micEnable
            speakerVolume:(NSString *)speakerVolume
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(ALFError *))failure;


/// On/Off Indicator Light
/// @param deviceId deviceId
/// @param enable  Indicator light switch: 0 - Off, 1 - On
/// @param success success
/// @param failure failure
- (void)indicatorLightConfig:(NSString *)deviceId
                      enable:(NSString *)enable
                     success:(nullable void (^)(void))success
                     failure:(nullable void (^)(ALFError *))failure;

/// Automatic tracking
/// @param deviceId deviceId
/// @param toggle  Automatic tracking switch: off - off, on - on
/// @param success success
/// @param failure failure
- (void)autoTrackConfig:(NSString *)deviceId
                 toggle:(NSString *)toggle
                success:(nullable void (^)(void))success
                failure:(nullable void (^)(ALFError *))failure;


/// Privacy Mode Configuration - Scheduled Sleep
/// @param deviceId deviceId
/// @param enable Master switch 0 - Off, 1 - On
/// @param wholeDayEnable 24/7 switch: 0 - Off, 1 - On
/// @param enable1 Custom time switch: 0 - Off, 1 - On
/// @param startTime1 Custom start time 1 (e.g., passing 093000 means 09:30:00)
/// @param endTime1  Custom end time (e.g., 173000 means 17:30:00)
/// @param weekDays1 Customize the repeating day (e.g., @[@"1", @"3", @"5", @"6"], Monday, Wednesday, Friday, Saturday)
/// @param enable2  Custom 2-switch: 0 - Off, 1 - On
/// @param startTime2 Custom start time 2 (e.g., passing 093000 means 09:30:00)
/// @param endTime2 Custom end time 2 (e.g., sending 173000 means 17:30:00)
/// @param weekDays2 Customize two repeating days (e.g., @[@"1", @"3", @"5", @"6"], Monday, Wednesday, Friday, Saturday)
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


/// Courtyard light control
/// @param deviceId deviceId
/// @param toggle Switch: On - "1", Off - "0"
/// @param brightness Brightness 1-100
/// @param success success
/// @param failure failure
- (void)floodlightControl:(NSString *)deviceId
                   toggle:(NSString *)toggle
               brightness:(NSString *)brightness
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(ALFError *))failure;


/// Sound alarm monitoring configuration
/// @param deviceId deviceId
/// @param enable  Master switch 0 - Off, 1 - On
/// @param susceptiveness Sensitivity level 0 ~ 5
/// @param wholeDayEnable 24/7 switch: 0 - Off, 1 - On
/// @param enable1 Custom time switch: 0 - Off, 1 - On
/// @param startTime1 Custom start time 1 (e.g., passing 093000 means 09:30:00)
/// @param endTime1 Custom end time (e.g., 173000 means 17:30:00)
/// @param weekDays1 Customize the repeating day (e.g., @[@"1", @"3", @"5", @"6"], Monday, Wednesday, Friday, Saturday)
/// @param enable2 Custom 2-switch: 0 - Off, 1 - On
/// @param startTime2 Custom start time 2 (e.g., passing 093000 means 09:30:00)
/// @param endTime2 Custom end time 2 (e.g., sending 173000 means 17:30:00)
/// @param weekDays2 Customize two repeating days (e.g., @[@"1", @"3", @"5", @"6"], Monday, Wednesday, Friday, Saturday)
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


/// Privacy settings
/// @param deviceId deviceId
/// @param enable Enable privacy zone switch: 0 - Off, 1 - On
/// @param x0   Location coordinates of privacy area
/// @param y0  Location coordinates of privacy area
/// @param x1 Location coordinates of privacy area
/// @param y1 Location coordinates of privacy area
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



/// Timezone configuration
/// @param deviceId deviceId
/// @param tzName Region name, e.g., 'Asia/Shanghai'
/// @param tzValue Time zone, e.g., -480
/// @param autoAdjust If the time zone is selected from the device settings, then `autoAdjust = 0`; if the app obtains the phone's operating system time zone (tzName, tzValue) to configure the device during binding, then `autoAdjust = 1`.
/// @param tzDistrict For regions or cities, use the city name (en name); on the app, use the local language name, and store it using the en name.
/// @param success success
/// @param failure failure
- (void)timezoneConfig:(NSString *)deviceId
                tzName:(NSString *)tzName
               tzValue:(NSString *)tzValue
            autoAdjust:(NSString *)autoAdjust
            tzDistrict:(NSString *)tzDistrict
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(ALFError *))failure;

/// Time zone list
/// @param success success
/// @param failure failure
- (void)getTimezonelist:(nullable void (^)(NSArray<ALFTimezoneModel *> *))success
                failure:(nullable void (^)(ALFError *))failure;



/// Motion detection sensitivity level and detection area configuration
/// @param deviceId deviceId
/// @param susceptiveness Sensitivity level 0 ~ 5
/// @param fullViewport Fullscreen mode: 0 - Yes, 1 - No
/// @param x0   Detection area coordinates
/// @param y0  Detection area coordinates
/// @param x1 Detection area coordinates
/// @param y1 Detection area coordinates
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


/// Human detection
/// @param deviceId deviceId
/// @param humanoid Humanoid 0 - Off, 1 - On
/// @param package  Package 0 - Closed, 1 - Open
/// @param pet Pet 0 - Off, 1 - On
/// @param vehicle  Vehicle 0 - Off, 1 - On
/// @param pnmO1 Other 0 - Off, 1 - On
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


/// Motion Alarm Settings
/// @param deviceId deviceId
/// @param enable 0 - Off, 1 - On
/// @param genAlarmThumb Rich text notifications: 0 - Off, 1 - On
/// @param wholeDayEnable 24/7 time switch: 0 - Off, 1 - On
/// @param enable1 Custom schedule 1 switch: 0 - Off, 1 - On
/// @param startTime1 Custom start time 1 (e.g., passing 093000 means 09:30:00)
/// @param endTime1 Custom end time (e.g., 173000 means 17:30:00)
/// @param weekDays1 Customize the repeating day (e.g., @[@"1", @"3", @"5", @"6"], Monday, Wednesday, Friday, Saturday)
/// @param enable2 Custom 2-switch: 0 - Off, 1 - On
/// @param startTime2 Custom start time 2 (e.g., passing 093000 means 09:30:00)
/// @param endTime2 Custom end time 2 (e.g., sending 173000 means 17:30:00)
/// @param weekDays2 Customize two repeating days (e.g., @[@"1", @"3", @"5", @"6"], Monday, Wednesday, Friday, Saturday)
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



/// Lighting and night vision configuration
/// @param deviceId deviceId
/// @param toggle 'on' | 'off', floodlightConfig.toggle
/// @param brightness brightness
/// @param enable Automatic night vision enabled: 0 - Off, 1 - On
/// @param lightingDur Automatic shutdown time after delay
/// @param triggersOn Action-detect (intelligent lighting mode), Night-mode (full-color night mode), Timing (timed lighting mode), Infrared (automatic infrared mode), LightOff (fully off mode)
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



/// Local storage configuration
/// @param deviceId deviceId
/// @param enable Local storage master switch: 0 - Off, 1 - On
/// @param nasPath nas  localStorage.nasPath
/// @param playUrlRoot  localStorage.playUrlRoot (http://{netwowrkConfig.local_ip}/api)
/// @param quality Video quality
/// @param storageType localStorage.storageType
/// @param triggerMode  0 - Default (motion or sound detection), 1-24H
/// @param writeMode When the space is full, the storage mode is (1 - overwrite the oldest storage, 2 - stop storing).
/// @param wholeDayEnable 24/7 time switch: 0 - Off, 1 - On
/// @param wholeStartTime All-day start time (000000)
/// @param wholeEndTime End time for all hours (235959)
/// @param wholeWeekDays 24/7 Sunday Schedule ([1, 2, 3, 4, 5, 6, 7] -> Daily)
/// @param wholeFormat localStorConfig.policies[0].format
/// @param enable1 Custom schedule 1 switch: 0 - Off, 1 - On
/// @param startTime1 Custom start time 1 (e.g., passing 093000 means 09:30:00)
/// @param endTime1 Custom end time (e.g., 173000 means 17:30:00)
/// @param weekDays1 Customize the repeating day (e.g., @[@"1", @"3", @"5", @"6"], Monday, Wednesday, Friday, Saturday)
/// @param format1  localStorConfig.policies[1].format
/// @param enable2 Custom 2-switch: 0 - Off, 1 - On
/// @param startTime2 Custom start time 2 (e.g., passing 093000 means 09:30:00)
/// @param endTime2 Custom end time 2 (e.g., sending 173000 means 17:30:00)
/// @param weekDays2 Customize two repeating days (e.g., @[@"1", @"3", @"5", @"6"], Monday, Wednesday, Friday, Saturday)
/// @param format2  localStorConfig.policies[2].format
/// @param ecoRecordDurationLimit Maximum recording time on battery only ([10, 20, 30, 40, 50, 60]) seconds
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



/// Format TF card
/// @param deviceId deviceId
/// @param success success
/// @param failure failure
- (void)formatTfCard:(NSString *)deviceId
             success:(nullable void (^)(void))success
             failure:(nullable void (^)(ALFError *))failure;



/// Captured by device
/// @param deviceId deviceId
/// @param success success
/// @param failure failure
- (void)setSnapshot:(NSString *)deviceId
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(ALFError *))failure;



/// Camera switch ON/OFF
/// @param deviceId deviceId
/// @param enable Switch 0 - Off, 1 - On
/// @param success success
/// @param failure failure
- (void)hibernateConfig:(NSString *)deviceId
                 enable:(NSString *)enable
                success:(nullable void (^)(void))success
                failure:(nullable void (^)(ALFError *))failure;



/// Restore factory settings
/// @param deviceId deviceId
/// @param success success
/// @param failure failure
- (void)retoreFactory:(NSString *)deviceId
              success:(nullable void (^)(void))success
              failure:(nullable void (^)(ALFError *))failure;



/// Restart the device
/// @param deviceId deviceId
/// @param success success
/// @param failure failure
- (void)restart:(NSString *)deviceId
        success:(nullable void (^)(void))success
        failure:(nullable void (^)(ALFError *))failure;


/// Alarm switch control
/// @param deviceId deviceId
/// @param isOn  0: Off 1: On
/// @param success success
/// @param failure failure
- (void)sirenControl:(NSString *)deviceId
                isOn:(NSString *)isOn
             success:(nullable void (^)(void))success
             failure:(nullable void (^)(ALFError *))failure;



/// Movement-triggered alarm switch control
/// @param deviceId deviceId
/// @param isOn  0: Off 1: On
/// @param success success
/// @param failure failure
- (void)sirenByMotionCtrl:(NSString *)deviceId
                     isOn:(NSString *)isOn
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(ALFError *))failure;


/// Load diagnostic server address
- (NSArray<ALFDiagnoseModel *>*)loadDiagnoseServiceUrls;

@end

NS_ASSUME_NONNULL_END
