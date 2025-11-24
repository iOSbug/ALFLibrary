//
//  ALFMediaPlayer.h
//  ALFLibrary
//
//  Created by HX on 2022/10/18.
//

#import <UIKit/UIKit.h>
#import "ALFAlertsListModel.h"
#import "ALFCloudStorageModel.h"


typedef enum {
    ALFMediaPlayerVideoRecord=1,
    ALFMediaPlayerPrivate
}ALFMediaPlayerDecodeType;

typedef enum {
    ALFMediaPlayerTalkModeFullDuplex=1,
    ALFMediaPlayerTalkModeHalfDuplex
}ALFMediaPlayerTalkMode;

@protocol ALFMediaPlayerDelegate <NSObject>
@optional
- (void)ALFMediaPlayerTimeChange;
- (void)ALFMediaPlayerTimeChange:(NSInteger)playTime;
- (void)ALFMediaPlayerVideoStartPlay;
- (void)ALFMediaPlayerStatusBuffering;
- (void)ALFMediaPlayerVideoisNotPlay;
- (void)ALFMediaPlayerVLCSPausetatus;
- (void)ALFMediaPlayerNetworkChangeRetryAction;
- (void)ALFMediaPlayerFullScreenAction:(BOOL)isFullscreen;
- (void)ALFMediaPlayerFullScreenActionOrientation:(UIDeviceOrientation)Orientation;
- (void)ALFMediaPlayerResolutionChange:(NSInteger)resolutionIndex;
- (void)ALFMediaPlayerResolutionDidTap;
- (void)ALFMediaPlayerWhitelightCtrl:(NSInteger)CtrlIndex;
- (void)ALFMediaPlayerFastforwordRateChange:(float)forwordRate;
- (void)ALFMediaPlayerFullscreenSideAction:(NSInteger)actionIndex;
- (void)ALFMediaPlayerFullscreenPTZEnd;
- (BOOL)ALFMediaPlayerShouldAutoRotated;
- (void)ALFMediaPlayerControlViewHide:(BOOL)isHide;
- (void)ALFMediaPlayerGotoLive;
- (void)ALFMediaPlayerLiveSpeed:(NSInteger)Speed;

@end

typedef void (^snapShotDoneAction)(UIImage *image);
@interface ALFMediaPlayer : UIView
@property (weak) id<ALFMediaPlayerDelegate>   delegate;
//@property (copy, nonatomic  )snapShotDoneAction snapCallback;
-(instancetype)initWithFrame:(CGRect)frame showView:(UIView *)View deviceId:(NSString *)deviceId;

/**
 *   Mute
 */
- (void)mute;

/**
 *   Is it muted
 */
- (BOOL)isMute;

/**
 *   Cancel mute
 */
- (void)cancelMute;

/**
 *  Start talking
 */
-(void)startTalk:(NSString *)cameraID;

/**
 *  Stop talking
 */
-(void)stopTalk:(NSString *)cameraID;

/**
 *  Is it recording
 */
-(BOOL)isVideoRecording;

/**
 *  Start live recording
 *  @param     filePath                Video file path
 */
- (int) startLocalRecordWithPath:(NSString *)filePath;

/**
 *  Stop live recording
 */
- (int) stopLocalRecord;

/**
 *  screenshot
 *  @param     path                Screenshot path
 *  @param     completion           uiimage callback (also saved in the path, mainly used for screenshot effect display)
 */
- (void)takeSnapShot:(NSString *)path completion:(snapShotDoneAction)completion;

/**
 *  Stop playing
 */
- (void)stop;

/**
 *  Destroy the player
 */
- (void)dismiss;

/**
 *  Playing  videos
 *  @param     URLString                video URL
 */
- (void)playWithURL:(NSString *)URLString;


/**
 *  Play alarm video
 *  @param     alertModel          告警model
 */
- (void)playAlertVideo:(ALFAlertModel *)alertModel;

/**
 *  Playing cloud storage videos
 */
- (void)playRecordVideo:(NSString *)deviceId record:(ALFCloudStorageModel *)reocrdModel;

/**
 *  Set video preview cover
 *  @param     image                Cover image
 */
- (void)showPlaceHolderImage:(UIImage *)image;

/**
 *  Screenshot animation
 *  @param     snapImage                image
 */
- (void)showSnapAnimation:(UIImage *)snapImage;

/**
 *  Set the video preview cover URL and the video URL (cloud storage).
 *  @param     imageUrl               Cover image URL
 *  @param     videoUrl                Video URL
 */
- (void)showPlaceHolderImage:(NSString *)imageUrl videoURL:(NSString *)videoUrl;

/**
 *  Play local video files
 *  @param     localPath                Local video file path
 */
- (void)playWithLocalPath:(NSString *)localPath;

/**
 *  Start live stream
 *  @param     cameraID                deviceId
 *  @param     qualityNum              resolution
 */
- (void)playVideoWithCameraId:(NSString *)cameraID qualityNum:(NSString *)qualityNum;

/**
 *  Start playing live audio
 *  @param     cameraID                deviceId
 */
-(void)playAudioWithCameraId:(NSString *)cameraID;


/**
 *  The following API videoRecordTpye ONLY! ! ! !
 *
 */
/**
 *  Can  pause in videoRecord mode
 *
 */
- (BOOL)canPause;

/**
 *  Pause in videoRecord mode
 *
 */
- (void)pause;

/**
 *  videoRecord mode Stop playback
 *
 */
- (void)playstop;

/**
 *  videoRecord mode has video output.
 *
 */
- (BOOL)hasVideoOut;

/**
 *  Is videoRecord mode  playing
 *
 */
- (BOOL)isPlaying;

/**
 *  Start playing in videoRecord mode
 *
 */
- (void)play;

/**
 *  videoRecord mode playback rate
 *
 */
- (void)setRate:(float)rate;


/**
 *  position Playback progress
 *
 */
-(BOOL)playPosition:(CGFloat)position;

/**
 *  talkMode (call mode)
 *
 *   Set only if the device supports full-duplex.
 *
 */
-(void)talkMode:(ALFMediaPlayerTalkMode)talkMode;


/**
 *  talkMode (call mode)
 *
 *   ALFMediaPlayerTalkModeHalfDuplex:  hold to talk (half-duplex);
 *   ALFMediaPlayerTalkModeFullDuplex: tap to talk mode (full-duplex).
 *
 */
- (ALFMediaPlayerTalkMode)getTalkMode;
@end


