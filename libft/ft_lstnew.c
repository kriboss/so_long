/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:32:01 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/31 23:41:49 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_li	*ft_lstnew(void *content)
{
	t_li	*new;

	new = (t_li *)malloc(sizeof(t_li));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
#include <stdio.h>

int main() {
    // Test Case 1: Integer content
    int value = 42;
    t_list *int_node = ft_lstnew(&value);
    if (int_node) {
        printf("Integer Node Content: %d\n", *(int *)int_node->content);
        free(int_node);
    } else {
        printf("Failed to create integer node.\n");
    }

    // Test Case 2: String content
    char *str = "Hello, linked list!";
    t_list *string_node = ft_lstnew(str);
    if (string_node) {
        printf("String Node Content: %s\n", (char *)string_node->content);
        free(string_node);
    } else {
        printf("Failed to create string node.\n");
    }

    // Test Case 3: NULL content
    t_list *null_node = ft_lstnew(NULL);
    if (null_node) {
        if (!null_node->content)
            printf("NULL Node Content: (null)\n");
        free(null_node);
    } else {
        printf("Failed to create null node.\n");
    }

    return 0;
}*/
