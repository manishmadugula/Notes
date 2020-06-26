# Techniques of data modelling.

Say we are trying to store posts and tags.

## Embedding
- Directly add data to the document. Say you have a collection apis and inside this collection you have a document whose structure is 
  ```json
  {
      tags:[
          {
              name : "randomname",
              url : "tag/randomname"
          },
          {
              name : "randomname",
              url : "tag/randomname"
          },
          {
              name : "randomname",
              url : "tag/randomname"
          }

      ]
  }
  ```

- It is fast since a single document read is enought to get all the data and works as long as all your data can fit into 1 MB.
- You can't query any data inside this data model. You need to get the entire data and process it.

## Root Collection
- we give each entity it's own document.

We have a posts collection and we have a tags collection. post collection can have many tags and each tag can be used in multiple posts. So we reference the tag in the post document using it's id.

## Sub Collection 
- using tag as a subcollection of posts, we don't need to use reference to tag as it's existence is valid only inside the post.
- But we can't make queries across the subcollection level, i.e get all tags across all the posts.

## Bucketing