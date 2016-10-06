local time = os.time()
math.randomseed(time)

local f = io.open('test.hex', 'wb')

function tohex(str)
	for i=1,#str,2 do
		f:write(string.char(tonumber('0x'..string.char(string.byte(str, i))..string.char(string.byte(str, i + 1)))))
	end
end

local header_name = "ea83f361726e6f"

f:write(string.char(0))
tohex(header_name)

for i=1,131 do
	f:write(string.char(0))
end

local header_description = "4661726e6f61726e6f61726e6f"

tohex(header_description)

for i=1,2040 do
	f:write(string.char(0))
end

for i=1,70 do
	f:write(string.char(math.random(1, 16)))
end

f:close()
