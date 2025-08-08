//
//  ALFCloudStorageDeleteModel.h
//  ALFLibrary
//
//  Created by HX on 2022/11/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ALFCloudStorageDeleteModel : NSObject
@property (nonatomic, copy) NSString * _Nullable groupId;
@property (nonatomic, strong) NSNumber * _Nullable tsStart;
@property (nonatomic, strong) NSNumber * _Nullable tsEnd;
@property (nonatomic, strong) NSNumber * delIndex;
@end

@interface ALFCloudStorageDeleteRealDayModel : NSObject
@property (nonatomic, strong) NSNumber * _Nullable dayStartTs;
@property (nonatomic, strong) NSNumber * _Nullable dayEndTs;
@end



NS_ASSUME_NONNULL_END
