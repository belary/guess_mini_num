local skynet = require("skynet")
local param = {...}
if (#param == 0) then
    table.insert(param, "onlyservice")
end

skynet.start(function()
    local us
    skynet.error("test unique service")
    skynet.error("param:".. table.concat(param, ", "))

    -- 若有两个参数，第一个为true，则启动第二个参数的模块
    if (#param == 2 and param[1] == "true") then 
        us = skynet.uniqueservice(true, param[2])
    else
        -- 直接指向第一个参数
        us = skynet.uniqueservice(param[1])
    end

    skynet.error("uniqueservice handler:", skynet.address(us))
end)