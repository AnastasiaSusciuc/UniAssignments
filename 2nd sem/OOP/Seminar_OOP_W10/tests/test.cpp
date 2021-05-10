//
// Created by susci on 4/27/2021.
//

#include "test.h"
#include "../Domain/BasicComponent.h"
#include "../Domain/BorderedComponent.h"
#include "../Domain/HorizontalLayout.h"
#include "../Domain/VerticalLayout.h"
#include "../Domain/Label.h"
#include <cassert>

void Tests::run_all_tests() {

    BasicComponent bc(2, 3, '*');

    assert(IComponent::print(&bc) == "***\n***\n");

    BorderedComponent bbc(&bc, 3, '$');

//    std::cout << IComponent::print(&bbc) << '\n';

    BorderedComponent bbbc(&bbc, 2, '~');

//    std::cout << IComponent::print(&bbbc) << '\n';

    HorizontalLayout hl;
    hl.addComponent(&bc);
    hl.addComponent(&bbbc);
    hl.addComponent(&bbc);

//    std::cout << IComponent::print(&hl) << '\n';

    HorizontalLayout hll;
    hll.addComponent(&bbbc);
    hll.addComponent(&bc);
    hll.addComponent(&bbc);

//    std::cout << IComponent::print(&hll) << '\n';

    VerticalLayout vl;
    BorderedComponent bvl(&vl, 2, '@');

    vl.addComponent(&hl);
    vl.addComponent(&hll);
//    vl.addComponent(&hl);

//    std::cout << IComponent::print(&vl) << '\n';


//    std::cout << vl.get_width() << " " << vl.get_height() << '\n';
//
//    std::cout << IComponent::print(&bvl) << '\n';

    Label a("Salut!");
    Label b("Sunt eu!");
    Label c("Haiducul!");

    BorderedComponent bb(&b, 3, '*');

    HorizontalLayout hlll;
    hlll.addComponent(&a);
    hlll.addComponent(&bb);
    hlll.addComponent(&c);


    vl.addComponent(&hlll);


    std::cout << IComponent::print(&bvl) ;

    std::cout << "Finished tests!\n";
}
