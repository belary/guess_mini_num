local skynet = require("skynet")
local param = {...} -- 从命令行接收参数
if (#param == 0) then
    table.insert(param, "onlyservice")
    table.insert(param, "onlyservice")
end

skynet.start(function()
    local us1, us2
    skynet.error("test unique service")
    skynet.error("param:".. table.concat(param, ", "))

    skynet.error("查询当前节点 唯一句柄")
    us1 = skynet.queryservice(param[1])
    skynet.error("查询全局节点 唯一句柄")
    us2 = skynet.queryservice(true, param[2])
    

    skynet.error("当前节点 唯一句柄:", us1)
    skynet.error("全局节点 唯一句柄:", us2)

end)