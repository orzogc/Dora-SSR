local ActionDef = require("Action").Def
local Ease = require("Ease")

-- Creates a definition for an action that animates the height of a Node.
-- @param duration (number) The duration of the animation in seconds.
-- @param from (number) The starting height value of the Node.
-- @param to (number) The ending height value of the Node.
-- @param easing (EaseFunc) [optional] The easing function to use for the animation. Defaults to Ease.Linear if not specified.
-- @return (ActionDef) An ActionDef object that can be used to run the animation on a Node.
local height: function(
		duration: number,
		from: number,
		to: number,
		easing?: Ease.EaseFunc --[[Ease.Linear]]
	): ActionDef

return height
