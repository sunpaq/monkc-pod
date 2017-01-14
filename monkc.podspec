#
# Be sure to run `pod lib lint monkc.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'monkc'
  s.version          = '0.1.0'
  s.summary          = 'Monk-C is a Objective-C like tiny programming language'
  s.description      = 'Monk-C is a Objective-C like tiny programming language'

  s.homepage         = 'https://github.com/sunpaq/monkc'
  s.license          = { :type => 'BSD', :file => 'LICENSE' }
  s.author           = { 'Sun YuLi' => 'sunpaq@gmail.com' }
  s.source           = { :git => 'https://github.com/sunpaq/monkc.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'

  s.source_files        = 'monkc/Classes/**/*'
  s.public_header_files = 'Pod/Classes/**/*.h'

end
