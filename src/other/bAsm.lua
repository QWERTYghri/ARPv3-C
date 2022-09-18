#!/bin/lua

--[[
-- Basic assembler just to test out things and prototype.
--]]

local inst_t = 
        {
                "NOP",

                "LDA",
                "LDA",



local function mTree ( str )
        local retTab    = {}
        local curTab    = {}
        local cnt       = 0

        local 

        for i, _ in string.gmatch ( "%S+" ) do
                if ( i == "org" ) then
                        
                end


                if ( cnt == 0 ) then
                        table.insert ( curTab, inst_t[i] )
                else if ( cnt == 1 ) then
                        table.insert ( curTab, tonumber ( i ) )
                        cur = 0
                        table.insert ( retTab, curTab )
                        curTab = {}
                end
        end

        return retTab

end

local function gen ( tab )
        for i in pairs ( tab ) do
                for v in pairs ( i ) do
                        
                end
        end
end

local function asm ( str )

end

local function main ()
        for i in pairs ( arg ) do
                         ( str )
                end
        end
end
