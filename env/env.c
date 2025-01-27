#include "../minishell.h"

int init_sec_env(t_mini *mini, char **env_ar)
{
	t_env *env;
	t_env *new1;
	int i;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (1);
	env->value = ft_strdup(env_ar[0]);
	env->next = NULL;
	mini->sec_env = env;
	i = 1;
	while (env_ar && env_ar[0] && env_ar[i])
	{
		new1 = (t_env *)malloc(sizeof(t_env));
		if (!new1)
			return (1);
		new1->value = ft_strdup(env_ar[i]);
		new1->next = NULL;
		env->next = new1;
		env = new1;
		i++;
	}
	// while (mini->env)
	// 	printf("%s\n", mini->env->value), mini->env = mini->env->next;
	return (0);
}

int count_str_env(char **env)
{
    int i;

    i = 0;
    while (env[i])
        i++;
    return (i);
}

int env_validation(char *env)
{
    int i;

    i = 0;
    if (ft_isdigit(env[i]) == 1)
        return (0);
    while (env[i] && env[i] != '=')
    {
        if (ft_isalnum(env[i] == 0))
            return (-1);
        i++;
    }
    if (env[i] != '=')
        return (2);
    return (1);
}

char *get_name(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i] && src[i] != '=' && ft_strlen(src) < 4096)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *get_env_val(char *param, t_env *env)
{
    char env_name[4096];
    char *env_val;

    env_val = ft_strdup("");
    while (env && env_val)
    {
        get_name(env_name, env->value);
        if (ft_strcmp(param, env_name) == 0)
        {
            delete_memmory(env_val);
            env_val = env_val1(env->value);
            return (env_val);
        }
        env = env->next;
    }
    return (env_val);
}