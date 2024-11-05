local redis = require("redis")
client = redis.connect('172.31.27.125', 6379)
zsetname = "zset-test-k1"
local players = client:zrange(zsetname, 0, 1000)
print("players number:",#players)
if #players < 2 then
    print("not enough players")
else 
    local p1 = players[1]
    local p2 = players[2]
    local p3 = players[3]
    local p4 = players[4]
    print(p1,p2,p3,p4)
    
   
end