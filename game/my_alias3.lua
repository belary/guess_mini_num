local skynet = require("skynet")
require("skynet.manager")
local harbor = require("skynet.harbor")

skynet.start(function()
    local handle = skynet.newservice("my_s1")

    -- 本地别名
    -- skynet.name(".my_alias", handle)
    -- 全局别名
    skynet.name("mysvc", handle)

    handle = harbor.queryname("mysvc")
    skynet.error("queryname mysvc handle", skynet.address(handle))

    skynet.kill(handle) -- 杀死了全局的别名

    --
    -- 查找全局别名的两个测试
    handle = harbor.queryname("mysvc")
    skynet.error("queryname mysvc handle", skynet.address(handle)) -- 全局别名



end)