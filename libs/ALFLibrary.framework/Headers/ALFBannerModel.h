//
//  ALFBannerModel.h
//  ALFLibrary
//
//  Created by wtb on 2025/7/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ALFBannerNodeModel : NSObject
@property (nonatomic) BOOL enable;
@property (nonatomic, strong) NSString * redirectUrl;
@property (nonatomic, strong) NSString * enValue;
@property (nonatomic, strong) NSString * thaiValue;
@property (nonatomic, strong) NSString * value;

@end

@interface ALFBannerModel : NSObject
@property (nonatomic, strong) NSString * color;
@property (nonatomic, strong) NSString * createAt;
@property (nonatomic) BOOL enable;
@property (nonatomic, strong) NSString * endTime;
@property (nonatomic, strong) NSString * startTime;
@property (nonatomic, strong) ALFBannerNodeModel * more;
@property (nonatomic, strong) ALFBannerNodeModel * picture;
@property (nonatomic, strong) ALFBannerNodeModel * text;
@property (nonatomic, strong) NSString * notificationId;

@end

NS_ASSUME_NONNULL_END
