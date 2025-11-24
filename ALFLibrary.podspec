#
# Be sure to run `pod lib lint ALFLibrary.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ALFLibrary'
  s.version          = '1.0.8.1'
  s.summary          = 'A short description of ALFLibrary.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/iOSbug/ALFLibrary'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Tianbao Wang' => '519955268@qq.com' }
  s.source           = { :git => 'https://github.com/iOSbug/ALFLibrary.git', :tag => s.version.to_s }

  s.ios.deployment_target = '11.0'
  s.swift_version = '5.0'
  s.default_subspec     = 'Core'

 s.subspec 'Core' do |ss|

  ss.vendored_frameworks = "libs/*.{framework}"


#   s.source_files = 'ALFLibrary/Classes/**/*'

#    ss.source_files        = 'ALFLibrary.framework/Headers/*.{h}'
    ss.resources           = 'ALFBundle.bundle'
    ss.preserve_paths      = 'ALFLibrary.framework/*', 'ALFBundle.bundle'

  ss.frameworks   = 'OpenGLES','Foundation','SystemConfiguration','OpenAL','Security','MediaPlayer','AVFoundation','CoreVideo','CoreAudio','CoreMedia','VideoToolbox','AudioToolbox','AdSupport','NetworkExtension','GLKit'
  
  ss.libraries = "c++.1", "iconv", "z", "bz2.1.0"

  ss.dependency 'Alamofire', '4.9.1'
  ss.dependency 'MBProgressHUD'
  ss.dependency 'SnapKit'
  ss.dependency 'CocoaAsyncSocket', '7.6.5'
  s.dependency 'MJRefresh'
  ss.dependency 'Material'
  ss.dependency 'lottie-ios','2.5.0'
  ss.dependency 'SDWebImage', "~> 5.11.0"
  ss.dependency 'AFNetworking', "~> 4.0.1"
  ss.dependency 'FCUUID'
  ss.dependency 'Sodium', '0.8.0'
  ss.dependency 'Masonry'
  ss.dependency 'SDVersion'
  ss.dependency 'SocketRocket'
  ss.dependency 'XCGLogger'
  ss.dependency 'ZipArchive'
  ss.dependency 'LSTCategory'
  ss.dependency 'CHIPageControl'
  ss.dependency 'ZKCycleScrollView'
  ss.dependency 'ALFOBSWrapper'
  ss.dependency 'MobileVLCKit', "~> 3.6.0"
  ss.dependency 'ffmpeg-kit-ios-full-gpl-ajc', '6.0.0'

 end


end
