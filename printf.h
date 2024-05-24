#define SPECIFIERS "cspdiuxX"

//pad can be /0 (right-justify), '-' (left-justify), or '0' (pad with zero)
//sign can be ' ' (no plus sign) or '+' (yes plus sign)
typedef struct	s_token
{
	char		spec;
	char		pad;
	char		sign;
	int			width;
	int			precision;
}				t_token
