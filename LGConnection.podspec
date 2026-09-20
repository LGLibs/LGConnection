Pod::Spec.new do |s|
    s.name = 'LGConnection'
    s.version = '1.0.5'
    s.platform = :ios, '6.0'
    s.license = 'MIT'
    s.homepage = 'https://github.com/LGLibs/LGConnection'
    s.author = { 'Grigorii Lutkov' => 'grigorii@lutkov.dev' }
    s.source = { :git => 'https://github.com/LGLibs/LGConnection.git', :tag => s.version }
    s.summary = 'iOS wrapper around AFNetworking makes it easy to use'
    s.requires_arc = true
    s.source_files = 'LGConnection/*.{h,m}'
    s.dependency 'AFNetworking', '~> 2.5.0'
    s.dependency 'Reachability', '~> 3.2'
    s.dependency 'XMLReader-Arc', '~> 1.1'
    s.dependency 'LGHelper', '~> 1.1.0'
end
