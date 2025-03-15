!!cnh {"suffix":"json"}
[
    {
        "comment-header": {
            "File": "{{ cnh_file }}",
            "Author": "{{ cnh_name }}",
{% if exists("cnh_has_copyright") %}
            "Copyright": "{{ cnh_has_copyright }}",
{% endif %}
{% if exists("cnh_description") %}
            "Description": "{{ cnh_description }}",
{% endif %}
            "Created": "{{ cnh_date }}"
        },
        "salutation": "Hello world"
    }
]
