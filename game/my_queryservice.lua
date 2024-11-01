local skynet = require("skynet")

local params = {...}
if (#params == 0) then 
    table.insert(params, 'onlyservice')
end

skynet.start(function()
    local onlysvc
    skynet.error("开始测试查询服务方法queryservice")
    skynet.error("启动参数是:".. table.concat(params, ","))

    if (#params == 2 and params[1] == true) then
        onlysvc = skynet.queryserivce(true, params[2])
    else
        onlysvc = skynet.queryserivce(params[1])
    end

    skynet.error("结束测试查询服务方法:", skynet.address(onlysvc))
end)