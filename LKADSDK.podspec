#
# Be sure to run `pod lib lint LKADSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'LKADSDK'
  s.version          = '2.4.1.12'
  s.summary          = 'LKADSDK is a SDK providing union AD service.'

  s.description      = <<-DESC
LKADSDK provides Union ADs which include native、banner、feed、splash、RewardVideo etc.
                       DESC

  s.homepage         = 'https://github.com/peterJ123234/lkadsdk'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Peter' => 'peterwu@bloomadtech.com' }
  s.source           = { :git => 'https://github.com/peterJ123234/lkadsdk.git', :tag => s.version.to_s }

  s.ios.deployment_target = '9.0'
  
  s.vendored_frameworks = 'LKADSDK/SDK/LKADSDK.framework'
  s.resource = 'LKADSDK/SDK/LKADSDKBundle.bundle'

  s.dependency 'AFNetworking', '~> 3.2.1'
  s.dependency 'SDWebImage'
  s.dependency 'MJExtension'
  s.dependency 'ReactiveObjC', '3.0.0'
  s.dependency 'SVPullToRefresh'
  s.dependency 'Bytedance-UnionAD', '~> 2.9.0.1'
  s.dependency 'GDTMobSDK', '~> 4.11.3'
  
end
