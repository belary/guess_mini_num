local skynet = require "skynet.manager"
local redis = require "skynet.db.redis"

skynet.start(function ()
	local rds = redis.connect({
		host	= "172.31.27.125",
		port	= 6379,
		db		= 0,
		-- auth	= "123456",
	})
	skynet.dispatch("lua", function (session, address, cmd, ...)
		skynet.retpack( rds[cmd:lower()](rds, ...) )
	end)
end)
