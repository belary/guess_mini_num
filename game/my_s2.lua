local skynet = require('skynet')
skynet.start(function()
    skynet.error("My new Service ...")
    skynet.newservice("my_s1") -- 前面的服务
    skynet.error("new test service")
end
)