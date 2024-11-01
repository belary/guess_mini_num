local skynet = require("skynet")

local params = {...}
if (#params == 0) then 
    table.insert(params, "onlyservice")
end

skynet.start(function()
    local o1,o2
    skynet.error("开始测试查询服务方法queryservice")
    skynet.error("启动参数是:".. table.concat(params, ","))

    if (#params == 2 and params[1] == "true") then
        -- 查询全局节点的服务唯一句柄
        o1 = skynet.queryservice(true, params[2])
        skynet.error("全局节点的唯一句柄是:"..o1)
    else
        -- 查询当前节点的服务唯一句柄
        skynet.error("查询当前节点的服务名称是:".. params[1])
        o2 = skynet.queryservice(params[1])
        skynet.error("当前节点的唯一句柄是:"..o2)
    end

end)