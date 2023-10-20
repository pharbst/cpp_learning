/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:34:38 by pharbst           #+#    #+#             */
/*   Updated: 2023/10/20 16:06:53 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    Bureaucrat  Hans("Hans", 50);
    Bureaucrat  Berta("Berta", 10);
    Form        A28("A28", 1, 1);
    Form        B28("B28", 20, 9);
    Form        C28("C28", 60, 80);

    Hans.signForm(C28);
    Hans.signForm(B28);
    Berta.signForm(B28);
    Berta.signForm(A28);
}
