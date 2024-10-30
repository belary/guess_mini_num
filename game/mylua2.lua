local mytable = {}
local mymeta_table = {
    __index = function(table, key)
        return "key '" .. key .. "' not found."
    end
}

setmetatable(mytable, mymeta_table)

print(mytable.no_exists_key)