//
//  ALFAlertsListModel.h
//  ALFLibrary
//
//  Created by tmz on 2022/10/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ALFCognitiveModel : NSObject

@property (nonatomic, strong) NSString *value;
//@property (nonatomic, strong) NSString *confidence;
@property (nonatomic, strong) NSString *type;

@end

@interface ALFAvsModel : NSObject

@property (nonatomic, strong) NSString *tags;
@property (nonatomic, strong) NSString *url;

@end

@interface ALFAlertModel : NSObject

@property (nonatomic, strong) NSString *did;
@property (nonatomic, strong) NSString *ats;
@property (nonatomic, strong) NSString *ctime;
@property (nonatomic, strong) NSArray<ALFAvsModel *> *avs;
@property (nonatomic, strong) NSArray<ALFCognitiveModel *> *cognitives;
@property (nonatomic, strong) NSString *cts;
@property (nonatomic, strong) NSString *duration;
@property (nonatomic, strong) NSArray<ALFAvsModel *> *images;
@property (nonatomic, strong) NSString *tsStart;
@property (nonatomic, strong) NSString *tsEnd;
@property (nonatomic, strong) NSString *groupId;
@property (nonatomic, strong) NSString *videoFormatTime;
@property (nonatomic, strong) NSString *coverImage;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSString *videoUrl;
@end


@interface ALFAlertsListModel : NSObject

@property (nonatomic, strong) NSArray<ALFAlertModel *> *alarms;
@property (nonatomic, strong) NSString *cts;
@property (nonatomic, strong) NSString *ctime;

@end

NS_ASSUME_NONNULL_END
