local redis = require("redis")
client = redis.connect('172.31.27.125', 6379)

local zsetname = "zset-test-k1"
local players = client:zrangebyscore(zsetname, 0, 500, 'WITHSCORES')

-- 遍历 players 并解析每个 player 的信息
for i, player in ipairs(players) do
    if type(player) == "table" and #player == 2 then
        local name, score = player[1], player[2]
        print("Player: " .. name .. ", Score: " .. score)
    else
        print("Unexpected structure for player:", player)
    end
end
-- 打印原始数据，检查每个元素的结构
print("Raw players data:")
for i, player in ipairs(players) do
   print(i, player)  -- 查看每个元素的原始数据结构
end

-- 遍历 players 并解析每个 player 的信息
for i = 1, #players, 1 do
    local tablePlayer = players[i]
        -- 假设 player 是一个包含玩家名字和其他信息的表
        print("table length:"..#players[i].."content:"..tablePlayer[1].. ","..tonumber(tablePlayer[2])) 
--        for k, v in pairs(tablePlayer) do
--            print("  " .. k .. ": " .. tostring(v))
--        end
end

-- 关闭连接
client:quit()
