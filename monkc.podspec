#
# Be sure to run `pod lib lint monkc.podspec' to ensure this is a
# valid spec before submitting.
#

Pod::Spec.new do |s|
  s.name             = 'monkc'
  s.version          = '1.0.1'
  s.summary          = 'a toolkit for OOP programming in C language'

  s.description      = 'Monk-C, is a toolkit for OOP programming use pure C (static library). the aim of Monk-C is to support OOP in pure C with some tiny C macros, functions and even a light preprocessor (optional). Monk-C is inspired by Apple Objective-C and gcc builtin "Constructing Calls". It is tiny and primitive but full of fun. I use it to play with my RaspberryPi and it really vary suitable for the ARM/Linux based embeded systems. It is open source under BSD license(3-clause license).'

  s.homepage         = 'https://github.com/sunpaq/monkc'
  s.license          = { :type => 'BSD', :file => 'LICENSE' }
  s.author           = { 'Sun YuLi' => 'sunpaq@gmail.com' }
  s.source           = { :git => 'https://github.com/sunpaq/monkc-pod.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'

  s.source_files        = 'monkc/Classes/**/*'
  s.public_header_files = 'monkc/Classes/**/*.h'
end
