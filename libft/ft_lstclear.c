/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:56:15 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/31 23:41:20 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_li **lst, void (*del)(void *))
{
	t_li	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
/*
#include <stdio.h>
#include <stdlib.h>

void del(void *content) {
    // Free the dynamically allocated content (assuming it's a string)
    free(content);
}

int main() {
	t_list *head = ft_lstnew(ft_strdup("Primo"));
	head->next = ft_lstnew(ft_strdup("Secondo"));
	head->next->next = ft_lstnew(ft_strdup("Terzo"));

	printf("before:\n");
	t_list *current = head;
	while (current) {
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	printf("\nafter:\n");
	ft_lstclear(&head, del);
	current = head;
	while (current) {
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstdelone(head->next, del);
	ft_lstdelone(head, del);
	return 0;
}*/
