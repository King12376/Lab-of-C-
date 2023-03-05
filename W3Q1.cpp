explainThis(char *s, char *t)
{
	for (; *t && *s ; s += *s == *t++) ;
	return !*s ;
}
