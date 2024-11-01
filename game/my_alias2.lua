local skynet = require("skynet")
require("skynet.manager")
local harbor = require("skynet.harbor")

skynet.start(function()
    local handle = skynet.newservice("my_s1")

    -- 本地别名
    skynet.name(".my_alias", handle)
    -- 全局别名
    skynet.name("my_alias", handle)

    -- handle = skynet.localname(".my_alias")
    -- skynet.error("localname .my_alias handle", skynet.address(handle))

    -- handle = skynet.localname("my_alias") -- 尝试获取全局别名
    -- skynet.error("localname my_alias handle", skynet.address(handle)) -- 注意全局别名开头无"."

    -- handle = harbor.queryname(".my_alias")
    -- skynet.error("queryname my_alias handle", skynet.address(handle))


    -- handle = harbor.queryname("my_alias")
    -- skynet.error("queryname my_alias handle", skynet.address(handle))

end)