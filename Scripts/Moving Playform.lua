-- Assuming 'box' is the object you want to move
local speed = 2          -- Speed at which the object moves
local height = 5         -- Maximum vertical movement
local time = 0           -- Track time for the sine wave

function Update(deltaTime)
    time = time + deltaTime    -- Update time based on deltaTime
    
    -- Calculate new Y position using sine wave
    local newY = math.sin(time * speed) * height

    -- Get the current position of the object
    local currentPos = self:GetPosition()

    -- Set the new position for the box (moving only in the Y direction)
    self:SetPosition(currentPos.x, newY, currentPos.z)
    
    return self
    
end