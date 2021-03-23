/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzombie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:33:26 by yzombie           #+#    #+#             */
/*   Updated: 2021/02/09 13:33:27 by yzombie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STRUCT_H
# define PARSER_STRUCT_H

typedef struct		s_parse
{
	char	player;
	int		map_index;
	int		save;
	int		r[2];
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		f;
	int		c;
}					t_parse;

#endif
