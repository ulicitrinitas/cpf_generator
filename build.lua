local src_dir = "src/"
local libs = "-lpthread -lsodium -lm"
local cc="clang++"
local cflags = "-Wall -Werror -Wextra -pedantic -g -fsanitize=address -O2 -o cpf"

os.execute(
    "/usr/bin/" .. cc .. " " .. 
    libs .. " " .. 
    cflags .. " " .. " " .. 
    src_dir .. "*.cpp"
)

