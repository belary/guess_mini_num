local skynet = require("skynet")
require("skynet.manager")
local harbor = require("skynet.harbor")

skynet.start(function()
    local handle = skynet.newservice("my_s1")

    -- 全局别名
    skynet.name("mysvc", handle)
    -- 查询全局别名
    handle = harbor.queryname("mysvc")
    skynet.error("queryname mysvc handle", skynet.address(handle))

    skynet.kill(handle) -- 杀死了全局的别名

    -- 再启动一次服务
    handle = skynet.newservice("my_s1")
    skynet.name("mysvc", handle) -- 再次起全局名

    skynet.error("queryname mysvc handle", skynet.address(handle))



end)