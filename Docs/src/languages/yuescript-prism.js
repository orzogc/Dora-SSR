(function (Prism) {
	Prism.languages.yuescript = {
		comment: /--.*/,
		string: [
			{
				pattern: /'[^']*'|\[(=*)\[[\s\S]*?\]\1\]/,
				greedy: true
			},
			{
				pattern: /"[^"]*"/,
				greedy: true,
				inside: {
					interpolation: {
						pattern: /#\{[^{}]*\}/,
						inside: {
							yuescript: {
								pattern: /(^#\{)[\s\S]+(?=\})/,
								lookbehind: true,
								inside: null // see beow
							},
							'interpolation-punctuation': {
								pattern: /#\{|\}/,
								alias: 'punctuation'
							}
						}
					}
				}
			}
		],
		'class-name': [
			{
				pattern: /(\b(?:class|extends)[ \t]+)\w+/,
				lookbehind: true
			}, // class-like names start with a capital letter
			/\b[A-Z]\w*/
		],
		keyword:
			/\b(?:and|break|do|else|elseif|false|for|goto|if|in|local|nil|not|or|repeat|return|then|true|until|while|as|class|continue|export|extends|from|global|import|macro|switch|try|unless|using|when|with)\b/,
		variable: /@@?\w*/,
		property: {
			pattern: /\b(?!\d)\w+(?=:)|(:)(?!\d)\w+/,
			lookbehind: true
		},
		function: {
			pattern:
				/\b(?:_G|_ENV|_VERSION|assert|collectgarbage|coroutine\.(?:create|resume|running|status|wrap|yield)|debug\.(?:debug|getfenv|gethook|getinfo|getlocal|getmetatable|getregistry|getupvalue|setfenv|sethook|setlocal|setmetatable|setupvalue|traceback)|dofile|error|getfenv|getmetatable|io\.(?:close|flush|input|lines|open|output|popen|read|stderr|stdin|stdout|tmpfile|type|write)|ipairs|load|loadfile|loadstring|math\.(?:abs|acos|asin|atan|atan2|ceil|cos|cosh|deg|exp|floor|fmod|frexp|ldexp|log|log10|max|min|modf|pi|pow|rad|random|randomseed|sin|sinh|sqrt|tan|tanh)|module|next|os\.(?:clock|date|difftime|execute|exit|getenv|remove|rename|setlocale|time|tmpname)|package\.(?:cpath|loaded|loadlib|path|preload|seeall)|pairs|pcall|print|rawequal|rawget|rawset|require|select|setfenv|setmetatable|string\.(?:byte|char|dump|find|format|gmatch|gsub|len|lower|match|rep|reverse|sub|upper)|table\.(?:concat|insert|maxn|remove|sort)|tonumber|tostring|type|unpack|xpcall)\b/,
			inside: {
				punctuation: /\./
			}
		},
		boolean: /\b(?:false|true)\b/,
		number:
			/(?:\B\.\d+|\b\d+\.\d+|\b\d+(?=[eE]))(?:[eE][-+]?\d+)?\b|\b(?:0x[a-fA-F\d]+|\d+)(?:U?LL)?\b/,
		operator:
			/\.{3}|[-=]>|~=|(?:[-+*/%<>!=]|\.\.)=?|[:#^]|\b(?:and|or)\b=?|\b(?:not)\b/,
		punctuation: /[.,()[\]{}\\]/
	}
	Prism.languages.yuescript.string[1].inside.interpolation.inside.yuescript.inside = Prism.languages.yuescript
	Prism.languages.yue = Prism.languages.yuescript
})(Prism);
