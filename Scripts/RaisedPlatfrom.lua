local MyComponent = 
{
    Properties = {},
    time = 0,  -- Track time for the sine wave
}

function MyComponent:OnActivate()
    -- Register for the tick bus to receive OnTick calls every frame
    self.tickBusHandler = TickBus.Connect(self)
      -- Enable physics debug rendering
    PhysXDebug.RequestBus.Broadcast.SetVisualization("Colliders", true)
    PhysXDebug.RequestBus.Broadcast.SetVisualization("CollisionLayers", true)
end

function MyComponent:OnTick(deltaTime, timePoint)
    self.time = self.time + deltaTime

    -- Calculate the new Y position using sine wave
    local newY = math.sin(self.time * 1.5) * 5

    -- Get the current position of the entity
    local currentPos = TransformBus.Event.GetWorldTranslation(self.entityId)

    -- Set the new position of the entity
    local newPos = Vector3(currentPos.x, newY, currentPos.z)
    TransformBus.Event.SetWorldTranslation(self.entityId, newPos)

    -- Update the physics transform
    PhysXColliderComponentRequestsBus.Event.SetWorldTransform(self.entityId, TransformBus.Event.GetWorldTM(self.entityId))
end

function MyComponent:OnDeactivate()
    -- Unregister from the tick bus
    if self.tickBusHandler then
        self.tickBusHandler:Disconnect()
        self.tickBusHandler = nil
    end
end

return MyComponent