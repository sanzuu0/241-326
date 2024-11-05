document.addEventListener('DOMContentLoaded', () => {
    const links = document.querySelectorAll('.site-header nav ul li a');

    links.forEach(link => {
        link.addEventListener('click', (e) => {
            e.preventDefault();
            const targetId = link.getAttribute('href');
            const element = document.getElementById(targetId);
            element.scrollIntoView({ behavior: 'smooth' });
        });
    });

    // Скрипт для переключения между секциями
    const sections = document.querySelectorAll('section');
    window.addEventListener('scroll', () => {
        let currentSection = null;

        sections.forEach((section, index) => {
            const sectionTop = section.offsetTop;
            const sectionBottom = sectionTop + section.offsetHeight;

            if (window.pageYOffset >= sectionTop && window.pageYOffset < sectionBottom) {
                currentSection = section;
            }
        });

        if (currentSection) {
            const links = document.querySelectorAll('.site-header nav ul li a');
            links.forEach(link => {
                link.classList.remove('active');
                if (link.href === '#' + currentSection.id) {
                    link.classList.add('active');
                }
            });
        }
    });
});
