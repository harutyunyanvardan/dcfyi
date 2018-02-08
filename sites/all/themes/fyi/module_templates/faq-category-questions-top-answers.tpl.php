<?php

/**
 * @file
 * Template file for the answers section of the FAQ page if set to show
 * categorized questions at the top of the page.
 */

/**
 * Available variables:
 *
 * $display_answers
 *   Whether or not there should be any output.
 * $display_header
 *   Boolean value controlling whether a header should be displayed.
 * $header_title
 *   The category title.
 * $category_name
 *   The name of the category.
 * $answer_category_name
 *   Whether the category name should be displayed with the answers.
 * $group_questions_top
 *   Whether the questions and answers should be grouped together.
 * $category_depth
 *   The term or category depth.
 * $description
 *   The current page's description.
 * $term_image
 *   The HTML for the category image. This is empty if the taxonomy image module
 *   is not enabled or there is no image associated with the term.
 * $display_faq_count
 *   Boolean value controlling whether or not the number of faqs in a category
 *   should be displayed.
 * $question_count
 *   The number of questions in category.
 * $nodes
 *   An array of nodes to be displayed.
 *   Each node stored in the $nodes array has the following information:
 *     $node['question'] is the question text.
 *     $node['body'] is the answer text.
 *     $node['links'] represents the node links, e.g. "Read more".
 * $use_teaser
 *   Whether $node['body'] contains the full body or just the teaser text.
 * $question_label
 *   The question label, intended to be pre-pended to the question text.
 * $answer_label
 *   The answer label, intended to be pre-pended to the answer text.
 * $container_class
 *   The class attribute of the element containing the sub-categories, either
 *   'faq-qa' or 'faq-qa-hide'. This is used by javascript to open/hide
 *   a category's faqs.
 * $subcat_body_list
 *   The sub-categories faqs, recursively themed (by this template).
 */
?>

<?php $key = 0; ?>
<?php if (count($nodes)): ?>
  <?php foreach ($nodes as $i => $node): ?>

    <h4><?php print ($key +1) . ". " . $node['question']; ?></h4> <!-- Close div: faq-question -->

    <div class="faq-answer">
      <?php print $node['body']; ?>
    </div> <!-- Close div: faq-answer -->
    <?php $key++; ?>

  <?php endforeach; ?>
<?php endif; ?>
