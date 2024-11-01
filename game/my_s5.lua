local skynet = require("skynet")

skynet.start(function()
    skynet.error("begin to sleep")
    skynet.sleep(500)
    skynet.error("end to sleep")
end)