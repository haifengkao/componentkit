Pod::Spec.new do |s|
  s.name = 'ComponentKit'
  s.version = '0.31'
  s.license = 'BSD'
  s.summary = 'A React-inspired view framework for iOS'
  s.homepage = 'https://componentkit.org'
  s.social_media_url = 'https://twitter.com/componentkit'
  s.authors = 'adamjernst@fb.com'
  s.source = { :git => 'https://github.com/facebook/ComponentKit.git', :tag => s.version.to_s }
  s.ios.deployment_target = '13.0'
  s.requires_arc = true

  s.source_files = 'ComponentKit/**/*', 'ComponentTextKit/**/*'
  s.exclude_files = ['ComponentKit/Info.plist']
  s.frameworks = 'UIKit', 'CoreText'
  s.library = 'c++'
  s.xcconfig = {
    'CLANG_CXX_LANGUAGE_STANDARD' => 'gnu++14',
    'CLANG_CXX_LIBRARY' => 'libc++',
  }
  s.dependency 'RenderCore', s.version.to_s
  s.dependency 'Yoga', '~> 2.0.1'
end
