//
//  ALFBindDeviceModel.h
//  ALFLibrary
//
//  Created by wtb on 2025/7/15.
//

#import <Foundation/Foundation.h>
#import "ALFDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface ALFBindDeviceModel : NSObject

@property (nonatomic, strong) NSString *deviceName;
@property (nonatomic, strong) NSString * deviceId;
@property (nonatomic, strong) NSString * uuid;
@property (nonatomic) ALFAccountGroup accountGroup;

@end

NS_ASSUME_NONNULL_END
