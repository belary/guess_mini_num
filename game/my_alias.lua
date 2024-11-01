local skynet = require("skynet")
require("skynet.manager")
local harbor = require("skynet.harbor")

skynet.start(function()
    -- local handle = skynet.newservice("my_s1")

    -- 本地别名
    -- skynet.name(".my_alias", handle)
    -- 全局别名
    -- skynet.name("my_alias", handle)

    handle = skynet.localname(".my_alias")
    skynet.error("localname .my_alias handle", skynet.address(handle))

    handle = skynet.localname("my_alias") -- 尝试获取全局别名
    skynet.error("localname my_alias handle", skynet.address(handle)) -- 注意全局别名开头无"."

    handle = harbor.queryname(".my_alias") -- 通过harbor查询本地别名，不存在的返回nil
    skynet.error("queryname my_alias handle", skynet.address(handle))


    handle = harbor.queryname("my_alias") -- 通过harbor查询全局别名，不存在会阻塞
    skynet.error("queryname my_alias handle", skynet.address(handle))

end)