#define SPECIFIERS "cspdiuxX"
#define FLAGS "0-+ #"

//pad can be /0 (right-justify), '-' (left-justify), or '0' (pad with zero)
//sign can be ' ' (no plus sign) or '+' (yes plus sign)
//prefix can be /0 (no prefix) or '#' (yes prefix)
//default precision is represented as -1
typedef struct	s_token
{
	char		spec;
	char		pad;
	char		sign;
	char		prefix;
	int			width;
	int			precision;
}				t_token
