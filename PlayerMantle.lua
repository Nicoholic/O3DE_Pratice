local Mantle = {}

local playerEntityId = self.entityId

function Mantle:OnActivate()
    -- Connect to the tick bus to update the mantling logic
    self.tickBusHandler = TickBus.Connect(self)
    
    -- Connect to the input event bus for handling input events
    self.inputHandler = InputEventNotificationBus.Connect(self, InputEventNotificationId("MantleKey"))  -- Replace "MantleKey" with the actual input name you set up
end

function Mantle:OnDeactivate()
    -- Disconnect from the tick bus when the script is deactivated
    if self.tickBusHandler then
        self.tickBusHandler:Disconnect()
        self.tickBusHandler = nil
    end

    -- Disconnect from the input event bus when the script is deactivated
    if self.inputHandler then
        self.inputHandler:Disconnect()
        self.inputHandler = nil
    end
end

function Mantle:OnTick(deltaTime, timePoint)
    -- Your tick logic can remain here if needed for other checks
end

function Mantle:OnPressed(floatValue)
    -- Called when the mapped input key is pressed
    self:TryMantle()
end

function Mantle:TryMantle()
    -- Assuming 'playerEntityId' is the entity id of the player
    local playerEntityId = self.entityId

    -- Get the player position and direction
    local playerPosition = TransformBus.Event.GetWorldTranslation(playerEntityId)
    local playerForward = TransformBus.Event.GetWorldRotation(playerEntityId):GetForward()

    -- Perform a raycast forward to detect a mantling opportunity
    local rayCastRequest = RayCastRequest()
    rayCastRequest.Start = playerPosition
    rayCastRequest.Direction = playerForward
    rayCastRequest.Distance = 1.5 -- Adjust this value for range
    rayCastRequest.MaxHits = 1

    local hitResult = PhysicsSystemRequestBus.Broadcast.RayCast(rayCastRequest)

    if hitResult and #hitResult > 0 then
        -- Check if the hit is at a height suitable for mantling
        local hit = hitResult[1]
        local mantleHeight = 1.0 -- Adjust this value for mantle height
        if hit.Position.z < playerPosition.z + mantleHeight then
            -- Perform the mantle movement
            self:PerformMantle(hit.Position)
        end
    end
end

function Mantle:PerformMantle(hitPosition)
    local playerEntityId = self.entityId

    -- Calculate the target position for mantling
    local targetPosition = hitPosition + Vector3(0, 0, 1.0) -- Adjust z for mantle height

    -- Smoothly move the player to the target position
    local currentPosition = TransformBus.Event.GetWorldTranslation(playerEntityId)
    local newPosition = currentPosition:Lerp(targetPosition, 0.1) -- Adjust 0.1 for smoothness
    TransformBus.Event.SetWorldTranslation(playerEntityId, newPosition)

    -- Uncomment and add animation trigger here when ready
    -- AnimationRequestBus.Event.TriggerAnimation(playerEntityId, "Mantle")
end

return Mantle