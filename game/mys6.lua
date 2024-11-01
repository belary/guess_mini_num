local skynet = require("skynet")

function task(timeout)
    skynet.error("skynet.starttime():", skynet.starttime()) -- skynet主进程的开始时间
    skynet.error("fork coroutine:", coroutine.running())
    skynet.sleep(timeout)
    skynet.error("skynet.now():", skynet.now())
    skynet.error("延迟任务执行完成, skynet.time():", skynet.time())
end


skynet.start(function()
    skynet.error("in main -skynet.starttime():", skynet.starttime()) -- skynet主进程的开始时间
    skynet.error("准备执行延迟任务")
    skynet.error("main coroutine:", coroutine.running())
    skynet.fork(task, 500) -- 开启协程执行
    skynet.error("延迟任务后面的执行逻辑")
end)