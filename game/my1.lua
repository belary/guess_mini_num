local lfs = require "lfs"

local function get_absolute_path(rel_path) 
    local cur_dir = lfs.currentdir()
    return cur_dir .. "/" .. rel_path
end


local function get_abs_path(rel_path)
    local cur_dir = io.popen("cd"):read("*1")
    if not cur_dir then
        error("无法获取当前工作目录")
    end
    return cur_dir .. "/" .. rel_path
end

local current_file_path = debug.getinfo(1, "S").source
if current_file_path:sub(1,1) == "@" then
    local rel_path = current_file_path:sub(2)
    -- local abs_path = get_abs_path(rel_path)
    local abs_path = get_absolute_path(rel_path)
    print(abs_path)
else
    print("no file")
end


-- local sep = package.config:sub(1,1)
-- print("路径分隔符是:"..sep)